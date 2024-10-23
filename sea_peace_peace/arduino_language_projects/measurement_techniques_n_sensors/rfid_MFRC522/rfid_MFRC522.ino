#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN    0     // Chân RST của RFID (GPIO0)
#define SS_PIN     2     // Chân SDA của RFID (GPIO2)

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Tạo đối tượng MFRC522

MFRC522::MIFARE_Key key;  // Khai báo khóa mặc định

void setup() {
  Serial.begin(115200);   // Khởi động Serial
  SPI.begin();            // Khởi động SPI bus
  mfrc522.PCD_Init();     // Khởi động MFRC522

  // Khởi tạo khóa mặc định là 0xFF cho tất cả 6 byte (mặc định của thẻ RFID MIFARE)
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  Serial.println("Scan RFID card to write new data...");
}

void loop() {
  // Kiểm tra xem có thẻ được đặt gần module hay không
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Đọc thẻ
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println("Card detected!");

  // Xóa dữ liệu cũ từ sector 1 (block 4,5,6)
  byte block = 4;  // Block để ghi dữ liệu (Sector 1 - block 4)
  byte newData[] = "hehe"; // Dữ liệu mới để ghi

  // Ghi dữ liệu mới
  writeBlock(block, newData);

  // Kết thúc quá trình đọc thẻ
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}

// Hàm để ghi dữ liệu vào block của thẻ RFID
void writeBlock(byte block, byte data[]) {
  MFRC522::StatusCode status;
  
  // Xác thực quyền ghi block
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Authentication failed: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // Ghi dữ liệu vào block
  status = mfrc522.MIFARE_Write(block, data, 16);  // Ghi dữ liệu (tối đa 16 byte cho một block)
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Writing failed: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  Serial.println("Data written successfully!");
}

