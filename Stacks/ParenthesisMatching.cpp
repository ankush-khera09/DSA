#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        char *s;
    public:
        Stack(int size){
            this->size = size;
            this->top = -1;
            this->s = new char[size];
        }

        void push(char x){
            if(top==size-1) cout<<"Stack Overflow!";
            else{
                top++;
                s[top] = x;
            }
        }

        void display(){
            for(int i=top; i>=0; i--) cout<<s[i]<<" ";
            cout<<endl;
        }

        char pop(){
            char x = -1;
            if(top==-1) cout<<"Stack Underflow!";
            else{
                x = s[top];
                top--;
            }
            return x;
        }

        int isEmpty(){
            if(top==-1) return 1;
            return 0;
        }
};

bool isBalanced(char* e){
    Stack s(strlen(e));                  // Creating a Stack
    for(int i=0; i<strlen(e); i++){
        if(e[i]=='(') s.push(e[i]);
        else if(e[i]==')'){
            if(s.isEmpty()) return false;
            else s.pop();
        }
    }

    return s.isEmpty()?true:false;
}

int main(){
    
    char exp[] = "((a+b)*(c-d))";
    cout<<isBalanced(exp);

    return 0;
}