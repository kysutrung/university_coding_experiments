#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int tinhTienSoChan(int x, int y, int z){
    int i=x,j=y,k=z;
    int soTien1;

    if(j<k){
       soTien1 = i*j;
    }
    if(j>k){
        soTien1 = (i/2)*k;
    }

    return soTien1;
}

int tinhTienSoLe(int x, int y, int z){
    int i=x,j=y,k=z;
    int soTien1,soTien2;

    if(j<k){
        soTien1 = i*j;
    }
    if(j>k){
        soTien1 = ((i-1)/2)*k + j;
    }
    return soTien1;
}

int main(){
    int a,b,c;
    int gia1, gia2;
    cin>>c;
    cin>>a>>b;
    
    if(c%2 == 0){
        cout<<tinhTienSoChan(c,a,b)<<endl;
    }
    if(c%2!=0){
        cout<<tinhTienSoLe(c,a,b)<<endl;
    }
    
}