#include <iostream>
#include <cstdlib>

using namespace std;

void meoBatChuot(int x, int y, int z){
    int l1 = abs(z-x);
    int l2 = abs(z-y);
    if(l1 < l2){
        cout<<"Con meo A bat duoc chuot"<<endl;
    }
    if(l1 > l2){
        cout<<"Con meo B bat duoc chuot"<<endl;
    }
    if(l1==l2){
        cout<<"Chuot chay mat cmnr :V"<<endl;
    }
}

int main(){
    int n;
    cout<<"n= ";
    cin>>n;
    for(int u=1; u<=n; u++){
    int a,b,c;
    cin>>a>>b>>c;
    meoBatChuot(a,b,c);
    }
}