// Problem 4: Special of Zero (1.5 points)
// In the realm of numbers from 0 to 9, the number 0 holds a special significance. If the zero
// disappears in this world. What would happen?
// Consider a simple example: 101 + 102 = 203. If we remove all the zeros, we get 11 + 12 =
// 23, and the addition still holds true. However, with the addition of 104 + 33 = 137, removing
// the zeros results in 14 + 33 = 137, and this calculation is incorrect.
// Your task is to determine, given two integers a and b, whether after performing the addition
// and removing all zeros, the result is still correct.
// Input: Two lines containing two integers a and b ( 1 ≤ a, b ≤ 109)
// Output: Print "YES" if after removing all zeros the addition result is correct, and "NO"
// otherwise.

#include <bits/stdc++.h>
using namespace std;

//Problem 4: Special of Zero

void xacNhan(string a, string b){
    string x = a;
    string y = b;

    int x2 = stoi(x); //hàm chuyển từ string sang int
    int y2 = stoi(y);
    int sum1 = x2 + y2;
    string strsum1 = to_string(sum1);//hàm chuyển từ int sang string

    int len1 = x.length();
    for(int i=0; i<len1; i++){
        if(x[i]=='0'){
            x.erase(i,1);
        }
    }

    int len2 = y.length();
    for(int i=0; i<len2; i++){
        if(y[i]=='0'){
            y.erase(i,1);
        }
    }

    int len3 = strsum1.length();
    for(int i=0; i<len1; i++){
        if(strsum1[i]=='0'){
            strsum1.erase(i,1);
        }
    }

    int x3 = stoi(x);
    int y3 = stoi(y);
    int sum3 = x3 + y3;
    int sum2 = stoi(strsum1);

    if(sum2 != sum3){
        cout<<"NO"<<endl;
    }
    if(sum2 == sum3){
        cout<<"YES"<<endl;
    }
}

int main(){
    string a1, b1;
    cin>>a1>>b1;
    string a2, b2;
    cin>>a2>>b2;

    xacNhan(a1,b1);
    xacNhan(a2,b2);
} 