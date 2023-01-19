#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *s;
    public:
        Stack(int size){                    // constructor for initialising stack
            this->size = size;
            this->top = -1;
            this->s = new int[size];
        }

        ~Stack(){                          // destructor
            delete[] s;
        }
        
        void push(int x);                 // for pushing element into stack
        int pop();                        // for popping out topmost element out of stack
        int peek(int index);              // for finding element at particular index
        int isFull();                     // for checking whether stack is FULL
        int isEmpty();                    // for checking whether stack is EMPTY
        void display();                   // for printing values of stack
        int stackTop();                   // for getting value of topmost element
};

int Stack::isFull(){
    if(top==size-1) return 1;
    else return 0;
}

int Stack::isEmpty(){
    if(top==-1) return 1;
    else return 0;
}

void Stack::display(){
    for(int i=top; i>=0; i--) cout<<s[i]<<" ";
    cout<<endl;
}

void Stack::push(int x){
    if(isFull()) cout<<"Stack Overflow!"<<endl;
    else{
        top++;
        s[top] = x;
    }
}

int Stack::pop(){
    int x = -1;
    if(isEmpty()) cout<<"Stack Underflow!"<<endl;
    else{
        x = s[top];
        top--;
    }
    return x;
}

int Stack::stackTop(){
    if(top==-1) return -1;
    else return s[top];
}

int Stack::peek(int pos){
    int x = -1;
    if(top-pos+1 < 0 || top-pos+1 == size)
        cout<<"Invalid Position!"<<endl;
    else
        x = s[top-pos+1];
    return x;
}

int main(){
    
    int a[] = {1,2,3,4,5};

    Stack s(5);

    for(int i=0; i<5; i++){
        s.push(a[i]);
    }

    s.display();

    // s.pop();
    // s.display();

    cout<<"stackTop: "<<s.stackTop()<<endl;
    cout<<"Peek: "<<s.peek(3);

    return 0;
}