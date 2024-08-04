// CODE MÁY ĐO NHIỆT ĐỘ
// transitor đo nhiệt độ LM35
// màn hình I2C oled

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int nutNhan01 = 8;
int nutNhan02 = 9;
int trangThai01; 
int trangThai02;
int soTrangThai02;
int soDem = 5;
int soDem1 = 3;

float temperature;

void setup() {
  Serial.begin(9600);
  pinMode(nutNhan01,INPUT_PULLUP);
  pinMode(nutNhan02,INPUT_PULLUP);

  Wire.begin(); // Khởi tạo giao tiếp I2C

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Failed to initialize SSD1306 display"));
    for(;;);
  }
}


void lamNongCamBien(){
  display.clearDisplay();
  if(soDem1 < 4){
    for(int u1 = 5; u1>0; u1--){
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 16);
    display.print("Waiting ");
    display.print(u1);
    display.display(); // Hiển thị trên màn hình
    display.clearDisplay(); // Xóa màn hình trước khi hiển thị dữ liệu mới
    delay(1000);
    }
    soDem1++;
  }
}

void loop() {

  lamNongCamBien();

  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);

  trangThai01 = digitalRead(nutNhan01);
  if(trangThai01 == LOW) { // Kiểm tra nút nhấn 01
    temperature = voltage * 100;
  }

  trangThai02 = digitalRead(nutNhan02);
  if (trangThai02 == HIGH && soTrangThai02 == LOW) { // Kiểm tra nút nhấn 02
    soDem++;
    if (soDem == 8) {
      soDem = 5;
    }
    soTrangThai02 = HIGH;
  } else if (trangThai02 == LOW) {
    soTrangThai02 = LOW;
  }

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Nhiet do:");

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 16);
  switch (soDem) {
    case 5:
      display.print(temperature);
      display.print(" C");
      break;
    case 6:
      display.print(temperature + 273);
      display.print(" K");
      break;
    case 7:
      display.print((temperature * 1.8) + 32);
      display.print(" F");
      break;
  }

  Serial.println("Temperature : ");
  Serial.println(temperature);
  delay(100);
  display.display(); // Hiển thị trên màn hình
  display.clearDisplay(); // Xóa màn hình trước khi hiển thị dữ liệu mới
}
