/* File Tổng Ôn Tập Bộ Môn Lập Trình C/C++
Người Biên Tập: Nguyễn Đức Trung
Liên Hệ: linktr.ee/trungtaulua
Ngày Tạo File: 26 Tháng 2 Năm 2024
Nội Dung: Ôn Tập Các Tính Chất Phổ Biến Có Trong
Ngôn Ngữ Lập Trình C/C++ Sau Một Thời Gian Học Tập */

//khai báo thư viện
#include <iostream> //thư viện in/output tiêu chuẩn
#include <bits/stdc++.h> //file này bao gồm tất cả thư viện
using namespace std;

//biến và các kiểu dữ liệu hay dùng
int num1 = 1,num2 = 2;
int arr1[4];//cách khai báo một mảng kiểu dữ liệu + tên + số lượng 
float num3 = 1.2;//float là 32bit nên lưu được ít hơn double
double num4 = 2.2;//double tốn bộ nhớ hơn nên tính toán chậm hơn
int num5 = (int)num4;//đây gọi là ép kiểu
char let1 = 'a';
bool tf1 = true;
int *ptr1 = &num1;//ptr1 gọi là con trỏ và &num1 là lệnh để lấy địa chỉ của biến num1
int *ptr2 = arr1;//arr1 không điền số chỉ thứ tự thì nó sẽ là địa chỉ của ô nhớ đầu tiên có trong mảng
vector <int> vec1 (5); //cách khai báo một vector 5 chỗ
vector <char> vec2 {'a','b','c'}; //cách khai báo phần tử trong vector
string str1 = "hehehe"; //cách khai báo một chuỗi

//khai báo prototype
//ở file này có thể dùng phần này như một cái mục lục
//function
void chaoTheGioi();
void dieuKien1();
void dieuKien2();
void loop1(int i);
void loop2(int i);
void loop3(int i);
void toanTu();
void streamContrl();
int traVe(int a, int b);//hàm này được quy về dạng pass by value
void pasByRef(int &ref);//hàm này được quy về dạng pass by reference
void nhapXuat();//cách đọc dữ liệu được nhập từ bàn phím
void capPhatDong(); //cách cấp phát và sử dụng bộ nhớ động
void xuLyNgoaiLe(); //cách dùng chức năng xử lý ngoại lệ
void nhapXuatFile(); //cách sử dụng nhập xuất file

//cách khai báo một template
//template không thể khai báo prototype hoặc khai báo trong một hàm
template <typename T>
void print(T value) {
    std::cout << value << std::endl;
}


//các tính chất hướng đối tượng của ngôn ngữ
//class không thể khai báo prototype được nên phải viết luôn ở trước main
class NhanVien //cách khai báo một class đơn giản
{
protected: //đây là từ khóa dùng để phân chia các khu vực có quyền truy cập khác nhau
    string hoTen;
    float luong;

public: //những vùng truy cập này giúp bảo vệ giữ liệu
        //đây được gọi là tính đóng gói
    NhanVien()
    {
        this->hoTen = "";
        this->luong = 0.0;
    }

    void nhap()
    {
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, this->hoTen);
    }

    void xuat()
    {
        cout << "Ho ten: ";
        cout << this->hoTen << endl;
    }

    virtual void tinhLuong(){} 
    //cùng một phương thức(method) nhưng ở các class dẫn xuất lại được biến đổi
    //đây gọi là tính đa hình

    //việc ẩn đi chi tiết của method tinhLuong mà chỉ đề cao tính tái sử dụng cấu trúc
    //đây gọi là tính trừu tượng
};

//từ một class cơ sở viết được các class dẫn xuất
//các class dẫn xuất có các tính chất của class cơ sở
//đây được gọi là tính kế thừa

class NhanVienSanXuat : public NhanVien //cách khai báo một class kế thừa tính chất của class khác
{
private:
    int soSanPham;
    float tienCong1SP;

public:
    NhanVienSanXuat() : NhanVien()
    {
        this->soSanPham = 0;
        this->tienCong1SP = 0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "So san pham: ";
        cin >> this->soSanPham;
        cout << "Tien cong 1 san pham: ";
        cin >> this->tienCong1SP;
    }

    void xuat()
    {
        cout << "So san pham: ";
        cout << this->soSanPham << endl;
        cout << "Tien cong 1 san pham: ";
        cout << this->tienCong1SP << endl;
        cout << "Luong: ";
        cout << this->luong << endl;
    }

    void tinhLuong()
    {
        this->luong = this->soSanPham * this->tienCong1SP;
    }
};

class NhanVienVanPhong : public NhanVien
{
private:
    float luongCoBan;
    int soNgayLamViec;

public:
    NhanVienVanPhong() : NhanVien()
    {
        this->luongCoBan = 0.0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "Luong co ban: ";
        cin >> this->luongCoBan;
        cout << "So ngay lam viec: ";
        cin >> this->soNgayLamViec;
    }

