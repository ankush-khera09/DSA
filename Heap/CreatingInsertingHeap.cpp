#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Insert(int A[], int n){
    int temp = A[n];
    int i = n;
    while(i>1 && temp>A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}


int main(){
    int A[] = {0,10,20,30,25,5,40,35};
    int n = sizeof(A)/sizeof(A[0]);

    // Creating a Heap
    for(int i=2; i<n; i++){
        Insert(A, i);
    }

    for(int i=1; i<n; i++){
        cout<<A[i]<<" ";
    }

    return 0;
}