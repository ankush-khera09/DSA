#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/////////////////////////// Arrays ADT operations ///////////////////
struct Array
{
    int A[10];
    int size;
    int length;
};

display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << endl;
    }
}

append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

insert(struct Array *arr, int index, int ele)
{
    for (int i = arr->length; i > index; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = ele;
    arr->length++;
}

delete1(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

//////////////////////////// Binary Search ///////////////////
int BinarySearch(int binarr[], int size, int ele){
    int l = 0;
    int h = size-1;
    int mid;
    while(l<=h){
        mid = (l+h)/2;
        if(binarr[mid]==ele) return mid;
        else if(binarr[mid]>ele) h=mid-1;
        else l=mid+1;
    }
    return -1;
}

///// Binary Search Recursively ///////////
int RbinSearch(int arr[],int l, int h, int ele){
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(arr[mid] == ele) return mid;
        else if(arr[mid]<ele)
            return RbinSearch(arr, mid+1, h, ele);
        else
            return RbinSearch(arr, l, mid-1, ele);
    }
    return -1;
}

////////////////////////// Reverse Array ///////////////

// Method 1: Using an extra array

int ReverseArr(int arr[], int len){
    int newarr[len];
    int i,j;
    for(i=len-1, j=0; i>=0; i--, j++){              // Time Comp = 2n [n+n] => O(n)
            newarr[j] = arr[i];
    }
    for(int i=0; i<len; i++){
        arr[i] = newarr[i];
    }
    cout<<"Reversed Array: ";
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Method 2: Taking 2 pointers from start and end

int ReverseArr2(int arr[], int len){
    int i,j;
    for(i=0, j=len-1; i>j; i++, j--){          // Time Comp = O(n)
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    cout<<"Reversed Array by Method 2: ";
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

////////// Left Shift ///////////

int leftshift(int arr[], int len){
    for(int i=0; i<len; i++){
        arr[i] = arr[i+1];
    }
    arr[len-1] = 0;                        // Time Comp = O(n) [We have moved n elements]

    cout<<"Left Shift: ";
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

////////// Inserting an element inside a sorted array /////////////

int insortarr(int arr[], int len, int ele){
    int i = len-1;
    while(arr[i]>ele){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = ele;

    cout<<"Inserting ele in sorted arr: ";
    for(int i=0; i<len+1; i++){                  // len+1 bcz. one ele is added
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//////////// Checking whether an arr is sorted or not //////////

int checksort(int arr[], int len){
    for(int i=1; i<=len; i++){                       // Time Comp = O(n)
        if(arr[i]<arr[i-1]) return 0;
    }
    return 1;
}

///////////// Bring all -ve no's to the left & +ve to the right ///////////

int negonleft(int arr[], int len){
    int i = 0;                          // Taking 2 pointers from both sides
    int j = len-1;
    while(i<j){
        while(arr[i]<0){i++;};              // Time Comp = O(n)
        while(arr[j]>0){j--;};              // Actual no of comparisons = n+1+1
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        };
    }

    // int i = 0;                             // 2nd method
    // int neg = 0;
    // while(i<n){
    //     if(arr[i]<0){
    //         int temp = arr[neg];
    //         arr[neg] = arr[i];
    //         arr[i] = temp;
    //         neg++;
    //         i++;
    //     }else if(arr[i]>0){
    //         i++;
    //     }
    // }

    ///////// OR

    // for(int i=0; i<6; i++){
    //     if(arr[i]<0){
    //         swap(arr[i],arr[neg]);
    //         neg++;
    //     }
    // }


    cout<<"Bring all -ve no's to the left: ";
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/////////// Merging 2 Sorted Arrays ////////////////

void merSort(int arr1[], int n1, int arr2[], int n2, int arr3[]){
    int i=0, j=0 ,k=0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3[k++] = arr1[i++];             // Time Comp = Theta(m+n)
        }else{                                 // m = no. of ele in arr1
            arr3[k++] = arr2[j++];            // n = no. of ele in arr2
        }                                      // we take time for copying ele of both arr in arr3
    }

    while(i<n1){
        arr3[k++] = arr1[i++];
    }
    while(j<n2){
        arr3[k++] = arr2[j++];
    }
    
    for(int i=0; i<n1+n2; i++){
        cout<<arr3[i]<<" ";
    }
}

////////////////////// Union of 2 sets /////////////////////

///////// USING SETS
int unionof2sets(int a[], int n, int b[], int m){
    set<int> s;
    for(int i=0; i<n; i++){
        s.insert(a[i]);
    }
    for(int j=0; j<m; j++){
        s.insert(b[j]);
    }

    return s.size();       // returns no. of ele in union set
}

//////// Unsorted Arrays

int unionofsets1(int arr1[], int n1, int arr2[], int n2, int arr3[]){
    int l = 0;                       // pointer to remember the location of last ele position
    for(int i=0; i<n1; i++){         // Copying elements of arr1 in arr3
        arr3[l] = arr1[i];
        l++;
    }

    for(int i=0; i<n2; i++){
        int flag = 0;
        for(int j=0; j<n1; j++){
            if(arr2[i] == arr3[j]){          // if ele in arr2 is same as arr1 => don't copy
                flag = 1;
                break;
            };
        }
        if(flag == 0){
            arr3[l] = arr2[i];              // if arr2 ele != arr1 ele => copy and move to next position
            l++;
        };
    }
    
    for(int i=0; i<l; i++){
        cout<<arr3[i]<<" ";
    }
}

////////////// Sorted Arrays
// The below solution will fail for duplicate elements. You can refer this: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
int unionofsets2(int arr1[], int n1, int arr2[], int n2, int arr3[]){
    int i=0, j=0, k=0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]) arr3[k++] = arr1[i++];
        else if(arr2[j]<arr1[i]) arr3[k++] = arr2[j++];
        else{
            arr3[k++] = arr1[i++];
            j++;
        }
    }

    while(i<n1){
        arr3[k++] = arr1[i++];
    }
    while(j<n2){
        arr3[k++] = arr2[j++];
    }

    for(int i=0; i<k; i++){
        cout<<arr3[i]<<" ";
    }

}

////////////////////// Intersection of 2 sets //////////////////

////////////// Unsorted Arrays
int interofsets1(int arr1[], int n1, int arr2[], int n2, int arr3[]){
    int k = 0;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(arr1[i]==arr2[j]){
                arr3[k++] = arr1[i];
            }
        }
    }
    for(int i=0; i<k; i++){
        cout<<arr3[i]<<" ";
    }
}

///////////////////// Sorted Arrays
int interofsets2(int arr1[], int n1, int arr2[], int n2, int arr3[]){
    int i=0, j=0, k=0;
    while (i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j]) i++;               // arr1[i] is smaller, move to next ele
        else if(arr2[j]<arr1[i]) j++;          // arr2[j] is smaller, move to next ele
        else{                                  // arr1[i]==arr2[j] => copy to arr3 & i++,j++,k++
            arr3[k++] = arr1[i++];             // copy to arr3 only if arr1[i] == arr2[j]
            j++;
        }
    }
    for(int i=0; i<k; i++){                    // printing arr3
        cout<<arr3[i]<<" ";
    }
    
}

