#include<iostream>
#include<bits/stdc++.h>

#define SIZE 10
// Here we have used #define which is a 'macro'
// Macro is a piece of code which is given a name
// & wherever the compiler encounters it, it replaces it with the actual piece of code

using namespace std;

// Just a simple Print Function
// Just for presenting our output in our own way with brackets and commas
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

int Hash(int key){                 // Hash Function
    return key%SIZE;
}

int LinearProbe(int H[], int key){          // For Linear Probing
    int index = Hash(key);                   // index = h(x)
    int i=0;
    while(H[(index+i) % SIZE] != 0){                  // h'(x) = [(h(x)+f(i))%10]
        i++;                                          // Move on until you get an empty space
    }
    return (index+i) % SIZE;
}

void Insert(int H[], int key){
    int index = Hash(key);
    if(H[index]!=0){                             // if the allocated space is not empty => go to next position using linear probe fn
        index = LinearProbe(H, key);
    }
    H[index] = key;                            // place the key
}

int Search(int H[], int key){
    int index = Hash(key);
    int i=0;
    while(H[(index+i) % SIZE] != key){                // move on until you get your key
        i++;
        if(H[(index+i) % SIZE] == 0){                 // stop if you get an empty space
            return -1;
        }
    }
    return (index+i) % SIZE;                 // return the index where key is present
}


int main(){
    int arr[] = {1,2,3,4,5,24};
    int n = sizeof(arr)/sizeof(arr[0]);
    Print(arr, n, " A: ");         // Just for printing array

    int HT[10] = {0};         // HashTable of fixed size 10
    for(int i=0; i<n; i++){
        Insert(HT, arr[i]);
    }
    Print(HT, SIZE, "HT: ");     // for printing HT

    cout<<"Key found at index: "<<Search(HT, 24);

    return 0;
}