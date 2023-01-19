#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TwoStack {
	int *arr;
    int top1;
    int top2;
    int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        //atleast an empty space present
        if(top2 - top1 > 1 ) {
            top1++;
            arr[top1] = num;
        } 
       
    }

    // Push in stack 2.
    void push2(int num) {
         if(top2 - top1 > 1 ) {
            top2--;
            arr[top2] = num;
        } 
       
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
		if( top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
		if( top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }

};



int main(){

    int size;                                // size of array
    cout<<"Enter size of array: ";
    cin>>size;
    TwoStack ts(size);

    int t;                                  // no. of test cases/operations
    cout<<"Enter no. of test cases: ";
    cin>>t;

    while(t--){
        int q;
        cout<<"Enter Query Type: "<<endl<<"1 for push & 2 for pop: ";
        cin>>q;                            // query type (1==push, 2==pop)
        if(q==1){
            int stkNo;
            cout<<"Enter Stack No: ";
            cin>>stkNo;                    // query to be performed on which stack (1 or 2)
            int x;
            cout<<"Enter element to be pushed: ";
            cin>>x;                        // as q==1 means push, so push 'x'

            if(stkNo==1) ts.push1(x);
            else if(stkNo==2) ts.push2(x);
        }else if(q==2){
            int stkNo;
            cout<<"Enter Stack No: ";
            cin>>stkNo;                   // Stack Number whose element is to be popped out

            if(stkNo==1) cout<<"Popped from stack 1: "<<ts.pop1()<<endl;
            else if(stkNo==2) cout<<"Popped from stack 2: "<<ts.pop2()<<endl;
        }
    }

    return 0;
}