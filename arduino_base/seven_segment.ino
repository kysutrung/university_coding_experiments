const int aPin=2;
const int bPin=3;
const int cPin=4;
const int dPin=5;
const int ePin=6;
const int fPin=7;
const int gPin=8;  



void setup() {
 pinMode(aPin, OUTPUT);
 pinMode(bPin, OUTPUT);
 pinMode(cPin, OUTPUT);
 pinMode(dPin, OUTPUT);
 pinMode(ePin, OUTPUT);
 pinMode(fPin, OUTPUT);
 pinMode(gPin, OUTPUT);
}

void loop() {
  //so khong
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,0);
  digitalWrite(fPin,0);
  digitalWrite(gPin,1);
  delay(1000);
  //so mot
  digitalWrite(aPin,1);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,1);
  digitalWrite(ePin,1);
  digitalWrite(fPin,1);
  digitalWrite(gPin,1);
  delay(1000);
  //so hai
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,1);
  digitalWrite(dPin,0);
  digitalWrite(ePin,0);
  digitalWrite(fPin,1);
  digitalWrite(gPin,0);
  delay(1000);
  //so ba
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0); 
  digitalWrite(ePin,1);
  digitalWrite(fPin,1);
  digitalWrite(gPin,0);
  delay(1000);
  //so bon
  digitalWrite(aPin,1);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,1);
  digitalWrite(ePin,1);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0);
  delay(1000);
  //so nam
  digitalWrite(aPin,0);
  digitalWrite(bPin,1);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,1);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0);
  delay(1000);
  //so sau
  digitalWrite(aPin,0);
  digitalWrite(bPin,1);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,0);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0);
  delay(1000);
  //so bay
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,1);
  digitalWrite(ePin,1);
  digitalWrite(fPin,1);
  digitalWrite(gPin,1);
  delay(1000);
  //so tam
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,0);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0);
  delay(1000);
  //so chin
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,1);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0);
  delay(1000);

}