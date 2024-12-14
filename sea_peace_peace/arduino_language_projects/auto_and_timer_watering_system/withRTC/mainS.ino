#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>
#include <DHT.h>

// Kích thước màn hình OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Chân kết nối OLED (SPI)
#define OLED_MOSI   11 // D1 trên OLED
#define OLED_CLK    13 // D0 trên OLED
#define OLED_DC     8  // DC trên OLED
#define OLED_CS     10 // CS trên OLED
#define OLED_RESET  9  // RES trên OLED

// Chân kết nối DHT22
#define DHTPIN 2 // DATA của DHT22 nối vào D2
#define DHTTYPE DHT22 // Loại cảm biến DHT22

// Chân kết nối LM393
#define SOIL_AO A0 // Đầu ra Analog từ LM393

// Chân nút nhấn
#define BUTTON1_PIN 3
#define BUTTON2_PIN 4
#define BUTTON3_PIN 5 // Thêm nút mới sử dụng chân D5

// Chân relay
#define RELAY_PIN 6

// Khởi tạo màn hình OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);
// Khởi tạo cảm biến DHT22
DHT dht(DHTPIN, DHTTYPE);
// Khởi tạo module RTC DS3231
RTC_DS3231 rtc;

// Biến toàn cục
int button1Value = 1;
int wateringHour = 7; // Giờ tưới mặc định
int wateringMinute = 0; // Phút tưới mặc định
bool isWatering = false; // Trạng thái tưới
unsigned long wateringStartTime = 0; // Lưu thời gian bắt đầu tưới
int oneTime = 1;

void setup() {
  // Cấu hình nút nhấn
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP); // Cấu hình nút mới
  pinMode(RELAY_PIN, OUTPUT);

  // Khởi tạo OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    while (true); // Nếu không tìm thấy OLED, dừng lại
  }

  // Khởi tạo cảm biến DHT22
  dht.begin();

  // Khởi tạo RTC
  if (!rtc.begin()) {
    while (true); // Nếu không tìm thấy RTC, dừng lại
  }

  // Màn hình khởi động
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 20);
  display.println(F("DO AN 1"));
  display.setCursor(5, 35);
  display.println(F("Nguyen Khanh Ly"));
  display.setCursor(5, 50);
  display.println(F("22070177"));
  display.display();
  delay(5000);
}

void loop() {
  // Đọc và hiển thị dữ liệu
  DateTime now = rtc.now();
  float temperature = readTemperature();
  float humidity = readHumidity();
  float soilMoisture = readSoilMoisture();

  // Kiểm tra trạng thái nút nhấn
  checkButtons();

  // Xử lý logic hệ thống
  if(button1Value == 1){
    autoMode();
  }
  if(button1Value == 2){
    scheduleWatering(now);
  }

  // Hiển thị dữ liệu lên màn hình OLED
  displayData(now, temperature, humidity, soilMoisture);

  delay(100); // Đợi 100ms trước khi cập nhật
}

// Hàm xử lý tưới tự động
void autoMode(){
  oneTime = 1;
  int a_temperature = int(readTemperature());
  int a_humidity = int(readHumidity());
  int a_soilMoisture = int(readSoilMoisture());

  if (a_temperature > 35 || a_humidity < 20 || a_soilMoisture < 30){
    digitalWrite(RELAY_PIN, 0);
  }
  else{
    digitalWrite(RELAY_PIN, 1);
  }
}

// Hàm xử lý tưới theo hẹn giờ
void scheduleWatering(DateTime now) {
  if(oneTime == 1){
    digitalWrite(RELAY_PIN, 1);
    oneTime++;
  }
  if (!isWatering && now.hour() == wateringHour && now.minute() == wateringMinute) {
    isWatering = true;
    wateringStartTime = millis();
    digitalWrite(RELAY_PIN, LOW); // Bật tưới
  }

  // Tắt tưới sau 10 phút
  if (isWatering && millis() - wateringStartTime >= 10 * 60 * 1000) {
    isWatering = false;
    digitalWrite(RELAY_PIN, HIGH); // Tắt tưới
  }
}