    void xuat()
    {
        NhanVien::xuat();
        cout << "Luong co ban: ";
        cout << this->luongCoBan << endl;
        cout << "So ngay lam viec: ";
        cout << this->soNgayLamViec << endl;
        cout << "Luong: ";
        cout << this->luong << endl;
    }

    void tinhLuong()
    {
        this->luong = this->soNgayLamViec * this->luongCoBan;
    }
};

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw "Division by zero error"; // Ném một ngoại lệ kiểu const char*
    }
    return numerator / denominator;
}    

//hàm main của chương trình
int main(){
    xuLyNgoaiLe();

    //biểu thức lambda
    // [capture-list](reference)->return-type{body}
    int y = 4;
    auto congSo = [&](int x){ y = y+x;};
    congSo(10);
    cout<<y<<endl;
}

//cách khai báo một function
void chaoTheGioi(){
    cout<<"Goodbye World !!!!"<<endl;//cách in chữ ra màn hình
}

void dieuKien1(){
    //hàm điều kiện if else
    if(num1 = 1){
        cout<<"Dieu kien cua num1 da dung"<<endl;
    }
    else{
        cout<<"Dieu kien cua num1 da sai"<<endl;
    }
}

void dieuKien2(){
    //hàm điều kiện switch case
    switch(num2){
        case 1:
            cout<<"num2 = 1"<<endl;
        case 2:
            cout<<"num2 = 2"<<endl;
    }
}

void loop1(int i){
    //vòng lặp for
    for(int n=0; n<i; n++){
        cout<<"for loop "<<n<<endl;
    }
}

void loop2(int i){
    //vòng lặp while
    int a = 0;
    while(a<i){
        cout<<"while loop "<<a<<endl;
        a++;
    }
}

void loop3(int i){
    int a = 0;
    do{
        cout<<"do while loop"<<a<<endl;
        a++;
    }while(a<i);
}

void toanTu(){
int a=8;
int b=4;
/*
Các Loại Toán Tử Cơ Bản
1. Toán tử toán học
a++ tương đương a=a+1
a-- tương đương a=a-1
a % b tương đương số dư khi lấy a chia b
còn lại các dấu cộng trừ nhân chia sử dụng như bình thường
2. Toán tử logic
|| = hoặc
&& = và
! = NOT(phủ định một điều gì đó)
== = =
3. Toán tử quan hệ
<
>
>=
<=
*/
}

void streamContrl(){
    for(int i = 1; i<10; i++){
        if(i==4){
            continue;//kết thúc vòng lặp này để chạy vòng lặp mới
        }
        if(i==7){
            cout<<"run break at"<<i<<endl;
            break;//kết thúc luôn không lặp thêm lần nào nữa
        }
        cout<<"num "<<i<<endl;
    }
}

int traVe(int a, int b){
    return a*b;
}

void nhapXuat(){
    int a;
    cout<<"Nhap 1 so: ";
    cin>>a;
    cout<<"So vua nhap:"<<a<<endl;
}

void pasByRef(int &ref){
    ref = ref*2;
}

void capPhatDong(){
    // Cấp phát bộ nhớ động cho một biến kiểu int
    int *ptr = new int;
    // Kiểm tra xem cấp phát bộ nhớ có thành công không
    if (ptr == nullptr) {
        std::cout << "Failed to allocate memory!" << std::endl;
    }
    // Gán giá trị cho biến được cấp phát bộ nhớ
    *ptr = 5;
    // In ra giá trị của biến
    std::cout << "Value of dynamically allocated variable: " << *ptr << std::endl;
    // Giải phóng bộ nhớ đã cấp phát
    delete ptr;
}

void xuLyNgoaiLe(){
    double a = 10.0;
    double b = 2.0; //thay đổi số này để thấy sự khác biệt

    try {
        // Gọi hàm divide() trong khối try
        double result = divide(a, b);
        std::cout << "Result of division: " << result << std::endl;
    } catch (const char* error) { // Bắt ngoại lệ kiểu const char*
        std::cerr << "Error: " << error << std::endl;
    }

}

void nhapXuatFile(){
    //nhập xuất file sử dụng thư viện fstream
     std::ofstream outputFile("output.txt");

    // Kiểm tra xem file có được mở thành công không
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
    }

    // Ghi dữ liệu vào file
    outputFile << "Hello, World!" << std::endl;
    outputFile << "This is a line written to a file." << std::endl;

    // Đóng file sau khi ghi xong
    outputFile.close();

    // Mở file để đọc dữ liệu
    std::ifstream inputFile("output.txt");

    // Kiểm tra xem file có được mở thành công không
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
    }

    // Đọc dữ liệu từ file và in ra màn hình
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    // Đóng file sau khi đọc xong
    inputFile.close();

}