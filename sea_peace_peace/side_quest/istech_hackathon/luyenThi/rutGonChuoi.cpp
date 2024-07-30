#include <iostream>
#include <string>
using namespace std;

//từ aabbbccd thành bd

int main(){
    string str1 = "";
    cin>>str1;
    int len1 = str1.length();
    bool daXong = 0;

    while(daXong==0){
        for(int i = 0; i<len1; i++){
     if(str1[i] == str1[i+1]){
        str1.erase(i,2);
     }
    }
    int dem = 0;
    for(int i = 0; i<len1; i++){
        if(str1[i] == str1[i+1]){
            dem++;
        }
    }
    if(dem==0){
        daXong = 1;
    }
    }
    int len2 = str1.length();
    if(len2==0){
        cout<<"iem ti"<<endl;
    }
    else{
    cout<<str1<<endl;

    }
}