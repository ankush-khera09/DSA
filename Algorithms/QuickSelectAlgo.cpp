#include<bits/stdc++.h>
using namespace std;


//////////////// FINDING KTH SMALLEST ELEMENT IN AN ARRAY ///////////////

int partition(int arr[], int low, int high){
    int pivot = arr[high];      // take last ele as pivot
    int pivotpos = low;         // take a pointer to set ele<pivot to the left side of pivot

    for(int i=low; i<=high; i++){
        if(arr[i]<pivot){
            int temp = arr[pivotpos];
            arr[pivotpos] = arr[i];     // setting ele<pivot to the left side of pivot
            arr[i] = temp;
            pivotpos++;
        }
    }
    
    int temp = arr[pivotpos];          // placing pivot at correct position (after ele which are lesser than pivot)
    arr[pivotpos] = arr[high];
    arr[high] = temp;
    
    return pivotpos;                  // returning index of pivot
}

int kthsmallestElement(int arr[], int low, int high, int k){
        int partitionIndex = partition(arr, low, high);
        
        if(partitionIndex+1 == k)
            return arr[partitionIndex];
        else if(partitionIndex+1 < k)
            return kthsmallestElement(arr, partitionIndex+1, high, k);
        else
            return kthsmallestElement(arr, low, partitionIndex-1, k);
    }

int main(){
    int arr[] = {1,0,3,4,2};
    int k = 4;
    cout<<kthsmallestElement(arr, 0, 4, k);

    return 0;
}