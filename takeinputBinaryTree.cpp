#include <bits/stdc++.h>
#include <iostream>
using namespace std;


template<typename T>
class node{
    public:
    	T data;
    	node *left;
    	node *right;
    
        node(T data){
            this->data= data;
            left= NULL;
            right= NULL;
        }
};

node<int>* takeinput(){
    int nodedata;
    cin>>nodedata;
    
    if(nodedata== -1){
        return NULL;
    }
    
    node<int>* newnode = new node<int> (nodedata);
    node<int>* left = takeinput();
    node<int>* right = takeinput();
    
    newnode->left = left;
    newnode->right = right;
    
    
    return newnode;
    
}

void print(node<int>* root){
    if(!root){
        return;
    }
    cout<<root->data<<":";
    if(root->left){
        cout<<root->left->data<<",";
    }
    if(root->right){
        cout<<root->right->data;
    }
    cout<<endl;
    
    print(root->left);
    print(root->right);
    
}

int main()
{
	node<int>* root = takeinput();
    print(root);
	return 0;
}