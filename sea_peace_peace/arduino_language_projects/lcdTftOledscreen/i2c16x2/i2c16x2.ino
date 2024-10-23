#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Địa chỉ I2C của LCD, thường là 0x27 hoặc 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(4, 5);  // Khởi tạo I2C trên ESP8266 (4 - D2 - SDA, 5 - D1 - SCL)
  lcd.init();          // Khởi động LCD
  lcd.backlight();     // Bật đèn nền LCD
}

int var_1 = 0;

void loop() {
  lcd.clear();

  if(var_1 == 0){
    lcd.setCursor(0, 0);  // Cột + dòng
    lcd.print("EM YEU LXH");
    var_1 = 1;
  }
  else if(var_1 == 1){
    lcd.setCursor(0, 1);  // Cột + dòng
    lcd.print("EM YEU LXH");
    var_1 = 0;
  }

  delay(1000);
}
