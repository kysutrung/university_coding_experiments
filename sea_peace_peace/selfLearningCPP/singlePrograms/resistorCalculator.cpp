//chương trình tính giá trị điện trở theo dữ liệu màu tương ứng vòng nhập vào
#include <bits/stdc++.h>
using namespace std;

int numBersOfBand;
int band01;
int band02;
int band03;
int band04;
int band05;
long resistanceValue = 0;
float tolerance = 0;

void tinhDienTro(){
    cout<<"\n=========Resistance Calculator=========\n";
    while(numBersOfBand != 5 && numBersOfBand != 4){
        cout<<"\nHow many bands? ";
        cin>>numBersOfBand;
    }

    if(numBersOfBand == 4){
        cout<<"\nFirst band:"<<endl;
        cout<<"\n1 - Black"<<endl;
        cout<<"2 - Brown"<<endl;
        cout<<"3 - Red"<<endl;
        cout<<"4 - Orange"<<endl;
        cout<<"5 - Yellow"<<endl;
        cout<<"6 - Green"<<endl;
        cout<<"7 - Blue"<<endl;
        cout<<"8 - Violet"<<endl;
        cout<<"9 - Gray"<<endl;
        cout<<"10 - White"<<endl;
        cout<<"\nEnter color of this band: ";

        cin>>band01;

        cout<<"\nSecond band:"<<endl;
        cout<<"\n1 - Black"<<endl;
        cout<<"2 - Brown"<<endl;
        cout<<"3 - Red"<<endl;
        cout<<"4 - Orange"<<endl;
        cout<<"5 - Yellow"<<endl;
        cout<<"6 - Green"<<endl;
        cout<<"7 - Blue"<<endl;
        cout<<"8 - Violet"<<endl;
        cout<<"9 - Gray"<<endl;
        cout<<"10 - White"<<endl;
        cout<<"\nEnter color of this band: ";

        cin>>band02;
        
        cout<<"\nThird band:"<<endl;
        cout<<"\n1 - Black"<<endl;
        cout<<"2 - Brown"<<endl;
        cout<<"3 - Red"<<endl;
        cout<<"4 - Orange"<<endl;
        cout<<"5 - Yellow"<<endl;
        cout<<"6 - Green"<<endl;
        cout<<"7 - Blue"<<endl;
        cout<<"8 - Violet"<<endl;
        cout<<"9 - Gray"<<endl;
        cout<<"10 - White"<<endl;
        cout<<"11 - Gold"<<endl;
        cout<<"12 - Silver"<<endl;
        cout<<"\nEnter color of this band: ";

        cin>>band03;

        cout<<"\nFourth band:"<<endl;
        cout<<"1 - Brown"<<endl;
        cout<<"2 - Red"<<endl;
        cout<<"3 - Orange"<<endl;
        cout<<"4 - Yellow"<<endl;
        cout<<"5 - Green"<<endl;
        cout<<"6 - Blue"<<endl;
        cout<<"7 - Violet"<<endl;
        cout<<"8 - Gray"<<endl;
        cout<<"9 - Gold"<<endl;
        cout<<"10 - Silver"<<endl;
        cout<<"11 - None"<<endl;
        cout<<"\nEnter color of this band: ";

        cin>>band04;

        switch(band01){
            case 1:
                resistanceValue += 0;
                break;
            case 2:
                resistanceValue += 10;
                break;
            case 3:
                resistanceValue += 20;
                break;
            case 4: 
                resistanceValue += 30;
                break;
            case 5:
                resistanceValue += 40;
                break;
            case 6:
                resistanceValue += 50;
                break;
            case 7:
                resistanceValue += 60;
                break;
            case 8:
                resistanceValue += 70;
                break;
            case 9:
                resistanceValue += 80;
                break;
            case 10:
                resistanceValue += 90;
                break;
        }

        switch(band02){
            case 1:
                resistanceValue += 0;   
                break;
            case 2:
                resistanceValue += 1;
                break;
            case 3:
                resistanceValue += 2;
                break;
            case 4: 
                resistanceValue += 3;
                break;
            case 5:
                resistanceValue += 4;
                break;
            case 6:
                resistanceValue += 5;
                break;
            case 7:
                resistanceValue += 6;
                break;
            case 8:
                resistanceValue += 7;
                break;
            case 9:
                resistanceValue += 8;
                break;
            case 10:
                resistanceValue += 9;
                break;
        }

        switch(band03){
            case 1:
                resistanceValue *= 1;
                break;
            case 2:
                resistanceValue *= 10;
                break;
            case 3:
                resistanceValue *= 100;
                break;
            case 4: 
                resistanceValue *= 1000;
                break;
            case 5:
                resistanceValue *= 10000;
                break;
            case 6:
                resistanceValue *= 100000;
                break;
            case 7:
                resistanceValue *= 1000000;
                break;
            case 8:
                resistanceValue *= 10000000;
                break;
            case 9:
                resistanceValue *= 100000000;
                break;
            case 10:
                resistanceValue *= 1000000000;
                break;
            case 11:
                resistanceValue /= 10;
                break;
            case 12:
                resistanceValue /= 100;
                break;
        }

        switch(band04){
            case 1:
                tolerance = 1;
                break;
            case 2:
                tolerance = 2;
                break;
            case 3:
                tolerance = 3;
                break;
            case 4: 
                tolerance = 4;
                break;
            case 5:
                tolerance = 0.5;
                break;
            case 6:
                tolerance = 0.25;
                break;
            case 7:
                tolerance = 0.10;
                break;
            case 8:
                tolerance = 0.05;
                break;
            case 9:
                tolerance = 5;
                break;
            case 10:
                tolerance = 10;
                break;
            case 11:
                tolerance = 20;
                break;
        }

        cout<<"\nValue: "<<resistanceValue<<" Tolerance: +-"<<tolerance<<"%"<<endl;
    }
    else{
        cout<<"\nI dont know how to value this type :)\n";
    }
}

int main(){
    tinhDienTro();
}