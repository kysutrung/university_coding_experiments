#include <iostream>

using namespace std;

int main(){
    int tongBill, tiBill, reFun, n1, n2;
    cin>>n1>>n2;
    int menu[n1];
    for(int i=0; i<n1; i++){
        cin>>menu[i];
    }
    cin>>tiBill;

    auto tinhToan = [&](){
        int sum = 0;
        for(int i=0; i<n1; i++){
            sum+=menu[i];
        }
        reFun = tiBill - (sum/2 - menu[n2]);
        if(reFun>0){
            cout<<"Tra lai "<<tiBill-reFun<<endl;
        }
        else{
            cout<<"Chuc ngon mieng"<<endl;
        }
    };

    tinhToan();

}