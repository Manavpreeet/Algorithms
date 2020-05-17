#include <iostream>
#include <bits/stdc++.h>
int tree[200000], a[200000], b[200000],n; 
using namespace std;

void update(int index, int val){
    while(index <= n){
        tree[index] += val;
        index += index & (-index);
    }
}

int query(int index){
    int sum = 0;
    while( index > 0){
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

int main(){
    cout << "Enter the number of elements: ";
    cin >> n;

    memset(tree,0,sizeof(tree));
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    for(int i=0; i<n; i++){
        int d = lower_bound(b, b+n, a[i]) - b;
        a[i] = d + 1;
    }

    int ans=0;
    for(int i=n-1; i>=0; i--){
        ans = ans + query(a[i] - 1);
        update(a[i], 1);
    }

    cout << ans << endl;
}