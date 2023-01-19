#include<iostream>
#include<bits/stdc++.h>
#include "QueueClass.h"

using namespace std;

class Tree{
    public:
        Node* root;

        Tree(){
            root = NULL;
        }

        void CreateTree();
};

void Tree::CreateTree(){
    Node *p, *t;     // temporary pointers
    int x;
    Queue q(100);       // object of Queue class
    
    cout<<"Enter Root Value: ";
    cin>>x;
    
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty()){
        // queue se ek node pointer bhar nikala
        p = q.dequeue();

        // usse pucha if uska left child hai
        cout<<"Enter left child of "<<p->data<<" : ";
        cin>>x;

        // if left child exists
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;      // p ke lchild ko isse point kra diya
            q.enqueue(t);       // lchild ke address ko queue me daal diya
        }

        // Asking if right child exists
        cout<<"Enter right child of "<<p->data<<" : ";
        cin>>x;

        // if right child exists
        if(x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;      // p ke lchild ko isse point kra diya
            q.enqueue(t);       // lchild ke address ko queue me daal diya
        }
    }
}

int main(){
    
    Tree t;
    t.CreateTree();

    return 0;
}