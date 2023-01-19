#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// USING STL ////////////////////////////////////////////////////////////

bool isBalanced(char* exp){
    
    map<char,char> m;
    m[')'] = '(';
    m['}'] = '{';
    m[']'] = '[';

    map<char,char> :: iterator it;

    stack<char> s;

    for(int i=0; i<strlen(exp); i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') s.push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(s.empty()) return false;
            else{
                char temp = s.top();
                it = m.find(exp[i]);
                if(temp==it->second) s.pop();
                else return false;
            }
        }
    }
    return s.empty()?true:false;

}




int main(){
    char A[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(A) << endl;

    return 0;
}