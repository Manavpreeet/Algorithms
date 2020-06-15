#include<bits/stdc++.h>
using namespace std;

class HashTable{

    public:
        int value;
        int key;

        HashTable(int key, int value){
            this->key = key;
            this->value = value;
        }
};

class HashMap{

    

    public:

        HashTable **arr;
        int capacity = 20;
        int size = 10;
        HashTable *dummy;

        HashMap(){
            this->capacity = capacity;
            this->size = size;

            arr = new HashTable*[capacity];

            for(int i=0; i < capacity; i++)
                arr[i] = NULL;

            dummy = new HashTable(-1, -1);
        }

        int hash(int key){
            return key % capacity;
        }

        void insetNode(int key, int value){
            HashTable *temp = new HashTable(key, value);
            int hashIndex = hash(key);

            while(arr[hashIndex] != NULL && arr[hashIndex]->key != key
                && arr[hashIndex]->key == key){
                    hashIndex++;
                    hashIndex %= capacity;
                }
                 
            if(arr[hashIndex]==NULL || arr[hashIndex]->key == -1){
                size++;
                arr[hashIndex] = temp;
            }
        }

        void display(){
            for(int i = 0; i < capacity; i++){
                if(arr[i] != NULL && arr[i])
                    cout << "key: " << arr[i]->key 
                            << "value: " << arr[i]->value << endl;
            }
        }
};

int main(){

    HashMap *hashtable = new HashMap;
    hashtable->insetNode(1,1);
    hashtable->insetNode(12,2);
    hashtable->insetNode(13,3);
    hashtable->insetNode(14,5);
    hashtable->insetNode(18,9);
    hashtable->display();

}

