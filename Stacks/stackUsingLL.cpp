#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=NULL;                   // Global Variable 'top'

void push(int x){                       // Inserting/Pushing an element
    Node *t = new Node;
    if(t==NULL) cout<<"Stack Overflow!"<<endl;
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

void display(){                        // Printing Stack elements
    Node *p = top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int pop(){                             // Deleting/Popping last element
    int x = -1;
    if(top==NULL) cout<<"Stack Underflow!"<<endl;
    else{
        Node *p = top;
        top=top->next;
        x = p->data;
        delete p;
    }
    return x;
}

/*
-------------------   USING CLASSES (C++ code)   --------------------

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        int *top;
    public:
        Stack(){top==NULL};
        void push(int x);
        int pop();
        void display();
};

void Stack::push(int x){-----code-----}

int main()[
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.display();                  // 3 2 1
]

*/


int main(){
    
    push(1);
    push(2);
    push(3);
    display();

    pop();
    display();

    return 0;
}