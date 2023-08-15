#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>         // for generalising the function
class Graph{
    public:
        // node/vertex -> uske saath kon kon si vertices connected hai (unko list me) 
        unordered_map<T, list<T>> adj;

        void addEdge(T u, T v, bool direction){
            
            // direction = 0 => undirected
            // direction = 1 => directed

            // create an edge from u to v
            adj[u].push_back(v);

            if(direction==0){
                // it is undirected graph
                // so, u->v & v->u dono honge
                adj[v].push_back(u);
            }
        }

        // PRINT ADJACENCY LIST ----------------------------------

        void printAdjList(){
            for(auto i:adj){
                cout<<i.first<<"-> ";
                // to traverse in list
                for(auto j:i.second){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }

        // BREADTH FIRST TRAVERSAL ---------------------------------

        void BFS(int source){
            unordered_map<int, bool> visited;   // to keep track of all visited vertices

            queue<int> q;

            visited[source] = true;          // mark the current node as visited
            q.push(source);

            while(!q.empty()){
                int frontNode = q.front();
                cout<<frontNode<<" ";
                q.pop();

                // traverse all adjacent vertices

                // for(auto i: adj){
                //     for(auto j: i.second){
                //         // if not visited => mark it true and push into queue
                //         if(!visited[j]){
                //             visited[j] = true;
                //             q.push(j);
                //         }
                //     }
                // }
                for(auto i: adj[frontNode]){
                        // if not visited => mark it true and push into queue
                        if(!visited[i]){
                            visited[i] = true;
                            q.push(i);
                    }
                }
            }
        }

        // DEPTH FIRST TRAVERSAL ------------------------
        // (using recursion)

        void DFS(int node){
            // static bcz this visited map should remain same for every recursive call
            static unordered_map<int, bool> visited;

            if(!visited[node]){
                cout<<node<<" ";
                visited[node] = true;
                
                // for(auto i: adj){
                //     for(auto j: i.second){
                //         if(!visited[j]){
                //             DFS(j);
                //         }
                //     }
                // }
                for(auto i: adj[node]){
                    if(!visited[i]){
                        DFS(i);
                    }
                }
            }
        }
        // for a disconnected graph => graph having multiple components, we need to ensure that we travel all nodes
        // so, use a for loop for that
        // https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar 

        // (using Stack)
        void dfsUsingStack(int source){
            unordered_map<int,bool> visited;

            stack<int> s;

            s.push(source);       // push source node

            while(!s.empty()){
                int node = s.top();
                s.pop();

                // Stack may contain same vertex twice. So
                // we need to print the popped item only if it is not visited.
                if(!visited[node]){
                    cout<<node<<" ";
                    visited[node] = true;
                }

                // Get all adjacent vertices of the popped node
                // If the adjacent node has not been visited, then push it to the stack.
                for(auto neighbour : adj[node]){
                    if(!visited[neighbour]){
                        s.push(neighbour);
                    }
                }
            }
        }

        // -----> Detect Cycle in Undirected Graph (using BFS & DFS):
        // https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

        // -----> Detect Cycle in Directed Graph (using DFS & BFS):
        // using bfs => kahn's algo
        // https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

    // -----> Topological Sorting: Topological Sort is linear ordering of vertices such that for every directed edge
	    // u->v , 'u' always appear before v in that ordering

        // It is valid only for Directed Acyclic Graph (DAG)
        // This can be used to detect cycle in graph => valid topo sort => no cycle => else cycle
        // as otherwise for eg: cyclic graph edges => [1->2], [2->3], [3->1]
        // 1-->2-->3-
        // |____<___|
        // sort: 1,2,3 => fails as 3 is not before 1

        // Topological Sorting (using DFS & BFS): https://practice.geeksforgeeks.org/problems/topological-sort/1
        // { USING BFS, its called => "KAHN'S ALGORITHM" }

        // -----> Shortest path in undirected graph: https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0
        // -----> Shortest path in DAG: VS Code

        // -----> DIJKSTRA's ALGORITHM : used for finding shortest path from source node to all nodes
        // gfg/codestudio
        // https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
        // https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

        // Spanning Tree: When a graph is converted into a tree (means no cycle) such that it contains 'n' nodes and 'n-1' edges,
        // provided every node is reachable by every other node
        // -----> PRIM's ALGORITHM : used for minimum spanning tree (min cost of weights)
        // Gfg: find sum of final weights in mst, Codestudio: find final mst
        // https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
        // https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

        // -----> KRUSKAL's ALGORITHM : used for finding minimum spanning tree

        // -----> Disjoint Set: a type of data structure
        // # we implement Kruskal's algo through this
        // # we can check whether 2 nodes belong to the same component of a graph or not
        // # 2 imp functions:
        // findParent() or findSet() => find parent node of a component
        // union() or unionSet() => union of 2 components
        // -> Union by rank and path compression concept
        // codestudio: https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

        // Bridge in Graph
};

int main(){
    
    int n;
    cout<<"Enter the no. of nodes: ";
    cin>>n;

    int m;
    cout<<"Enter the no. of edges: ";
    cin>>m;

    Graph<int> g;          // int data-type in graph

    for(int i=0; i<m; i++){
        // taking edges
        int u, v;
        cin >> u >> v;

        // Creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // printing graph
    g.printAdjList();

    cout<<"BFS: ";
    g.BFS(2);

    cout<<endl;

    cout<<"DFS: ";
    g.DFS(0);
    cout<<endl;

    cout<<"DFS using Stack: ";
    g.dfsUsingStack(0);


    /* sample input:
            Enter the no. of nodes: 4
            Enter the no. of edges: 4
            0 1
            0 2
            2 3
            1 2    
    */

    return 0;
}