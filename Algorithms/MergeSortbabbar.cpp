#include<iostream>
using namespace std;


void m(int *arr, int s, int e){
    int mid = (s+e)/2;

    int l1 = mid-s+1;
    int l2 = e-mid;

    int *f = new int[l1];
    int *sec = new int[l2];

    int k = s;
    for(int i=0; i<l1; i++){
        f[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0; i<l2; i++){
        sec[i] = arr[k++];
    }

    int ind1=0;
    int ind2=0;
    k=s;

    while(ind1<l1 && ind2<l2){
        if(f[ind1]<sec[ind2]){
            arr[k++] = f[ind1++];
        }else{
            arr[k++] = sec[ind2++];
        }
    }

    while(ind1<l1){
        arr[k++] = f[ind1++];
    }
    while(ind2<l2){
        arr[k++] = sec[ind2++];
    }

    delete []f;
    delete []sec;
}

void mergeSort(int *arr, int s, int e){
    if(s>=e) return;
    
    int mid = (s+e)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    m(arr, s, e);
}


int main(){
    int arr[] = {1,2,3,4,2,1,3};

    int n = 7;

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}