const int CLK = 2;       // Chân CLK của encoder nối với D2
const int DT = 3;        // Chân DT của encoder nối với D3
const int SW = 4;        // Chân nút bấm của encoder nối với D4 (tùy chọn)

int counter = 0;         // Biến lưu giá trị tăng giảm
int lastCLKState;        // Trạng thái trước đó của chân CLK
bool buttonPressed = false;

void setup() {
  pinMode(CLK, INPUT);             // Chân CLK
  pinMode(DT, INPUT);              // Chân DT
  pinMode(SW, INPUT_PULLUP);       // Chân SW với điện trở kéo lên tích hợp

  Serial.begin(9600);              // Khởi động Serial để in giá trị
  lastCLKState = digitalRead(CLK); // Đọc trạng thái ban đầu của chân CLK
}

void loop() {
  int currentCLKState = digitalRead(CLK);

  // Kiểm tra sự thay đổi trạng thái ở chân CLK
  if (currentCLKState != lastCLKState) {
    // Nếu chân CLK và DT có cùng trạng thái => quay ngược, nếu khác trạng thái => quay xuôi
    if (digitalRead(DT) != currentCLKState) {
      counter++;  // Quay theo chiều kim đồng hồ => tăng
    } else {
      counter--;  // Quay ngược chiều kim đồng hồ => giảm
    }
    if(counter > 12){
      counter = 12;
    }
    if(counter < 0){
      counter = 0
    }
    Serial.print("Volume: ");
    Serial.println(counter);
  }

  lastCLKState = currentCLKState;

  // Kiểm tra nút bấm của encoder (tùy chọn)
  if (digitalRead(SW) == LOW) {  // Khi nút được nhấn
    if (!buttonPressed) {
      counter = 0;  // Đặt lại biến counter về 0
      Serial.println("Đã reset counter về 0");
      buttonPressed = true;
    }
  } else {
    buttonPressed = false;  // Đặt lại trạng thái khi nút được nhả
  }
}
