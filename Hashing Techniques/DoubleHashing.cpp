#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// defining 2 macros
#define SIZE 10
#define PRIME 7

template <class T>
void Print(T& arr, int n, string s){
    cout<<s<<"["<<flush;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<flush;
        if(i<n-1){
            cout<<", "<<flush;
        }
    }
    cout<<"]"<<endl;
}

// Hash Function     h(x) = x % size
int Hash(int key){
    return key % SIZE;
}

// Prime Hash Function     h2(x) = R-(x%R)
int PrimeHash(int key){
    return PRIME - (key % PRIME);
}

// Double Hash Function    h'(x) = [h1(x)+i*h2(x)]%10  where i=0,1,2,3---
int DoubleHash(int H[], int key){
    int idx = Hash(key);
    int i=0;
    while(H[(Hash(idx) + i*PrimeHash(idx)) % SIZE] != 0){
        i++;                     // jab tak khali space ni milta => repeat by changing values of 'i'
    }
    return (idx + i*PrimeHash(idx)) % SIZE;
}

// Inserting elements in HT
void Insert(int H[], int key){
    int idx = Hash(key);
    if(H[idx]!=0){           // agr vo khali ni hai => go to double hash fn
        idx = DoubleHash(H, key);
    }
    H[idx] = key;
}

// For Searching ele in HT
int Search(int H[], int key){
    int idx = Hash(key);
    int i=0;
    while(H[(Hash(idx) + i*PrimeHash(idx)) % SIZE] != key){
        i++;
        if(H[(Hash(idx) + i*PrimeHash(idx)) % SIZE] == 0){
            return -1;
        }
    }
    return (Hash(idx) + i*PrimeHash(idx)) % SIZE;
}


int main(){
    int arr[] = {5,25,15,35,95};
    int n = sizeof(arr)/sizeof(arr[0]);
    Print(arr, n, " A: ");           // just for printing this arr\

    int HT[10] = {0};    // Hash Table
    for(int i=0; i<n; i++){
        Insert(HT, arr[i]);          // for inserting arr ele in HT
    }
    Print(HT, SIZE, "HT: ");          // just for printing the HT

    cout<<"Key found at index: "<<Search(HT, 25);

    return 0;
}