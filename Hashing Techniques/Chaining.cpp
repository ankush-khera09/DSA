#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{                // Linked List Node
    public:
        int data;
        Node* next;
};

class HashTable{
    public:
        Node** HT;
        HashTable();                     // Constructor
        int hash(int key);               // Hash Function
        void Insert(int key);            // Insert keys
        int Search(int key);             // For searching a key
        int Remove(int key);             // For deleting a key
        ~HashTable();                    // Destructor
};

HashTable::HashTable(){
    HT = new Node*[10];
    for(int i=0; i<10; i++){                  // Initialising HT indices to NULL
        HT[i] = NULL;
    }
}

int HashTable::hash(int key){
    return key%10;                           // h(x) = x%10
}

void HashTable::Insert(int key){
    int hIdx = hash(key);                   // Hash Index

    Node *t = new Node;                     // Creating Node & setting key in it;
    t->data = key;
    t->next = NULL;

    if(HT[hIdx] == NULL){                   // Case: No nodes in LL
        HT[hIdx] = t;                       // Point it to our node
    }else{                                  // else insert node in sorted manner
        Node* p = HT[hIdx];
        Node* q = HT[hIdx];

        while(p && p->data < key){        // Move on till the ele are < key to find the insert position
            q=p;
            p=p->next;
        }

        if(q == HT[hIdx]){                   // Insert at first of the LL
            t->next = HT[hIdx];
            HT[hIdx] = t;
        }else{                                 // Insert at the found position
            t->next = q->next;
            q->next = t;
        }
    }
}

int HashTable::Search(int key){
    int hIdx = hash(key);
    Node* p = HT[hIdx];
    while(p){
        if(p->data == key) return p->data;
        p=p->next;
    }
    return -1;              // if key not found
}

int HashTable::Remove(int key){            // Coded by me myself....maybe some mistake would be there
    int x = -1;                            // will return key to be deleted
    int hIdx = hash(key);
    Node* p = HT[hIdx];

    if (p == NULL){                        // if there is no Node pointed to HT
        return x;
    }

    if(p->data == key){                   // if we have to delete first node
        HT[hIdx] = HT[hIdx]->next;
        x = p->data;
        delete p;
        return x;
    }else{
        Node* p = HT[hIdx];
        Node* q = NULL;

        while(p->data != key){               // else move to the position where node is to be deleted
            q=p;
            p=p->next;
        }

        q->next = p->next;
        x = p->data;
        delete p;
    }

    return x;
}

HashTable::~HashTable(){
    for(int i=0; i<10; i++){
        Node* p = HT[i];
        while(HT[i]){
            HT[i] = HT[i]->next;
            delete p;
            p=HT[i];
        }
    }
    delete []HT;
}

int main(){
    
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    HashTable H;                       // Object of class HashTable
    for(int i=0; i<n; i++){           // Inserting elements of array in HashTable
        H.Insert(arr[i]);
    }

    int key = 4;
    cout<<"Key Found: "<<H.Search(key)<<endl;

    cout<<"Deleted key: "<<H.Remove(key)<<endl;

    return 0;
}