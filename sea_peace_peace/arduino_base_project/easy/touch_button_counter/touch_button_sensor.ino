    //khai bao chan cam
    const int aPin = 2;
    const int bPin = 3;
    const int cPin = 4;
    const int dPin = 5;
    const int ePin = 6;
    const int fPin = 7;
    const int gPin = 8;
    const int SENSOR_PIN = 12;
    //khai bao bien
    int num = 0;
    byte xet = 0;

    void setup() {
      Serial.begin(9600);
      pinMode(SENSOR_PIN, INPUT_PULLUP);
      pinMode(aPin, OUTPUT);
      pinMode(bPin, OUTPUT);
      pinMode(cPin, OUTPUT);
      pinMode(dPin, OUTPUT);
      pinMode(ePin, OUTPUT);
      pinMode(fPin, OUTPUT);
      pinMode(gPin, OUTPUT);
    }

    void loop() {
      //cong tac nhan nha +1
      int state = digitalRead(SENSOR_PIN);

      if (state == 0 && xet == 0) {
        num++;
        xet = 1;
      }
      if (state == 1 && xet == 1) {
        xet = 0;
      }
      if (num > 9) {
        num = 0;
      }

      //hien thi so tren led
      if (num == 0) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 0);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 1);
      } else if (num == 1) {
        digitalWrite(aPin, 1);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 1);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 1);
        digitalWrite(gPin, 1);
      } else if (num == 2) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 1);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 0);
        digitalWrite(fPin, 1);
        digitalWrite(gPin, 0);
      } else if (num == 3) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 1);
        digitalWrite(gPin, 0);
      } else if (num == 4) {
        digitalWrite(aPin, 1);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 1);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (num == 5) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 1);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (num == 6) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 1);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 0);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (num == 7) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 1);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 1);
        digitalWrite(gPin, 1);
      } else if (num == 8) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 0);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (num == 9) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 1);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 0);
      } else if (num == 0) {
        digitalWrite(aPin, 0);
        digitalWrite(bPin, 0);
        digitalWrite(cPin, 0);
        digitalWrite(dPin, 0);
        digitalWrite(ePin, 0);
        digitalWrite(fPin, 0);
        digitalWrite(gPin, 1);
      }

      //in ra màn hình 
      Serial.println(num);
    }