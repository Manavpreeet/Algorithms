#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node *left;
        node *right;
};

node* newNode(int data){

    node* temp = new node();

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node* insertNode(int data, node* root){

    if(root == NULL){
        node* n = new node();
        n->data = data;
        n->left = n->right = NULL;
        return n;
    }

    if(data <= root->data)
        root->left = insertNode(data, root->left);
    else root->right = insertNode(data, root->right);

    return root;
}

node* constructTree(int arr[], int size){
    
    node* root = new node();
    root->data = arr[0];
    root->left = root->right = NULL;

    for(int i = 1; i < size; i++)
        root = insertNode(arr[i], root);
    
    return root;
}

void inorderTraversal(node* root){

    if(root){
        inorderTraversal(root->left);
        cout << root->data << endl;
        inorderTraversal(root->right);
    }
}

void postorderTraversal(node* root){

    if(root){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << endl;
    }
}

void preorderTraversal(node* root){

    if(root){
        cout << root->data << endl;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main(){

    int arr[] = {5,4,3,2,1,6,7,8,9,10};
    int size = 10;

    node* root = constructTree(arr, size);
    inorderTraversal(root);
}