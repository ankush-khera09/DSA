#include<iostream>
#include<bits/stdc++.h>
using namespace std;


Node* Delete(Node* p, int key){
    if(p==NULL) return NULL;

    if(p->left==NULL && p->right==NULL){
        if(p==root) root=NULL;
        delete p;
        return NULL;
    }

    if(key < p->data){
        p->left = Delete(p->left, key);
    }else if(key > p->data){
        p->right = Delete(p->right, key);
    }else{
        if(height(p->left) > height(p->right)){
            Node* q = InPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }else{
            Node* q = InPre(p->right);
            p->data = q->data;
            p->left = Delete(p->right, q->data);
        }
    }
    return p;
}


Node* InPre(Node* p){
    while(p && p->right) p=p->right;
    return p;
}


int main(){
    
cout<<"HEJKRK";
    return 0;
}