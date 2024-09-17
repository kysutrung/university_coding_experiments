    const int trig = 11; // chân trig của HC-SR04
    const int echo = 12; // chân echo của HC-SR04
    const int aPin = 2;
    const int bPin = 3;
    const int cPin = 4;
    const int dPin = 5;
    const int ePin = 6;
    const int fPin = 7;
    const int gPin = 8;

    void setup() {
      Serial.begin(9600); // giao tiếp Serial với baudrate 9600
      pinMode(trig, OUTPUT); // chân trig sẽ phát tín hiệu
      pinMode(echo, INPUT); // chân echo sẽ nhận tín hiệu
      pinMode(aPin, OUTPUT);
      pinMode(bPin, OUTPUT);
      pinMode(cPin, OUTPUT);
      pinMode(dPin, OUTPUT);
      pinMode(ePin, OUTPUT);
      pinMode(fPin, OUTPUT);
      pinMode(gPin, OUTPUT);
    }

    void loop() {
      unsigned long duration; // biến đo thời gian
      int distance; // biến lưu khoảng cách

      /* Phát xung từ chân trig */
      digitalWrite(trig, 0); // tắt chân trig
      delayMicroseconds(2);
      digitalWrite(trig, 1); // phát xung từ chân trig
      delayMicroseconds(5); // xung có độ dài 5 microSeconds
      digitalWrite(trig, 0); // tắt chân trig

      /* Tính toán thời gian */
      // Đo độ rộng xung HIGH ở chân echo. 
      duration = pulseIn(echo, HIGH);
      // Tính khoảng cách đến vật.
      distance = int(duration / 2 / 29.412);
      // Điều khiển led 7 thanh
      if (distance > 90) {
        digitalWrite(aPin, 1);
        digitalWrite(bPin, 1);
        digitalWrite(cPin, 1);
        digitalWrite(dPin, 1);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 1);
        digitalWrite(gPin, 1);
      } else if (distance <= 90 && distance > 80) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (distance <= 80 && distance > 70) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 0);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (distance <= 70 && distance > 60) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 1);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 1);
        digitalWrite(gPin, 1);
      } else if (distance <= 60 && distance > 50) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 1);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 0);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (distance <= 50 && distance > 40) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 1);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (distance <= 40 && distance > 30) {
        digitalWrite(aPin, 1);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 1);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (distance <= 30 && distance > 20) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 1);
        digitalWrite(gPin, 0);
      } else if (distance <= 20 && distance > 10) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 1);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 0);
        digitalWrite(fPin, 1);
        digitalWrite(gPin, 0);
      } else if (distance <= 10) {
        digitalWrite(aPin, 1);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 1);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 1);
        digitalWrite(gPin, 1);
      }

      /* In kết quả ra Serial Monitor */
      Serial.print(distance);
      Serial.println("cm");
      delay(200);
    }