///////////////////// Difference of 2 sets //////////////////////
////////////// Unsorted Arrays

int diffofsets1(int arr1[], int n1, int arr2[], int n2, int arr3[]){
    int k=0;
    for(int i=0; i<n1; i++){
        int flag = 0;
        for(int j=0; j<n2; j++){
            if(arr1[i]==arr2[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            arr3[k++] = arr1[i];
        }
    }
    for(int i=0; i<k; i++){                    // printing arr3
        cout<<arr3[i]<<" ";
    }
}

//////////////// Sorted Arrays
int diffofsets2(int arr1[], int n1, int arr2[], int n2, int arr3[]){
    int i=0, j=0, k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){                 // arr1[i]<arr2[j] => copy arr1[i] to arr3
            arr3[k++] = arr1[i++];           
        }else if(arr2[j]<arr1[i]){          // arr2[j]<arr1[i] => move to next ele (j++)
            j++;
        }else{                             // arr1[i]==arr2[j] => move ahead (i++ & j++)
            i++;
            j++;
        }
    }
    while(i<n1){
        arr3[k++] = arr1[i++];
    }

    for(int i=0; i<k; i++){                    // printing arr3
        cout<<arr3[i]<<" ";
    }
}

////////////////////// Find duplicate elements in sorted array //////////////
void finddup(int arr[], int n){
    int lastduplicate = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==arr[i+1] && arr[i]!=lastduplicate){
            cout<<arr[i]<<" ";
            lastduplicate = arr[i];
        }
    }
}

