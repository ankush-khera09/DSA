#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int l, int h){
    int mid = l+(h-l)/2;
    int i = l;
    int j = mid+1;
    int k = l;
    int arr2[100];            // auxilary array (can take arr2[100])

    while(i<=mid && j<=h){
        if(arr[i]<arr[j]){
            arr2[k++] = arr[i++];
        }else{
            arr2[k++] = arr[j++];
        }
    }

    while(i<=mid) arr2[k++] = arr[i++];
    while(j<=h) arr2[k++] = arr[j++];

    for(int i=l; i<=h; i++){
        arr[i] = arr2[i];
    }
}

void MergeSort(int arr[], int l, int h){
    if(l>=h) return;

    int mid = l+(h-l)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, h);
    Merge(arr, l, h);
}

// void MergeSort(int arr[], int n){
//     int p;
//     for(p=2; p<=n; p=p*2){
//         for(int i=0; i+p-1<n; i=i+p){
//             int l = i;
//             int h = i+p-1;
//             Merge(arr, l, h);
//         }
//     }
//     if(p/2<n) Merge(arr, 0, n-1);
// }

int main(){
    int arr[] = {1,5,7,2,4,8};
    MergeSort(arr,0,5);

    for(int i=0; i<6; i++) cout<<arr[i]<<" ";

    return 0;
}