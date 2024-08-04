#include <iostream>
#include <string>
using namespace std;

double tinhHieuXuat(int a,int b){
    if(a==0||b==0)
    throw 123;
    if(a<0||b<0)
    throw string{"abc"};

    return (double)a/(double)b;
}

int main(){
    int caySoDiDuoc=125;
    int litXangTieuThu=2;
    double hieuXuatXe;

    try
    {
        hieuXuatXe = tinhHieuXuat(caySoDiDuoc,litXangTieuThu);
        cout<<"\nHieu xuat xe dat muc: "<<hieuXuatXe<<" km/l"<<endl;
    }
    catch(...)
    {
        cout<<"So lieu nhap vao sai !!!"<<endl;
    }
    
    cout<<"\ncode da chay het\n"<<endl;
}