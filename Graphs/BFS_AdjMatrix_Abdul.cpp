#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BFS(int v, int arr[][8], int n){

    int visited[n] = {0};         // to keep track of all visited vertices

    queue<int> q;

    cout<<v<<" ";                // visit vertex
    visited[v] = 1;         // mark it visited
    q.push(v);              // push it in queue

    while(!q.empty()){
        v = q.front();              // vertex for exploring
        q.pop();
        // adjacent vertices of vertex 'v'
        // a row in the matrix
        for (int u = 1; u <= n; u++){
            if(arr[v][u]==1 && visited[u]==0){
                cout<<u<<" ";
                visited[u] = 1;
                q.push(u);
            }
        }
        
    }
    cout<<endl;
}


int main(){
    
    // Adjacency Matrix : kept 0-index zero itself
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    
    BFS(1, A, 8);
 
    BFS(4, A, 8);

    return 0;
}