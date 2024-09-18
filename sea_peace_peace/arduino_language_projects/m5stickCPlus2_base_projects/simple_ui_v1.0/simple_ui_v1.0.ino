//CHƯƠNG TRÌNH TẠO GIAO DIỆN ĐƠN GIẢN CHO ESP32 dựa trên một số hàm có sẵn của M5Stack

#include "M5StickCPlus2.h"  // Đọc tài liệu để cài thư viện M5StickC Plus 2

int x = 0;
int y = 0;
int z = 0;

void test_a(){
  if(x == 0){
    StickCP2.Display.clear();
    StickCP2.Display.setCursor(20, 20);
    StickCP2.Display.print("Hehehe :)");
    x++;
  }
}

void test_b(){
  if(y == 0){
    StickCP2.Display.clear();
    StickCP2.Display.setCursor(20, 20);
    StickCP2.Display.print("Dit me may");
    y++;
  }
}

void test_c(){
  if(z == 0){
    StickCP2.Display.clear();
    StickCP2.Display.setCursor(20, 20);
    StickCP2.Display.print("DCM Le Xuan Hai");
    z++;
  }
}


int num_a = 0;
int num_b = -1;
int num_c = 0;

void hienThiMode(int var_a){
  if(var_a == 1){
    StickCP2.Display.clear();
    StickCP2.Display.setTextColor(GREEN);
    StickCP2.Display.setCursor(20, 15);
    StickCP2.Display.print("Mode 1");
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 45);
    StickCP2.Display.print("Mode 2");
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 75);
    StickCP2.Display.print("Mode 3");
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 105);
    StickCP2.Display.print("Mode 4");    
  }

  if(var_a == 2){
    StickCP2.Display.clear();
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 15);
    StickCP2.Display.print("Mode 1");
    StickCP2.Display.setTextColor(GREEN);
    StickCP2.Display.setCursor(20, 45);
    StickCP2.Display.print("Mode 2");
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 75);
    StickCP2.Display.print("Mode 3");
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 105);
    StickCP2.Display.print("Mode 4");    
  }

  if(var_a == 3){
    StickCP2.Display.clear();
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 15);
    StickCP2.Display.print("Mode 1");
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 45);
    StickCP2.Display.print("Mode 2");
    StickCP2.Display.setTextColor(GREEN);
    StickCP2.Display.setCursor(20, 75);
    StickCP2.Display.print("Mode 3");
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 105);
    StickCP2.Display.print("Mode 4");    
  }

  if(var_a == 4){
    StickCP2.Display.clear();
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 15);
    StickCP2.Display.print("Mode 1");
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 45);
    StickCP2.Display.print("Mode 2");
    StickCP2.Display.setTextColor(WHITE);
    StickCP2.Display.setCursor(20, 75);
    StickCP2.Display.print("Mode 3");
    StickCP2.Display.setTextColor(GREEN);
    StickCP2.Display.setCursor(20, 105);
    StickCP2.Display.print("Mode 4");    
  }
}

void luaChonMode(){
  StickCP2.update();
  if(StickCP2.BtnA.wasClicked()){
    num_a++;
    num_c = 0;
    y = 0;
    x = 0;
    z = 0;
  }

  if(num_a == 4){
    num_a = 0;
  }

  if(StickCP2.BtnB.wasClicked()){
    num_c++;
  }

  if(num_a != num_b){
    if(num_a == 0){
      hienThiMode(1);
    }

    if(num_a == 1){
      hienThiMode(2);
    }

    if(num_a == 2){
      hienThiMode(3);
    }

    if(num_a == 3){
      hienThiMode(4);
    }

    num_b = num_a;
  }

  if(num_a == 0){
    if(num_c > 0){
      
    }
  }

  if(num_a == 0){
    if(num_c > 0){
      test_b();
    }
  }

  if(num_a == 1){
    if(num_c > 0){
      test_c();
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

    // Đặt màu nền màn hình là màu đen
    StickCP2.Display.fillScreen(BLACK);

    StickCP2.Display.setRotation(3);

    StickCP2.Display.setTextSize(2);

    StickCP2.Display.fillScreen(BLACK);

}

void loop() {
    luaChonMode();

}
