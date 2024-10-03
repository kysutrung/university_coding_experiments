#include "FS.h"
#include "SD_MMC.h"

#define LED_PIN 4 

String THOIGIAN = " - x gio y phut";

void ghiFile(int u, int v){

  for(int x = 0; x < u; x++){
    File file = SD_MMC.open("/meo.txt", FILE_APPEND);

    if (!file) {
      Serial.println("Khong the tao file test.txt");
      return;
    }

    // Ghi noi dung vao file
    file.println(v + THOIGIAN);

    // Dong file de ket thuc viec ghi du lieu
    file.close();
    Serial.println("Da ghi noi dung vao file thanh cong!");
  }

}

void docFile(){

  File file = SD_MMC.open("/gau.txt");
  if (!file || file.isDirectory()) {
    Serial.println("erro");
    return;
  }

  Serial.print("Number: ");
  while (file.available()){
    Serial.write(file.read());
  }

  // Đóng file sau khi đọc xong
  file.close();

}

void setup() {
  // Khoi tao Serial de kiem tra ket qua
  Serial.begin(115200);
  delay(1000);  // Doi mot chut de Serial Monitor san sang

  // Cau hinh GPIO33 (LED_PIN) la OUTPUT de dieu khien den LED
  pinMode(LED_PIN, OUTPUT);

  // Tat den LED
  digitalWrite(LED_PIN, LOW);

  // Khoi tao the SD qua giao tiep MMC
  if (!SD_MMC.begin("/sdcard", true)) {
    Serial.println("Khong the khoi tao the SD");
    return;
  }
  Serial.println("Khoi tao the SD thanh cong!");

  // Kiem tra the nho da san sang
  if (!SD_MMC.cardType()) {
    Serial.println("Khong co the SD");
    return;
  }
  
  ghiFile(3, 70);
  docFile();
}

void loop() {
  
}
