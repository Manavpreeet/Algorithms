#include<bits/stdc++.h>
#include<iostream>
#define MAX 1000000
using namespace std;

class insertion_sort{

    int arr[MAX], n;
public:
    void getData();
    void display();
    void sort();

};

void insertion_sort::sort(){
    
    for(int j = 1; j < n; j++){
        int key = arr[j];
        int i = j - 1;
        while( i >= 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }

}

void insertion_sort::display(){

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

}

void insertion_sort::getData(){

    cout << "Enter the number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

int main(){

    insertion_sort insort;
    insort.getData();
    insort.sort();
    insort.display();

}