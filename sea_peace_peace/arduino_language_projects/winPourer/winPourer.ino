#define CLK 6 
#define DT 5   
#define E3F 4
#define RELAYPIN 7


int counter = 0;      // Biến để lưu giá trị tăng/giảm
int lastStateCLK;     // Lưu trạng thái trước đó của chân CLK
int currentStateCLK;  // Trạng thái hiện tại của chân CLK
int e3fState = 0;
int lastE3FState = 3;
int soLanRot = 0;
unsigned long runTime = 0;
int waitTime = 1500; // chỉnh thời gian chờ trước khi rót
int pumpInTime = 0;


void numXoay(){
  // Đọc trạng thái hiện tại của CLK
  currentStateCLK = digitalRead(CLK);

  // Nếu trạng thái CLK thay đổi, nghĩa là núm đã xoay
  if (currentStateCLK != lastStateCLK) {
    // Kiểm tra hướng xoay dựa trên trạng thái của DT
    if (digitalRead(DT) != currentStateCLK) {
      counter++;  // Xoay theo chiều kim đồng hồ
    } else {
      counter--;  // Xoay ngược chiều kim đồng hồ
    }

    if(counter > 10){
      counter = 10;
    }
    if(counter <0){
      counter = 0;
    }

    // In giá trị counter ra Serial Monitor
    Serial.println("Thoi gian rot: " + String(counter) + " giay");
  }

  // Cập nhật trạng thái CLK cho lần đọc tiếp theo
  lastStateCLK = currentStateCLK;

}

void camBienVatCan(){
  e3fState = digitalRead(E3F);
}

void relayMayBom(bool u){
  if(u){
    digitalWrite(RELAYPIN, HIGH);
  }
  else{
    digitalWrite(RELAYPIN, LOW);
  }
}

void logicHeThong(){
  pumpInTime = counter * 1000;

  if(e3fState == 0){
    if(lastE3FState != e3fState){
      runTime = millis();
      lastE3FState = e3fState;
      soLanRot++;
      Serial.println("So lan rot: " + String(soLanRot));
    }

    unsigned long currentMillis = millis();

    if(currentMillis - runTime >= waitTime && currentMillis - runTime < pumpInTime + waitTime){
      relayMayBom(1);
    }

    if(currentMillis >= pumpInTime + waitTime){
      relayMayBom(0);
    }

  }

  if(e3fState == 1){
    lastE3FState = 1;
    relayMayBom(0);
  }

}


void setup() {
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(E3F, INPUT_PULLUP);  // Cấu hình chân E3F là đầu vào với pull-up
  pinMode(RELAYPIN, OUTPUT);
  // Đọc trạng thái ban đầu của CLK
  lastStateCLK = digitalRead(CLK);

  // Khởi động Serial Monitor
  Serial.begin(9600);
}

void loop() {
  numXoay();
  camBienVatCan();
  logicHeThong();
}
