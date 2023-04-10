#include <iostream>
using namespace std;
#include <stack>

int countMinReversals(string str)
{

    stack<char> s;
    
    int ans = 0;
    
    for(int i=0; i<str.length(); i++){
        char c = str[i];
        
        // in case of opening bracket => push in stack
        if(c=='{') s.push(c);
        
        // in case of closing bracket
        else{
            // if stack isn't empty => pop out bracket as we found a pair {}
            if(!s.empty()) s.pop();
            
            // if it empty => change closing to opening and push in stack
            // also add 1 to ans
            else{
                s.push('{');
                ans++;
            }
        }
    }
    
    // if the size of stack is odd => return -1 => can't form pair of {} then
    if(s.size()%2 != 0) return -1;
    // if size of stack is even
    else ans += s.size()/2;
    
    return ans;
}

int main()
{
    string expr = "{{{{}}";
    // string expr = "}}{";
    // string expr = "{{{";
    cout << countMinReversals(expr);
    return 0;
}