/////////////// Find no of duplicates of an ele in sorted array
void noofdup(int arr[], int n){
    int j;
    for(int i=0; i<n; i++){
        if(arr[i]==arr[i+1]){
            j = i+1;
            while(arr[j]==arr[i]) j++;
            cout<<arr[i]<<" occurs "<<j-i<<" times."<<endl;
            i = j-1;
        }
    }
}

/////////////// Find no of duplicates of an ele in an unsorted array
void noofdup2(int arr[], int n){
    int count;
    for(int i=0;i<n-1;i++){
        count = 1;
        if(arr[i]!=-1){
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    count++;
                    arr[j] = -1;
                }
            }
            if(count>1){
                cout<<arr[i]<<" appears "<<count<<" times."<<endl;
            }
        }
    }
}

//////////////// Find pair of ele whose sum = k ///////////////
////////// Unsorted Array
void pair1(int arr[], int n, int k){
    for(int i=0; i<n-1; i++){                          // Time comp = O(n^2)
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==k){
                cout<<"Pair: "<<arr[i]<<" & "<<arr[j]<<endl; 
            }
        }
    }
}

///////////////// Sorted Array
void pair2(int arr[], int n, int k){
    cout<<"Pairs in sorted array: "<<endl;
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==k){
            cout<<"Pair: "<<arr[i]<<" & "<<arr[j]<<endl;
            i++;
            j--;
        }else if(arr[i]+arr[j]>k){
            j--;
        }else{
            i++;
        }
    }
}

/////////////// Find max and min ele in one scan ///////////////
void minmax(int arr[], int n){
    int min=arr[0], max=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]<min)
            min = arr[i];
        else if(arr[i]>max)
            max = arr[i];
    }
    cout<<"Max: "<<max<<" & min: "<<min<<endl;
}

////////////////////////////////// main() funtion ///////////////////////////////////

