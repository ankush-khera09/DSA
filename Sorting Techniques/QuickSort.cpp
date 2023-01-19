#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int partition (int arr[], int s, int e){
    int pivot = arr[s];                          // Taking pivot = first ele
    int count = 0;                               // Counting no. of elements <= pivot
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot) count++;
    }
    
    int pivotIndex = s+count;                    // Placing pivot at right position 
    swap(arr[pivotIndex], arr[s]);
    
    int i=s, j=e;                               // making ele before pivot < pivot & after pivot > pivot
    while(i<pivotIndex && j>pivotIndex){
        
        while(arr[i]<=pivot) i++;               // jab tak ele<=pivot hai => move ahead
        while(arr[j]>pivot) j--;                // jab tak ele > pivot hai => move j in reverse order
        
        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++], arr[j--]);           // swap elements as not at suitable sides
    }
    return pivotIndex;                          // return Pivot Index
}

void quickSort(int arr[], int s, int e){
    if(s>=e) return;                             // Base Case
    
    int p = partition(arr, s, e);                // Partition Index
    quickSort(arr, s, p-1);                      // Sorting left part of partition index
    quickSort(arr, p+1, e);                      // Sorting right part of partition index
}

int main(){
    int arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7};
    quickSort(arr, 0, 8);

    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}