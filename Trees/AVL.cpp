#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* left;
        int data;
        Node* right;
        int height;
        // will need height of each node to calculate balanced factor
};

class AVL{
    public:
        Node* root;

        AVL(){ root = NULL; }

        // Helper Methods for Inserting
        int NodeHeight(Node* p);
        int BalanceFactor(Node* p);
        Node* LLRotation(Node* p);
        Node* RRRotation(Node* p);
        Node* LRRotation(Node* p);
        Node* RLRotation(Node* p);

        // Recursive Insert
        // Creating AVL Tree
        Node* rInsert(Node* p, int key);

        // Traversal
        void Inorder(Node* p);
};

int AVL::NodeHeight(Node* p){
    int hl, hr;    // height-left , height-right

    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->height : 0;

    return max(hl, hr) + 1;
}

int AVL::BalanceFactor(Node* p){
    int hl, hr;

    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->data : 0;

    return hl-hr;
}

Node* AVL::LLRotation(Node* p){
    Node* pl = p->left;
    Node* plr = pl->right;

    // rotation
    pl->right = p;
    p->left = plr;

    // update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // update root
    if(root = p){
        root = pl;
    }

    return pl;
}

Node* AVL::LRRotation(Node* p){
    return NULL;
}

Node* AVL::RRRotation(Node* p){
    
}

Node* AVL::RLRotation(Node* p){
    return NULL;
}

// CREATING AVL TREE

Node* AVL::rInsert(Node* p, int key){
    Node* t;

    if(p==NULL){
        t = new Node;
        t->data = key;
        t->left = t->right = NULL;
        t->height = 1;  // Starting height from 1 onwards instead of 0
        return t;
    }

    if(key < p->data){
        p->left = rInsert(p->left, key);
    }else if(key > p->data){
        p->right = rInsert(p->right, key);
    }

    // update height
    p->height = NodeHeight(p);

    // Balance Factor & Rotation
    if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1){
        return LLRotation(p);
    }else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1){
        return LRRotation(p);
    }else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1){
        return RRRotation(p);
    }else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1){
        return RLRotation(p);
    }

    return p;
}

void AVL::Inorder(Node* p){
    if(p){
        Inorder(p->left);
        cout<<p->data<<" ";
        Inorder(p->right);
    }
}

int main(){
    
    // LL Rotation
    AVL t;
    t.root = t.rInsert(t.root, 30);
    t.rInsert(t.root, 20);
    t.rInsert(t.root, 10);

    t.Inorder(t.root);
    cout<<endl;

    // RR Rotation
    AVL tr;
    tr.root = tr.rInsert(tr.root, 10);
    tr.rInsert(tr.root, 20);
    tr.rInsert(tr.root, 30);

    tr.Inorder(tr.root);
    cout<<endl;

    return 0;
}