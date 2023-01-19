#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Stack{               // Creating a Stack
    int size;
    int top;
    int *s;
};

void create(Stack *st){              // Initialising Stack
    cout<<"Enter size: ";
    cin>>st->size;                      // Setting size
    st->top = -1;                       // Setting top pointer as -1 initially
    st->s = new int[st->size];          // Making array
}

void display(Stack st){                   // Printing Stack
    for(int i=st.top; i>=0; i--){
        cout<<st.s[i]<<" ";
    }
    cout<<endl;
}

void push(Stack *st, int x){            // Pushing an element
    if(st->top==st->size-1)                   // Checking if stack is not full
        cout<<"Stack Overflow!"<<endl;
    else{
        st->top++;                      // Incrementing top pointer & saving new value
        st->s[st->top] = x;
    }
}

int pop(Stack *st){                    // Popping last element
    int x = -1;
    if(st->top==-1)                     // Checking if stack is not empty
        cout<<"Stack Underflow!";
    else{
        x = st->s[st->top];              // Storing value & then decrementing top pointer
        st->top--;
    }
    return x;
}

int peek(Stack st, int pos){           // Finding element at particular position
    int x = -1;
    if(st.top-pos+1 <0 )
        cout<<"Invalid Index! \n";
    else{
        x = st.s[st.top-pos+1];
    }
    return x;                           // returning value at that position else -1
}

int isEmpty(Stack st){            // Checks if stack is empty or not
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isFull(Stack st){           // Checks if stack is full or not
    if(st.top==st.size-1)
        return 1;
    else
        return 0;
}

int stackTop(Stack st){           // returns value of top most element
    if(st.top==-1)
        return -1;
    else
        return st.s[st.top];
}

int main(){
    
    Stack st;
    create(&st);

    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);

    cout<<"Before Popping: \n";
    display(st);
    cout<<"Popped element: "<<pop(&st)<<endl;
    cout<<"After Popping: \n";
    display(st);

    cout<<"Finding element at a position: "<<peek(st,6)<<endl;
    
    cout<<"isEmpty: "<<isEmpty(st)<<endl;
    cout<<"isFull: "<<isFull(st)<<endl;
    cout<<"stackTop: "<<stackTop(st)<<endl;



    return 0;
}