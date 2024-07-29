#include "DHT.h"            
 
const int DHTPIN = 13;       //Đọc dữ liệu từ DHT11 ở chân 13 trên mạch Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
 
DHT dht(DHTPIN, DHTTYPE);

const int aPin=2;
const int bPin=3;
const int cPin=4;
const int dPin=5;
const int ePin=6;
const int fPin=7;
const int gPin=8;  

const int a2Pin=9;
const int b2Pin=10;
const int c2Pin=11;
const int d2Pin=12;
const int e2Pin=14;
const int f2Pin=15;
const int g2Pin=16; 




void setup() {
 pinMode(aPin, OUTPUT);
 pinMode(bPin, OUTPUT);
 pinMode(cPin, OUTPUT);
 pinMode(dPin, OUTPUT);
 pinMode(ePin, OUTPUT);
 pinMode(fPin, OUTPUT);
 pinMode(gPin, OUTPUT);

 pinMode(a2Pin, OUTPUT);
 pinMode(b2Pin, OUTPUT);
 pinMode(c2Pin, OUTPUT);
 pinMode(d2Pin, OUTPUT);
 pinMode(e2Pin, OUTPUT);
 pinMode(f2Pin, OUTPUT);
 pinMode(g2Pin, OUTPUT);
 Serial.begin(9600);
 dht.begin();         // Khởi động cảm biến
}

void loop() {
  
  int h = dht.readHumidity();    //Đọc độ ẩm
  int t = dht.readTemperature(); //Đọc nhiệt độ
  int so=t;
  int chuc=so/10;
  int dv=so-chuc*10;


  //hàng đơn vị nha cả nhà
  if(dv==0){
    //so khong
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,0);
  digitalWrite(fPin,0);
  digitalWrite(gPin,1);
  }else if(dv==1){
  //so mot
  digitalWrite(aPin,1);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,1);
  digitalWrite(ePin,1);
  digitalWrite(fPin,1);
  digitalWrite(gPin,1);    
  }else if(dv==2){
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,1);
  digitalWrite(dPin,0);
  digitalWrite(ePin,0);
  digitalWrite(fPin,1);
  digitalWrite(gPin,0);
  }else if(dv==3){
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0); 
  digitalWrite(ePin,1);
  digitalWrite(fPin,1);
  digitalWrite(gPin,0);
  }else if(dv==4){
  digitalWrite(aPin,1);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,1);
  digitalWrite(ePin,1);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0);  
  }else if(dv==5){
   digitalWrite(aPin,0);
  digitalWrite(bPin,1);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,1);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0); 
  }else if(dv==6){
  digitalWrite(aPin,0);
  digitalWrite(bPin,1);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,0);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0);  
  }else if(dv==7){
 digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,1);
  digitalWrite(ePin,1);
  digitalWrite(fPin,1);
  digitalWrite(gPin,1);   
  }else if(dv==8){
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,0);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0);
  }else if(dv==9){
  digitalWrite(aPin,0);
  digitalWrite(bPin,0);
  digitalWrite(cPin,0);
  digitalWrite(dPin,0);
  digitalWrite(ePin,1);
  digitalWrite(fPin,0);
  digitalWrite(gPin,0);
  }
  //hàng chục bắt đầu từ đây nha cả nhà;
  if(chuc==0){
    //so khong
  digitalWrite(a2Pin,0);
  digitalWrite(b2Pin,0);
  digitalWrite(c2Pin,0);
  digitalWrite(d2Pin,0);
  digitalWrite(e2Pin,0);
  digitalWrite(f2Pin,0);
  digitalWrite(g2Pin,1);
  }else if(chuc==1){
  //so mot
  digitalWrite(a2Pin,1);
  digitalWrite(b2Pin,0);
  digitalWrite(c2Pin,0);
  digitalWrite(d2Pin,1);
  digitalWrite(e2Pin,1);
  digitalWrite(f2Pin,1);
  digitalWrite(g2Pin,1);    
  }else if(chuc==2){
  digitalWrite(a2Pin,0);
  digitalWrite(b2Pin,0);
  digitalWrite(c2Pin,1);
  digitalWrite(d2Pin,0);
  digitalWrite(e2Pin,0);
  digitalWrite(f2Pin,1);
  digitalWrite(g2Pin,0);
  }else if(chuc==3){
  digitalWrite(a2Pin,0);
  digitalWrite(b2Pin,0);
  digitalWrite(c2Pin,0);
  digitalWrite(d2Pin,0); 
  digitalWrite(e2Pin,1);
  digitalWrite(f2Pin,1);
  digitalWrite(g2Pin,0);
  }else if(chuc==4){
  digitalWrite(a2Pin,1);
  digitalWrite(b2Pin,0);
  digitalWrite(c2Pin,0);
  digitalWrite(d2Pin,1);
  digitalWrite(e2Pin,1);
  digitalWrite(f2Pin,0);
  digitalWrite(g2Pin,0);  
  }else if(chuc==5){
   digitalWrite(a2Pin,0);
  digitalWrite(b2Pin,1);
  digitalWrite(c2Pin,0);
  digitalWrite(d2Pin,0);
  digitalWrite(e2Pin,1);
  digitalWrite(f2Pin,0);
  digitalWrite(g2Pin,0); 
  }else if(chuc==6){
  digitalWrite(a2Pin,0);
  digitalWrite(b2Pin,1);
  digitalWrite(c2Pin,0);
  digitalWrite(d2Pin,0);
  digitalWrite(e2Pin,0);
  digitalWrite(f2Pin,0);
  digitalWrite(gPin,0);  
  }else if(chuc==7){
 digitalWrite(a2Pin,0);
  digitalWrite(b2Pin,0);
  digitalWrite(c2Pin,0);
  digitalWrite(d2Pin,1);
  digitalWrite(e2Pin,1);
  digitalWrite(f2Pin,1);
  digitalWrite(g2Pin,1);   
  }else if(chuc==8){
  digitalWrite(a2Pin,0);
  digitalWrite(b2Pin,0);
  digitalWrite(c2Pin,0);
  digitalWrite(d2Pin,0);
  digitalWrite(e2Pin,0);
  digitalWrite(f2Pin,0);
  digitalWrite(g2Pin,0);
  }else if(chuc==9){
  digitalWrite(a2Pin,0);
  digitalWrite(b2Pin,0);
  digitalWrite(c2Pin,0);
  digitalWrite(d2Pin,0);
  digitalWrite(e2Pin,1);
  digitalWrite(f2Pin,0);
  digitalWrite(g2Pin,0);
  }
  
  //in ra màn hình máy tính nha cả nhà
  Serial.print("Nhiet do: ");
  Serial.println(t);               //Xuất nhiệt độ
  Serial.print("Do am: ");
  Serial.println(h);               //Xuất độ ẩm
  
  Serial.println();                //Xuống hàng
  delay(500);                     //Đợi 1 giây  

}
