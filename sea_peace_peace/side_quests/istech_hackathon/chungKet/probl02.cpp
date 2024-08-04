#include <iostream>
#include <string>
using namespace std;


int main() {
    string str1;
    int numArr[11];
    cin >> str1;
    int len1 = str1.length();
    
    for (int i = 0; i < len1; i++) {
        numArr[i] = str1[i]- '0';
    }

    //tinh tong
    int sum=0;
    
    for(int i=0; i<len1; i++){
        sum += numArr[i];
    }
    sum+=stoi(str1);
    
    


    cout<<sum<<endl;
}