int main()
{
    struct Array arr
    {
        {1, 2, 3, 4, 5}, 10, 5
    };
    display(arr);

    append(&arr, 88);
    cout << "\n"
         << "After Appending:"
         << "\n";
    display(arr);

    insert(&arr, 2, 99);
    cout << "After Inserting:" << endl;
    display(arr);

    delete1(&arr, 3);
    cout << "After Deleting:" << endl;
    display(arr);

    int binarr[] = {0,1,2,3,4,5,6,7,8,9,10};
    int ele = 7;
    cout<<"Binary Search:"<<endl;
    cout<<BinarySearch(binarr, 11, ele)<<endl;

    cout<<"Binary Search Recursively: "<<endl;
    cout<<RbinSearch(binarr,0,10,7)<<endl;

    int revarr[] = {1,2,3,4,5};
    ReverseArr(revarr, 5);
    ReverseArr2(revarr, 5);

    leftshift(binarr, 11);

    int inarr[10] = {1,5,7,9,10,15};
    insortarr(inarr, 6, 8);

    int checkarr[] = {1,2,4,5};
    cout<<"Check whether an arr is sorted or not: ";
    cout<<checksort(checkarr, 4)<<endl;

    int negarr[] = {-1,2,3,-5,6,-9};
    negonleft(negarr, 6);

    int marr1[] = {3,8,16,20,25};
    int n1 = sizeof(marr1) / sizeof(marr1[0]);
    int marr2[] = {4,10,12,22,23};
    int n2 = sizeof(marr2) / sizeof(marr2[0]);
    int marr3[n1+n2];
    cout<<"Merged 2 sorted arrays: ";
    merSort(marr1, n1, marr2, n2, marr3);
    cout<<endl;

    int uarr1[] = {3,5,10,4,6};
    int un1 = sizeof(uarr1) / sizeof(uarr1[0]);
    int uarr2[] = {12,4,7,2,5};
    int un2 = sizeof(uarr2) / sizeof(uarr2[0]);
    int uarr3[un1 + un2];
    cout<<"Union of 2 unsorted arrays: ";
    unionofsets1(uarr1, un1, uarr2, un2, uarr3);
    cout<<endl;

    int uarr4[] = {3,4,5,6,10};
    int u1 = sizeof(uarr4) / sizeof(uarr4[0]);
    int uarr5[] = {2,4,5,7,12};
    int u2 = sizeof(uarr5) / sizeof(uarr5[0]);
    int uarr6[u1 + u2];
    cout<<"Union of 2 sorted arrays: ";
    unionofsets2(uarr4, u1, uarr5, u2, uarr6);
    cout<<endl;

    int iarr1[] = {3,5,10,4,6};
    int in1 = sizeof(iarr1) / sizeof(iarr1[0]);
    int iarr2[] = {12,4,7,2,5};
    int in2 = sizeof(iarr2) / sizeof(iarr2[0]);
    int iarr3[in1 + in2];
    cout<<"Intersection of 2 unsorted arrays: ";
    interofsets1(iarr1, in1, iarr2, in2, iarr3);
    cout<<endl;

    int iarr4[] = {3,4,5,6,10};
    int i1 = sizeof(iarr4) / sizeof(iarr4[0]);
    int iarr5[] = {2,4,5,7,12};
    int i2 = sizeof(iarr5) / sizeof(iarr5[0]);
    int iarr6[i1 + i2];
    cout<<"Intersection of 2 sorted arrays: ";
    interofsets2(iarr4, i1, iarr5, i2, iarr6);
    cout<<endl;

    int darr1[] = {3,5,10,4,6};
    int dn1 = sizeof(darr1) / sizeof(darr1[0]);
    int darr2[] = {12,4,7,2,5};
    int dn2 = sizeof(darr2) / sizeof(darr2[0]);
    int darr3[dn1 + dn2];
    cout<<"Difference of 2 unsorted arrays: ";
    diffofsets1(darr1, dn1, darr2, dn2, darr3);
    cout<<endl;

    int darr4[] = {3,4,5,6,10};
    int d1 = sizeof(darr4) / sizeof(darr4[0]);
    int darr5[] = {2,4,5,7,12};
    int d2 = sizeof(darr5) / sizeof(darr5[0]);
    int darr6[d1 + d2];
    cout<<"Difference of 2 sorted arrays: ";
    diffofsets2(darr4, d1, darr5, d2, darr6);
    cout<<endl;

    int duparr[] = {3,6,8,8,10,12,15,15,15,20};   // find duplicate ele in a sorted arr
    int dp = sizeof(duparr) / sizeof(duparr[0]);
    cout<<"Duplicate ele in arr: ";
    finddup(duparr, dp);
    cout<<endl;

    noofdup(duparr, dp);           // find no of duplicates in a sorted arr

    int duparr2[] = {8,3,6,4,6,5,6,8,2,7};   // find duplicate ele in an unsorted arr
    int dp2 = sizeof(duparr2) / sizeof(duparr2[0]);
    cout<<"Duplicate ele in unsorted arr: "<<endl;
    noofdup2(duparr2, dp2);
    cout<<endl;
    
    pair1(duparr2, dp2, 10);          // find pair elements whose sum=k in unsorted array
    cout<<endl;
    pair2(duparr, dp, 9);            // find pair elements whose sum=k in sorted array
    cout<<endl;
    minmax(duparr, dp);

    return 0;
}
