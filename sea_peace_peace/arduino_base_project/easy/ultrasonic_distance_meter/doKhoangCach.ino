#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h> 
//Lưu ý khi nạp code thành công mà không thấy màn hình lên chữ thì chỉnh cái chiết áp phía sau
// SDA cắm vào A4; SCL cắm vào A5
#define trigPin 10 // chân trig cắm vào digital 10
#define echoPin 11 // chân echo cắm vào digital 11
const int lcdColumns = 16;
const int lcdRows = 2;
const int lcdAddress = 0x27; // Địa chỉ I2C của màn hình LCD
int nutNhan01 = 12; //Một đầu của nút bấm cắm vào GND một đầu cắm vào chân digital số 12
int nutNhan02 = 13; //Một đầu của nút bấm cắm vào GND một đầu cắm vào chân digital số 13
int trangThai01; //Chân 
int trangThai02;
int soTrangThai02;
int soDem = 5;

LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);// cái này là hàm khởi tạo màn hình

void setup() {
  Serial.begin(9600); // Khởi động giao tiếp Serial
  pinMode(trigPin, OUTPUT); // Đặt chân trig là OUTPUT
  pinMode(echoPin, INPUT); // Đặt chân echo là INPUT
  lcd.init(); // Khởi tạo màn hình LCD
  lcd.backlight(); // Bật nền đèn LCD
  pinMode(nutNhan01,INPUT_PULLUP);
  pinMode(nutNhan02,INPUT_PULLUP);

}

float distance;
float bienTam;

void loop() {
  long duration;
  
  // Tạo xung 10μs trên chân trig để bắt đầu gửi tín hiệu siêu âm
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Đọc thời gian delay từ chân echo
  duration = pulseIn(echoPin, HIGH);
  
  //Đoạn này cho các nút bấm
  trangThai01 = digitalRead(nutNhan01);
  // Chuyển đổi thời gian thành khoảng cách (đơn vị cm)
  if(trangThai01==0){
    bienTam = (duration * 0.034) / 2;
    distance = round(bienTam*10.0)/10.0;
  }
  else{
    distance = distance;
  }

  // In ra Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  //In ra màn hình LCD
  //Đoạn này cho cái nút chuyển đơn vị
  trangThai02 = digitalRead(nutNhan02);
  if (trangThai02 == 1 && soTrangThai02 == 1) {
    soDem++;
    soTrangThai02 = 0;
  }

  if (trangThai02 == 0 && soTrangThai02 == 0) {
    soTrangThai02 = 1;
  }

  if(soDem==7){
    soDem=5;
  }
  //Hết đoạn code cho nút chuyển đơn vị

  if(soDem==5){
    lcd.setCursor(0, 0);
    lcd.print("Distance:");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.print(" cm");
  }
  if(soDem==6){
    lcd.setCursor(0, 0);
    lcd.print("Distance:");
    lcd.setCursor(0, 1);
    lcd.print(distance/2.54);
    lcd.print(" inch");
  }
  
  delay(100); // Điều chỉnh khoảng thời gian delay trước mỗi lần đo
  lcd.clear();
}
