#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
struct hienThi{
    void operator() (const T&data){
        cout<<data<<endl;
    }
};

int main(){
    hienThi<int> h1;
    h1(100);
    vector<int> vec1{1,3,5,7,9,11};
    for_each(vec1.begin(),vec1.end(),h1);
    transform(vec1.begin(),vec1.end(),vec1.begin(),[](int x){return x*x;});
    //[](int x){return x*x;}) cai nay la bieu thuc lamda
    for_each(vec1.begin(),vec1.end(),h1);
}