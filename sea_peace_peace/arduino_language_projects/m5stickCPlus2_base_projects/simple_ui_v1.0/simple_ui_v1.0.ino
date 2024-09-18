//CHƯƠNG TRÌNH TẠO GIAO DIỆN ĐƠN GIẢN CHO ESP32 dựa trên một số hàm có sẵn của M5Stack

#include "M5StickCPlus2.h"  // Đọc tài liệu để cài thư viện M5StickC Plus 2
#include "DHT.h"            
 
const int DHTPIN = 26;       //Đọc dữ liệu từ DHT11 ở chân 13 trên mạch Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
 
DHT dht(DHTPIN, DHTTYPE);

int h = 0;
int h_cuoi = -1;
float t = 0;
float t_cuoi = -1;

void m5_dht11(){
  h = dht.readHumidity();    //Đọc độ ẩm
  t = dht.readTemperature(); //Đọc nhiệt độ

  if(h_cuoi != h || t_cuoi != t){
    StickCP2.Display.fillScreen(BLACK);

    StickCP2.Display.setCursor(20, 20);
    StickCP2.Display.setTextColor(YELLOW);
    StickCP2.Display.print("Tem      Hum");

    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 50);
    StickCP2.Display.print(t);
    StickCP2.Display.print("C   ");
    StickCP2.Display.print(h);
    StickCP2.Display.print("% ");

    StickCP2.Display.setCursor(20, 80);
    if(t >= 30){
      StickCP2.Display.setTextColor(RED);
      StickCP2.Display.print("Nong VCL :V");
    }
    if (t >= 24 && t < 30){
      StickCP2.Display.setTextColor(WHITE);
      StickCP2.Display.print("Thuong thoi :|");
    }
    if(t >= 16 && t < 24){
      StickCP2.Display.setTextColor(GREEN);
      StickCP2.Display.print("Pheee :>");
    }
    if(t < 16){
      StickCP2.Display.setTextColor(BLUE);
      StickCP2.Display.print("Lanh VCL :O");
    }
    h_cuoi = h;
    t_cuoi = t;
  }
}

void test_a(){
    StickCP2.Display.setCursor(20, 20);
    StickCP2.Display.print("Hehehe :)");
}

void test_b(){
    StickCP2.Display.setCursor(20, 20);
    StickCP2.Display.print("Dit me may");
}

int num_a = 0;
int num_b = -1;
int num_c = 0;

void lua_chon_mode(){
  StickCP2.update();
  if(StickCP2.BtnA.wasClicked()){
    num_a++;
    num_c = 0;
  }

  if(num_a == 4){
    num_a = 0;
  }

  if(StickCP2.BtnB.wasClicked()){
    num_c++;
  }

  if(num_a != num_b){
    if(num_a == 0){
      StickCP2.Display.clear();
      StickCP2.Display.setCursor(20, 60);
      StickCP2.Display.print("Mode 1");
    }

    if(num_a == 1){
      StickCP2.Display.clear();
      StickCP2.Display.setCursor(20, 60);
      StickCP2.Display.print("Mode 2");
    }

    if(num_a == 2){
      StickCP2.Display.clear();
      StickCP2.Display.setCursor(20, 60);
      StickCP2.Display.print("Mode 3");
    }

    if(num_a == 3){
      StickCP2.Display.clear();
      StickCP2.Display.setCursor(20, 60);
      StickCP2.Display.print("Mode 4");
    }

    num_b = num_a;
  }

  if(num_a == 0){
    if(num_c > 0){
      m5_dht11();
    }
  }

  if(num_a == 1){
    if(num_c > 0){
      test_b();
    }
  }

  if(num_a == 2){
    if(num_c > 0){
      test_a();
    }
  }

}

void setup() {
    // Cấu hình và khởi động M5StickC Plus 2
    auto cfg = M5.config();
    StickCP2.begin(cfg);

    dht.begin();

    // Đặt màu nền màn hình là màu đen
    StickCP2.Display.fillScreen(BLACK);

    StickCP2.Display.setRotation(1);

    StickCP2.Display.setTextSize(2);

    StickCP2.Display.fillScreen(BLACK);

    StickCP2.Display.setTextColor(GREEN);
}

void loop() {
    lua_chon_mode();

}
