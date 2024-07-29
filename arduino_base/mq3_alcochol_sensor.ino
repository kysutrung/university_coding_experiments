// Môn: Kỹ Thuật Đo Lường Và Cảm Biến 
// Dự án: Thiết bị đo nồng độ cồn

// Khai báo LCD
#include <Wire.h>

#include <LiquidCrystal_I2C.h>

const int lcdColumns = 16;
const int lcdRows = 2;
const int lcdAddress = 0x27; // Địa chỉ I2C của màn hình LCD
LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows); // cái này là hàm khởi tạo màn hình
// Lưu ý khi nạp code thành công mà không thấy màn hình lên chữ thì chỉnh cái chiết áp phía sau
// SDA cắm vào A4; SCL cắm vào A5
// Khai báo nút bấm
// Một đầu của nút bấm cắm vào GND một đầu cắm vào chân digital số 3
const int nutNhan01 = 3;

const int coiBao = 5; // Khai báo chân cắm còi buzzer

#define digiPin 8 // chân digital của cảm biến cắm vào chân D8
#define anaPin 0 // chân analog của cảm biến cắm vào chân A0

// Các biến đếm sử dụng để chạy các chức năng
int trangThai01; // Trạng thái của nút bấm. Nhấn là 0 nhả là 1
int trangThai02; // Trạng thái của chân digital cảm biến. Có cồn là 0, không có cồn là 1.
int soDem = 0; // Biến đếm lưu số lần hàm loop được lặp
float soHienThiTrenLCD; // Số hiển thị trên màn hình LCD
int MQValue; // Số lấy được từ cảm biến MQ03 
float volt; // Biến lưu giá trị hiệu điện thế
float resistor; // Biến lưu giá trị điện trở
float alcohol; // Biến lưu nồng độ cồn
String s1; // Dòng chữ hiển thị trên LCD

void setup() {
  Serial.begin(9600); // Khởi động giao tiếp Serial
  lcd.init(); // Khởi tạo màn hình LCD
  lcd.backlight(); // Bật nền đèn LCD
  pinMode(nutNhan01, INPUT_PULLUP);
  pinMode(coiBao, OUTPUT);
}

void hienThi01(); // hàm hiển thị nội dung nên serial monitor và LCD
void doNongDo(); // hàm tính toán các giá trị phục vụ bài toán đo nồng độ cồn

void loop() {

  //Xử lý tín hiệu từ nút bấm
  trangThai01 = digitalRead(nutNhan01);
  trangThai02 = digitalRead(digiPin);
  if (trangThai01 == 0) {
    doNongDo();
    soDem++;
    if (trangThai02 == 0) {
      soHienThiTrenLCD = 0.0;
      s1 = "Khong co con";
    } else {
      soHienThiTrenLCD = alcohol / 10;
      s1 = " ";
    }
  } else {
    soDem = 0;
  }

  //Gọi hàm hiển thị các nội dung
  hienThi01();

  //Khi biến đếm soDem >= 5 tương đương với thời gian bấm nút đã là 5 giây thì còi sẽ kêu
  if (soDem >= 5) {
    digitalWrite(coiBao, HIGH);
  } else {
    digitalWrite(coiBao, LOW);
  }

}

void doNongDo() {
  MQValue = analogRead(anaPin); // Đọc giá trị analog từ cảm biến MQ tại chân A0
  volt = MQValue * (5.0 / 1023.0); // Chuyển đổi giá trị đọc được thành điện áp
  resistor = 1000 * ((5 - volt) / volt); // Tính toán giá trị Rs với một điện trở tải (RL) là 1k Ohm
  alcohol = 0.4091 * pow(resistor / 5463, -1.497); // Tính toán nồng độ cồn dựa trên phương trình đã được thu được.
}

void hienThi01() {
  //hiển thị các giá trị trên serial monitor
  Serial.print("MQValue:"); // In ra giá trị ADC
  Serial.print(MQValue);
  Serial.print("    Volt:"); // In ra điện áp
  Serial.print(volt);
  Serial.print("    Rs:"); // In ra giá trị Rs
  Serial.print(resistor);
  Serial.print("    Alcohol:"); // In ra nồng độ cồn
  Serial.print(alcohol);
  Serial.println("mg/L"); // Đơn vị của nồng độ cồn là mg/L
  Serial.print("Nut Bam: "); // In ra trạng thái của nút bấm
  Serial.println(trangThai01);
  Serial.print("Bien dem: "); // In ra giá trị của biến đếm soDem
  Serial.println(soDem);

  //hiển thị các giá trị trên LCD
  lcd.setCursor(0, 0);
  lcd.print("NongDo:");
  lcd.print(soHienThiTrenLCD);
  lcd.print("mg/L");
  lcd.setCursor(0, 1);
  lcd.print(s1);
  delay(1000);
  lcd.clear();
}