// Hàm đọc nhiệt độ từ DHT22
float readTemperature() {
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    return -999; // Giá trị lỗi
  }
  return temp;
}

// Hàm đọc độ ẩm từ DHT22
float readHumidity() {
  float hum = dht.readHumidity();
  if (isnan(hum)) {
    return -999; // Giá trị lỗi
  }
  return hum;
}

// Hàm đọc độ ẩm đất từ LM393
float readSoilMoisture() {
  int soilValue = analogRead(SOIL_AO); // Đọc giá trị analog từ cảm biến
  float moisture = map(soilValue, 180, 850, 100, 0); // Chuyển đổi từ giá trị thực tế thành phần trăm
  if (moisture < 0) moisture = 0;
  if (moisture > 100) moisture = 100;
  return moisture;
}

// Hàm kiểm tra trạng thái nút nhấn
void checkButtons() {
  static bool lastButton1State = HIGH;
  static bool lastButton2State = HIGH;
  static bool lastButton3State = HIGH; // Trạng thái cho nút mới

  bool button1State = digitalRead(BUTTON1_PIN);
  bool button2State = digitalRead(BUTTON2_PIN);
  bool button3State = digitalRead(BUTTON3_PIN); // Đọc trạng thái nút mới

  if (lastButton1State == HIGH && button1State == LOW) {
    button1Value++;
    if(button1Value > 2){
      button1Value = 1;
    }
  }
  if (button1Value == 2){
  if (lastButton2State == HIGH && button2State == LOW) {
    wateringHour++;
    if(wateringHour > 24){
      wateringHour = 0;
    }
  }
  if (lastButton3State == HIGH && button3State == LOW) {
    wateringMinute += 30;
    if(wateringMinute > 30){
      wateringMinute = 0;
    }
  }     
  }

  lastButton1State = button1State;
  lastButton2State = button2State;
  lastButton3State = button3State; // Cập nhật trạng thái nút mới
}

// Hàm hiển thị dữ liệu lên màn hình OLED
void displayData(DateTime now, float temperature, float humidity, float soilMoisture) {
  display.clearDisplay();

  // Hiển thị thời gian
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print(F("Time: "));
  if (now.hour() < 10) display.print("0");
  display.print(now.hour());
  display.print(":");
  if (now.minute() < 10) display.print("0");
  display.print(now.minute());
  display.print(":");
  if (now.second() < 10) display.print("0");
  display.print(now.second());

  // Hiển thị ngày tháng
  display.setCursor(0, 10);
  display.print(F("Date: "));
  display.print(now.day());
  display.print("/");
  display.print(now.month());
  display.print("/");
  display.print(now.year());

  // Hiển thị nhiệt độ
  display.setCursor(0, 25);
  display.print(F("Nhiet do: "));
  if (temperature == -999) {
    display.print(F("Loi"));
  } else {
    display.print((int)temperature); // Chuyển thành số nguyên
    display.print(F(" C"));
  }

  // Hiển thị độ ẩm
  display.setCursor(0, 35);
  display.print(F("Do am: "));
  if (humidity == -999) {
    display.print(F("Loi"));
  } else {
    display.print((int)humidity); // Chuyển thành số nguyên
    display.print(F(" %"));
  }

  // Hiển thị độ ẩm đất
  display.setCursor(0, 45);
  display.print(F("Do am dat: "));
  display.print(soilMoisture);
  display.print(F(" %"));

  // Hiển thị giá trị nút nhấn
  display.setCursor(0, 55);
  if(button1Value == 1){
    display.print(F("Che do: Tu dong"));
  }
  if(button1Value == 2){
    display.print(F("Che do: "));
    display.print(wateringHour);
    display.print(F("h"));
    display.print(wateringMinute);
  }

  // Cập nhật màn hình
  display.display();
}
