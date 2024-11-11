// Problem 3: Bill Division (3 points)
// Two friends, Ti and Teo, are deciding how to split the bill at a dinner. Each will only pay for
// the items they consume. Teo gets the check and calculates Ti’s portion. You must determine if
// his calculation is correct.
// For example, assume the bill has the following prices: bill = [2, 4, 6]. Ti declines to eat item k
// = bill[2] which costs 6. If Teo calculates the bill correctly, Ti will pay (2 + 4) / 2 = 3. If he
// includes the cost of bill[2], he will calculate (2 + 4 + 6) / 2 = 6. In the second case, he should
// refund 3 to Ti.
// Input: The first line contains two space-separated integers n and k, the number of items
// ordered and the 0-based index of the item that Ti did not eat.
// The second line contains n space-separated integers bill[i] (0 ≤ i < n).
// 2
// The third line contains an integer, b, the amount of money that Teo charged Ti for his share of
// the bill.
// Output: If Teo did not overcharge Ti, print Bon Appetit on a new line; otherwise, print the
// difference that Teo must refund to Ti.

#include <iostream>

using namespace std;

int main(){
    int tongBill, tiBill, reFun, n1, n2;
    cin>>n1>>n2;
    int menu[n1];
    for(int i=0; i<n1; i++){
        cin>>menu[i];
    }
    cin>>tiBill;

    auto tinhToan = [&](){
        int sum = 0;
        for(int i=0; i<n1; i++){
            sum+=menu[i];
        }
        reFun = tiBill - (sum/2 - menu[n2]);
        if(reFun>0){
            cout<<"Tra lai "<<tiBill-reFun<<endl;
        }
        else{
            cout<<"Chuc ngon mieng"<<endl;
        }
    };

    tinhToan();

}