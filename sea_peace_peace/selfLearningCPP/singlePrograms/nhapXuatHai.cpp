#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string text1 = "Meo meo meo meo";
    fstream  fileVao;
    fileVao.open("file1.txt",ios::app);

    if(fileVao.is_open()){
        cout<<"Mo phai thanh cong"<<endl;
    }
    fileVao<<endl<<text1;
    fileVao.close();

}