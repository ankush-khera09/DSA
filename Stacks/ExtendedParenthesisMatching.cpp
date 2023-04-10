#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// USING STL ////////////////////////////////////////////////////////////

// Without MAP :
bool isValid(string s) {
    stack<char> stk;

    for(int i=0; i<s.length(); i++){
        char c = s[i];

        if(c=='(' || c=='{' || c=='[') stk.push(c);
        else if(c==')' || c=='}' || c==']'){
            if(stk.empty()) return false;
            else{
                char top = stk.top();
                if(
                    (top =='(' && c==')') ||
                    (top =='{' && c=='}') ||
                    (top =='[' && c==']')
                ) stk.pop();          // found a match
                else return false;
            }
        }
    }

    return stk.empty() ? true : false;
}


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

    string s = "{([a+b]*[c-d])/e}";
    cout<<isValid(s)<<endl;

    return 0;
}