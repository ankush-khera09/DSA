#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first=NULL;

void Insert(Node *p, int x){
    Node *t = new Node;
    t->data = x;
    t->next = NULL;

    if(first==0){
        first = t;
    }else{
        while(p->next){
            p=p->next;
        }
        p->next = t;
    }
}

void display(Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

// Node* findMid(Node *p){
//     Node *q = first;
//     while(q){
//         q=q->next;
//         if(q) q=q->next;
//         if(q) p=p->next;
//     }
//     return p;
// }

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

Node* mergeTwo(Node *left, Node *right){
    if(left==NULL) return right;
    if(right==NULL) return left;

    Node *dummy = new Node;
    dummy->data = -1;
    Node *last = dummy;

    while(left&&right){
        if(left->data < right->data){
            last->next = left;
            last = left;
            left=left->next;
        }else{
            last->next = right;
            last = right;
            right=right->next;
        }
    }

    if(left) last->next = left;
    else last->next = right;

    return dummy->next;
}

Node* mergeSort(Node *p){
    if(first==NULL || first->next==NULL) return first;
    
    Node *mid = findMid(p);
    
    Node *left = first;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node *ans = mergeTwo(left, right);

    return ans;
}

int main(){
    int arr[] = {3,4,2,5,1};
    for(int i=0; i<5; i++){
        Insert(first, arr[i]);
    }
    display(first);

    Node *ans = mergeSort(first);
    display(ans);

    return 0;
}