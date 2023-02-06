#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* left;
        int data;
        Node* right;

        Node(){
            this->left = this->right = NULL;
        }
};

class Tree{
    public:
        Node* root;

        Tree(){
            root = NULL;
        }

        void PreOrder(Node* p);

        Node* Search(Node* t, int key);
        Node* IterSearch(Node* t, int key);

        void Insert(int key);
        Node* RecInsert(Node* p, int key);

        Node* Delete(Node* p, int key);
        int height(Node* p);
        Node* InPre(Node* p);
        Node* InSucc(Node* p);

        void BSTfromPreOrder(int arr[], int n);
};

void Tree::PreOrder(Node* p){
    if(p){
        cout<<p->data<<" ";
        PreOrder(p->left);
        PreOrder(p->right);
    }
}

// Searching in a BST
Node* Tree::Search(Node* t, int key){
    if(t==NULL) return NULL;

    if(t->data == key) return t;
    else if(t->data > key) return Search(t->left, key);
    else return Search(t->right, key);
}

Node* Tree::IterSearch(Node* t, int key){
    while(t!=NULL){
        if(t->data == key) return t;
        else if(t->data > key) t=t->left;
        else t=t->right;
    }
    return NULL;            // key not found
}

// CREATING A BST (Inserting a new Node in BST)
void Tree::Insert(int key){
    Node* t = root;
    Node *r, *p;

    // if it is the first node to be inserted
    if(root==NULL){
        p = new Node;
        p->data = key;
        p->left = p->right = NULL;
        root = p;
        return;
    }
    // search kro or insert krdo
    while(t!=NULL){
        r = t;
        if(key < t->data) t=t->left;
        else if(key > t->data) t=t->right;
        else return;        // means agr phle se present hai toh kuch ni krna
    }
    // correct position pe lga do element
    p = new Node;
    p->data = key;
    p->left = p->right = NULL;

    if(key < r->data) r->left = p;
    else r->right = p;
}

// Recursive Insert (also, creating tree with it)
Node* Tree::RecInsert(Node* p, int key){
    Node* t;
    if(p==NULL){
        t = new Node;
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }

    if(key < p->data) p->left = RecInsert(p->left, key);
    else if(key > p->data) p->right = RecInsert(p->right, key);

    return p;
}

int Tree::height(Node* p){
    if(p==NULL) return 0;
    int x = height(p->left);
    int y = height(p->right);
    return x>y ? x+1 : y+1;
}

// InOrder Predecessor: rightmost ele of left subtree
// left jaake right right right
// yha hum logon ne pass hi p->left krdiya hai Delete() me

Node* Tree::InPre(Node* p){
    while(p && p->right) p=p->right;
    return p;
}

Node* Tree::InSucc(Node* p){
    while(p && p->left) p=p->left;
    return p;
}

Node* Tree::Delete(Node* p, int key){
    if(p==NULL) return NULL;

    // if it is a leaf node
    if(p->left==NULL && p->right==NULL){
        if(p==root) root=NULL;      // if the node to be deleted is a root node
        delete p;
        return NULL;      // no node left
    }

    // otherwise search and delete
    if(key < p->data){
        p->left = Delete(p->left, key);
    }else if(key > p->data){
        p->right = Delete(p->right, key);
    }else{
        if(height(p->left) > height(p->right)){
            Node* q = InPre(p->left);     // take inOrder Predecessor
            p->data = q->data;            // Replace its value with inOrder Predecessor
            p->left = Delete(p->left, q->data);     // ab us InPre ko jaake delete krdo
        }else{
            Node* q = InSucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }
    return p;
}

void Tree::BSTfromPreOrder(int arr[], int n){
    // create root node
    int i = 0;
    root = new Node();
    root->data = arr[i++];

    // Iterative Steps
    Node *t;
    Node *p = root;
    stack<Node*> s;

    while(i<n){
        // left child case
        if(arr[i] < p->data){
            t = new Node();
            t->data = arr[i++];
            p->left = t;
            s.push(p);
            p = t;
        }else{
            // right child case
            // it should be within range
            // agr stack empty hai toh infinte lelo vrna stack ke top element ka data
            if(arr[i] > p->data && arr[i] < s.empty()? 32767 : s.top()->data){
                t = new Node();
                t->data = arr[i++];
                p->right = t;
                p = t;
            }else{
                p = s.top();         // stack se top element nikalo or p usko point krado
                s.pop();
            }
        }
    }
} 

int main(){
    Tree t;

    int arr[] = {10,5,20,8,30};
    // for(int i:arr){
    //     t.Insert(i);
    // }
    for(int i=0; i<5; i++){
        t.Insert(arr[i]);
    }

    cout<<"Inserting: ";
    t.PreOrder(t.root);
    cout<<endl;

    cout<<"Searching: ";
    Node* temp = t.Search(t.root, 30);

    if(temp==NULL) cout<<"Key not found!";
    else cout<<temp->data<<endl;

    // Node* newRoot = NULL;
    // newRoot = t.RecInsert(newRoot, 10);
    // t.PreOrder(newRoot);

    // t.Delete(t.root, 10);
    // t.PreOrder(t.root);

    int arr2[] = {30,20,10,15,25,40,50,45};
    int n = sizeof(arr2)/sizeof(arr2[0]);

    t.BSTfromPreOrder(arr2, n);
    t.PreOrder(t.root);

    return 0;
}