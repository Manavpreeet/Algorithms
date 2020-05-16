// TIME COMPLEXITY IS N*LOG(N) IN WORST CASE
#include <iostream>

using namespace std;
// This function find the sum of first n elements of array.
int getSum(int BITree[], int index){
    int sum = 0;
    index = index + 1;
    while(index > 0){
        sum += BITree[index];
        index -= index & (-index);
    }

    return sum;
}

// This function adds the value and update the correspondong linked index
void updateBIT(int BITree[], int n, int index, int element){
    index = index + 1;

    while( index <= n){
        BITree[index] += element;
        index += index & (-index);
    }
}

// This function create a BITree
int *constructBITree(int arr[], int n){
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
 
    for (int i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
    return BITree; 
} 

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int *BITree = constructBITree(arr, n);
    cout << getSum(BITree,4) << endl;
}