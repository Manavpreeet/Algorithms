#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int findPeek(int arr[], int low, int high, int n){

    int mid = (low + high)/2;

    if((mid == 0 || arr[mid - 1] <= arr[mid]) &&  
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))  
        return arr[mid]; 

    if(arr[mid] < arr[mid - 1] && mid > 0)
        return findPeek(arr, 0, mid - 1, n);
    else return findPeek(arr, mid + 1, high, n);
}

int main(){
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[100];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << findPeek(arr,0,n -1,n) << endl;
}