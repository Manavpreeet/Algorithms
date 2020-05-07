#include<iostream>
#include<bits/stdc++.h>
#define MAX 100000000
using namespace std;
int arr[MAX], n;

class merge_sort{
public:
    void getData();
    void merge(int arr[], int p, int q, int r);
    void sort(int arr[], int p , int r);
    void display(int arr[]);
};

void merge_sort::merge(int arr[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for(int i=0; i<n1; i++)
        L[i] = arr[p + i];

    for(int i=0; i<n2; i++)
        R[i] = arr[q + i + 1];

    int i, j, k = p;
    i = j = 0;

    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
        
}

void merge_sort::getData(){
    cout<<"Enter number of elements: ";
    cin>> n;

    for (int i = 0; i < n ; ++i) {
        cin >> arr[i];
    }
}

void merge_sort::display(int arr[]){
    for (int i = 0; i < n; ++i) {
       cout << arr[i] << " ";
    }
    cout << endl;
}

void merge_sort::sort(int arr[], int p , int r){
    if(p < r){
        int q = (p+r)/2;

        sort(arr, p, q);
        sort(arr, q + 1, r);
        merge(arr,p,q,r);
    }

}

int main(int argc, char const *argv[])
{
    merge_sort mergeSort;
    mergeSort.getData();
    mergeSort.sort(arr, 0, n-1);
    mergeSort.display(arr);
}
