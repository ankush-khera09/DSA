#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class QueueUsing2Stacks{
    stack<int> s1;
    stack<int> s2;

    public:
        void pushEle(int x){
            s1.push(x);
        }

        int popEle(){
            int x = -1, m = -1;

            if(s2.empty()){
                if(s1.empty()){
                    cout<<"Queue is empty!"<<endl;
                    return -1;
                }else{
                    while(!s1.empty()){
                        m = s1.top();
                        s2.push(m);
                        s1.pop();
                    }
                }
            }
            x = s2.top();
            s2.pop();
            return x;
        }
};

int main(){
    int arr[] = {1,2,3,4,5};
    QueueUsing2Stacks qs;

    for(int i=0; i<5; i++){
        qs.pushEle(arr[i]);
    }

    cout<<qs.popEle()<<endl;

    return 0;
}












