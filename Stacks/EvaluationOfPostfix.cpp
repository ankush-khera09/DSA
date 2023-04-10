#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Eval(string str){
    stack<char> s;

    int x1, x2, r;

    for(int i=0; i<str.length(); i++){
        char c = str[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) s.push(c-'0');
        // or 
        // if(c!="+" && c!="-" && c!="*" && c!="/") s.push(stoi(c));

        // if it is an operator
        else{
            x2 = s.top();
            s.pop();
            x1 = s.top();
            s.pop();

            switch(c){
                case '+':
                    r = x1+x2;
                    break;
                case '-':
                    r = x1-x2;
                    break;
                case '*':
                    r = x1*x2;
                    break;
                case '/':
                    r = x1/x2;
                    break;
            }

            s.push(r);           // push the result obtained in the stack
        }
    }
    return s.top();             // final ans would be left in the stack
}

int main(){
    string str = "234*+82/-";
    cout<<Eval(str)<<endl;

    return 0;
}