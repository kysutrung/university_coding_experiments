#include <bits/stdc++.h>
using namespace std;

//Problem 2: Handshakes at the Party

long long tinhToHop(int N, int K){
    long double result = 1.0;
    for (int i = 1; i <= K; ++i){
        result *= (N - K + i);
        result /= i;
    }
    return round(result); //hàm tính làm tròn
}

int main(){
    int N;
    cin >> N;
    long long soLanBatTay = tinhToHop(N, 2);
    cout<<soLanBatTay;
}