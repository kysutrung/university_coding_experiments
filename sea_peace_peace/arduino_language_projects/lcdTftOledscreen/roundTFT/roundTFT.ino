/*
CS -> D8 (GPIO15) trên ESP8266.
DC -> D3 (GPIO0) trên ESP8266.
RES -> D4 (GPIO2) trên ESP8266.
SDA (MOSI) -> D7 (GPIO13) trên ESP8266.
SCL (SCK) -> D5 (GPIO14) trên ESP8266.
*/

#include <TFT_eSPI.h>  // Thư viện TFT_eSPI
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Tạo đối tượng TFT

void setup() {
  
  // Khởi động màn hình
  tft.init();
  tft.setRotation(0);  // Đặt hướng màn hình (có thể là 0, 1, 2, 3 tùy cách xoay)

  // Xóa màn hình với màu đen
  tft.fillScreen(TFT_BLACK);

  // Chọn màu chữ và màu nền
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  // Chữ màu trắng, nền đen
  tft.setTextSize(3);  // Đặt kích thước chữ (có thể chỉnh để phóng to/thu nhỏ)

  // Hiển thị chữ ở tọa độ (x, y)
  tft.setCursor(60, 60);  
  tft.println("EM YEU");   
  tft.setCursor(25, 100);  
  tft.println("LE XUAN HAI");

  tft.fillRect(30, 140, 40, 40, TFT_RED);
  tft.fillRect(100, 140, 40, 40, TFT_GREEN);
  tft.fillRect(170, 140, 40, 40, TFT_BLUE);
}

int num_1 = 0;

void loop() {
  if(num_1 == 0){
    tft.fillRect(30, 140, 40, 40, TFT_RED);
    tft.fillRect(100, 140, 40, 40, TFT_GREEN);
    tft.fillRect(170, 140, 40, 40, TFT_BLUE);
    num_1 = 1;
  }
  else if(num_1 == 1){
    tft.fillRect(30, 140, 40, 40, TFT_BLUE);
    tft.fillRect(100, 140, 40, 40, TFT_RED);
    tft.fillRect(170, 140, 40, 40, TFT_GREEN);
    num_1 = 0;
  }
  delay(100);
}
