//Project Nâng Cấp Độ An Toàn Của Pháo Hoa Z121


#include <TM1637Display.h>

//=================KHÁI BÁO CHÂN CẮM======================================================================

//màn hình led
const int CLK_PIN = 2; // Chân kết nối Clock
const int DIO_PIN = 3; // Chân kết nối Data
TM1637Display display(CLK_PIN, DIO_PIN);
//đèn xác nhận kích cháy
const int ledCF1 = 4; //led màu xanh sáng khi nhấn nút demNguoc 3 lần
const int ledCF2 = 5; //led màu vàng sáng khi nhấn nút demNguoc 6 lần
const int ledCF3 = 6; //led màu đỏ sáng khi nhấn nút demNguoc 9 lần

//nút nhấn
const int demNguoc = 7;
const int themThoiGian = 8; //nút thêm thời gian đếm ngược
const int botThoiGian = 9; //Nut giảm thời gian đếm ngược
const int xacNhan = 10; //Nút xác nhận thời gian đếm ngược và hủy xác nhận nếu nút demNguoc chưa được nhấn 9 lần
//khi nhan nút này thì số phút tăng giảm lúc nãy sẽ nhân với 60 để đổi thành giây, nhấn một lần nữa sẽ đổi thành phút

//relay
const int kichHoat = 11; //relay kết nối pin 9V với kíp kích cháy

//====================KHAI BÁO CÁC BIẾN SỐ========================================================

int trangThai = 0;
int soTrangThai = 0;

int trangThaiHai = 0;
int soTrangThaiHai = 0;

int trangThaiBa = 0;
int soTrangThaiBa = 0;

int trangThaiBon = 0;
int soTrangThaiBon = 0;

int soTrenLed = 1;

int trangThaiXacNhan = 2;

int soKichHoat = 0;

//================================================================================================

void setup() {
  pinMode(demNguoc, INPUT);
  pinMode(themThoiGian, INPUT);
  pinMode(botThoiGian, INPUT);
  pinMode(xacNhan, INPUT);
  pinMode(kichHoat, OUTPUT);
  digitalWrite(kichHoat, 1);
  display.setBrightness(0x0f); // Điều chỉnh độ sáng, giá trị từ 0x00 đến 0x0f

  pinMode(ledCF1, OUTPUT);
  pinMode(ledCF2, OUTPUT);
  pinMode(ledCF3, OUTPUT);

  Serial.begin(9600);

}

//================================================================================================

void nutTangThoiGian() {
  trangThai = digitalRead(themThoiGian);

  if (trangThai == 0 && soTrangThai == 0) {
    soTrenLed++;
    soTrangThai = 1;
  }

  if (trangThai == 1 && soTrangThai == 1) {
    soTrangThai = 0;
  }
}

void nutGiamThoiGian() {
  trangThaiHai = digitalRead(botThoiGian);
  if (soTrenLed > 0) {
    if (trangThaiHai == 0 && soTrangThaiHai == 0) {
      soTrenLed--;
      soTrangThaiHai = 1;
    }

    if (trangThaiHai == 1 && soTrangThaiHai == 1) {
      soTrangThaiHai = 0;
    }
  }
}

void nutXacNhan() {
  trangThaiBa = digitalRead(xacNhan);

  if (trangThaiBa == 0 && soTrangThaiBa == 0) {
    trangThaiXacNhan++;
    soTrangThaiBa = 1;
  }

  if (trangThaiBa == 1 && soTrangThaiBa == 1) {
    soTrangThaiBa = 0;
  }

  if (trangThaiXacNhan == 4) {
    soTrenLed = soTrenLed * 60;
    trangThaiXacNhan++;
  }

}

void nutKichHoat() {
  if (trangThaiXacNhan > 4) {
    trangThaiBon = digitalRead(demNguoc);

    if (trangThaiBon == 0 && soTrangThaiBon == 0) {
      soKichHoat++;
      soTrangThaiBon = 1;
    }

    if (trangThaiBon == 1 && soTrangThaiBon == 1) {
      soTrangThaiBon = 0;
    }

    if (soKichHoat >= 3) {
      digitalWrite(ledCF1, 1);
    }
    if (soKichHoat >= 6) {
      digitalWrite(ledCF2, 1);
    }
    if (soKichHoat >= 9) {
      digitalWrite(ledCF3, 1);
    }

  }
}


//==============================================================================

void loop() {

  nutTangThoiGian();
  nutKichHoat();
  nutGiamThoiGian();
  nutXacNhan();

  if (soKichHoat >= 9 && soKichHoat > 0) {
    for (int i = soTrenLed; i > 0; i--) {
      soTrenLed--;
      delay(1000);
      display.showNumberDec(soTrenLed);
    }
  } else {
    display.showNumberDec(soTrenLed);
  }

  if (soTrenLed == 0) {
    digitalWrite(kichHoat, 0);
  }

  Serial.println(soKichHoat);

}