#include <bits/stdc++.h>
using namespace std;

//Problem 1: Length Discrepancy

int main(){
    string a, b;
    getline(cin,a);
    getline(cin,b);
    int n1, n2, n3;
    n1 = a.length();
    n2 = b.length();
    n3 = abs(n1-n2);
    cout<<n3;
}