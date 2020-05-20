#include<iostream>
#include<cmath>
#define Q 1.61803
using namespace std;

//  This function calculates nth fibonacci number using Stirling's approximation.
//                             | Q^n        1 |
//                     F(n) =  |----    +  ---|
//                             |_ sqrt(5)   2_| 

int fibonaacciNumber(int n){
    return ( floor( (pow(Q, n)/sqrt(5)) + 0.5 ) );
}

int main(){
    int n;
    cout << "Enter the nth number you want: ";
    cin >> n;

    cout << fibonaacciNumber(n) << endl;
}