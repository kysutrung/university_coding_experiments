// Problem 1: Length Discrepancy (2.5 points)
// Given two strings a and b. Print out the difference in length between the two strings.
// Input: The first line is the string a. The second line is the string b.
// Output: One line print the number to find.

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