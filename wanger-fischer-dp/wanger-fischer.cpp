#include<iostream>
#include<bits/stdc++.h>
#include <string>

using namespace std;

int min(int a, int b) {
   return (a < b) ? a : b;
}

int minimumLength(string a, string b){
    int m = a.length(), n = b.length(), substitutionCost = 0;
    int dp[m+1][n+1],temp;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m ; i++)
        dp[i][0] = i;
    for (int i = 1; i <= n; i++)
        dp[0][i] = i;

    for (int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i -1] == b[j - 1])
                substitutionCost = 0;
            else 
                substitutionCost = 1;
        
        temp = min((dp[i-1][j]+1),(dp[i][j-1]+1));
        dp[i][j] = min(temp,(dp[i-1][j-1]+substitutionCost));
        }
    }
    return dp[m][n];
    
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string a,b;
        cin >> a >> b;

        cout << minimumLength(a,b)<<endl;
    }
}