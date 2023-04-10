#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void RecursiveDFS(int v, int arr[][8], int n){
    static int visited[8] = {0};    // to access only this arr itself everytime & not new ones
    
    if(visited[v]==0){
        cout<<v<<" ";
        visited[v] = 1;
        // select one adjacent vertex
        for(int u=0; u<=n; u++){
            if(arr[v][u]==1 && visited[u]==0){
                RecursiveDFS(u, arr, n);
            }
        }
    }
}

// using STL stack
void DFS(int v, int arr[][8], int n){
    int visited[n] = {0};

    stack<int> s;
    s.push(v);

    while(!s.empty()){
        v = s.top();
        s.pop();

        if(visited[v] != 1){
            cout<<v<<" ";
            visited[v] = 1;

            for(int u=n-1; u>=0; u--){
                if(arr[v][u]==1 && visited[u]==0){
                    s.push(u);
                }
            }
        }
    }
}

int main(){

    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    RecursiveDFS(5, A, 8);
    cout << endl;
 
    DFS(1, A, 8);
    cout << endl;   

    return 0;
}