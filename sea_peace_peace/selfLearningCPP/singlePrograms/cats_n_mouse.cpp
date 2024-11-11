// Problem 1: Cats and a Mouse
// Two cats and a mouse are at various positions on a line. You will be given their starting
// positions. Your task is to determine which cat will reach the mouse first, assuming the mouse
// does not move and the cats travel at equal speed. If the cats arrive at the same time, the
// mouse will be allowed to move and it will escape while they fight.
// You are given q (1 ≤ q ≤ 100) queries in the form of x y z (1 ≤ x, y, z ≤ 100) representing
// the respective positions for cats A and B, and for mouse C. Complete the function
// catAndMouse to return the appropriate answer to each query, which will be printed on a new
// line.
// If cat A catches the mouse first, print Cat A.
// If cat B catches the mouse first, print Cat B.
// If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse
// escapes.

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