
// Thu vien Blynk
#define BLYNK_TEMPLATE_ID "TMPL688zNve9t"
#define BLYNK_TEMPLATE_NAME "GIAM SAT BUONG XONG HOI"
#define BLYNK_AUTH_TOKEN "JXio69PDDF9EGeYIdArKpMD6Yuy0LY3-"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Thong tin WiFi
char ssid[] = "Project 01";       // Ten WiFi
char pass[] = "vnu.edu.vn";   // Mat khau WiFi

// Auth Token tu Blynk
char auth[] = BLYNK_AUTH_TOKEN;

// Chan LED noi voi ESP32
#define LED_PIN1 12
#define LED_PIN2  5

// Chan PIR
#define PIR_SENSOR_PIN 21

// Chân GPIO 0 của ESP32
#define DHTPIN 0 
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Chân đo nhiệt độ của lò xông hơi
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Chân đo khí Co
#define MQ7_PIN 34
#define RLOAD 10000 // Điện trở tải (10kΩ)
#define VCC 5.0     // Điện áp cấp cho cảm biến

// Bien toan cuc 
int pirState = 0;
float humidity = 0;    
float temperature = 0; 
float temperatureC = 0;
float CO_sensor_value = 0;
float R0 = 10.0; // Thay giá trị này sau khi hiệu chuẩn. Giá trị R0 cần hiệu chỉnh, ban đầu ước lượng

// Thiet lap ban dau
void setup() {
  // Khoi dong Serial de debug
  Serial.begin(115200);
  dht.begin();
  sensors.begin();

  // Thiet lap LED_PIN la Output
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);

  // Cài đặt chân PIR_SENSOR_PIN là INPUT
  pinMode(PIR_SENSOR_PIN, INPUT);


  // Ket noi Blynk
  Blynk.begin(auth, ssid, pass);

  // Thong bao trang thai ban dau
  Serial.println("ESP32 da khoi dong va ket noi Blynk.");
}

// // Lenh Blynk Virtual Pin V4 de dieu khien LED
// BLYNK_WRITE(V4){
//   int ledState = param.asInt(); // Doc gia tri tu app (0: tat, 1: bat)
//   digitalWrite(LED_PIN1, ledState);


// }

void updatepir(){
  pirState = digitalRead(PIR_SENSOR_PIN);
}

void updatedht(){
  humidity = dht.readHumidity();    // Đọc độ ẩm (%)
  temperature = dht.readTemperature(); // Đọc nhiệt độ (°C)
}

void updateds(){
  sensors.requestTemperatures();
  temperatureC = sensors.getTempCByIndex(0);
}

void updateCO(){
 // Đọc giá trị analog từ cảm biến MQ-7
  int analogValue = analogRead(MQ7_PIN);

  // Tính điện áp đầu ra
  float Vout = analogValue * (VCC / 4095.0);

  // Tính Rs (điện trở của cảm biến)
  float Rs = RLOAD * (VCC - Vout) / Vout;

  // Tính tỷ lệ Rs/R0
  float ratio = Rs / R0;

  // Tính nồng độ CO (ppm) dựa trên đường cong đặc trưng
  // log(ppm) = m * log(ratio) + b (giá trị m và b lấy từ datasheet)
  CO_sensor_value = 10 * pow(10, (-1.179 * log10(ratio) + 1.182)); // Hệ số cho MQ-7 từ datasheet
}

// Vong lap chinh
void loop() {
  Blynk.run();
  updatepir();
  updatedht();
  updateds();
  updateCO();
  digitalWrite(LED_PIN1, pirState);
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, temperatureC);
  Blynk.virtualWrite(V3, CO_sensor_value );
  Blynk.virtualWrite(V4, pirState);

  if(temperature > 95 || CO_sensor_value > 8){
    Blynk.virtualWrite(V5, 1);
    digitalWrite(LED_PIN2, 1);
  }
  else{
    Blynk.virtualWrite(V5, 0);
    digitalWrite(LED_PIN2, 0);
  }
}