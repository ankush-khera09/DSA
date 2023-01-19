#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *top;
    public:
        Stack();
        ~Stack();
        void push(int x);
        int pop();
        int isFull();
        int isEmpty();
        int peek(int x);
        void display();
        int stackTop();
};

Stack::Stack(){
    top = NULL;
}

Stack::~Stack(){
    Node *p = top;
    while(top){
        top=top->next;
        delete p;
        p = top;
    }
}

int Stack::isEmpty(){
    if(top==NULL) return 1;
    else return 0;
}

int Stack::isFull(){
    Node *t = new Node;
    if(t==NULL) return 1;
    else return 0;
}

void Stack::push(int x){
    Node* t = new Node;
    if(t==NULL) cout<<"Stack Overflow!"<<endl;
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop(){
    int x = -1;
    Node* p;
    if(isEmpty()) cout<<"Stack Underflow!"<<endl;
    else{
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

void Stack::display(){
    Node* p = top;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int Stack::peek(int pos){
    if(isEmpty()) return -1;
    else{
        Node* p = top;
        for(int i=0; i<pos-1 && p!=NULL; i++){
            p=p->next;
        }
        if(p!=0) return p->data;
        else return -1;
    }
}

int Stack::stackTop(){
    if(top) return top->data;
    else return -1;
}

int main(){
    
    int a[] = {1,2,3,4,5};

    Stack s;
    for(int i=0; i<5; i++){
        s.push(a[i]);
    }

    s.display();

    // s.pop();
    // s.display();

    cout<<"Peek: "<<s.peek(2)<<endl;

    cout<<"stackTop: "<<s.stackTop()<<endl;

    return 0;
}