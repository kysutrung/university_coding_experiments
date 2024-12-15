#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Kích thước màn hình OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Chân kết nối OLED (SPI)
#define OLED_MOSI   11 // D1 trên OLED
#define OLED_CLK    13 // D0 trên OLED
#define OLED_DC     8  // DC trên OLED
#define OLED_CS     10 // CS trên OLED
#define OLED_RESET  9  // RES trên OLED

// Khởi tạo màn hình OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  // Khởi tạo OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    while (true); // Nếu không tìm thấy OLED, dừng lại
  }

  // Bật tất cả các pixel trên màn hình
  display.clearDisplay();
  display.fillScreen(SSD1306_WHITE);
  display.display();
}

void loop() {
  // Không cần thực hiện gì trong loop
}
