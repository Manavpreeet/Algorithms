#include<bits/stdc++.h>
#include<string>

using namespace std;

int cutRod(int price[], int rod){
    int T[rod + 1];

    for(int i=0; i<= rod; i++)
        T[i] = 0;
    
    for(int i=1; i <= rod; i++){
        for(int j=0; j <= i; j++){
            T[i] = max(T[i], price[j - 1] + T[i - j]);
        }
    }

    return T[rod];
}

int main(){
    int length[] = {1,2,3,4,5,6,7,8};
    int price[] = {1,5,8,9,10,17,17,20};

    // Length of rod
    int rod = 4;

    cout << cutRod(price, rod) << endl;
}