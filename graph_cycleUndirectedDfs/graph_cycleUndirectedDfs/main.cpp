//
//  main.cpp
//  graph_cycleUndirectedDfs
//
//  Created by CodeBreaker on 04/04/25.
//

#include <iostream>
#include <vector>
using namespace std;

int DFS(vector<int> G[], vector<int> &vis, vector<int> &par, int p, int v)
{
    if(vis[v]==1) return 0;
    
    vis[v]=1;
    par[v]=p;
    for(auto i: G[v])
    {
        if(vis[i]==0)
        {
            DFS(G,vis,par,v,i);
        } else {
            if(par[v]!=i) return 1;
        }
    }
    return 0;
}

int cycleDetectionDFS(vector<int> &U, vector<int> &V, int N, int S)
{
    //creating adjacency list
    vector<int> G[N+1];
    auto E = U.size();
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    
    //vreating visited list and parent list mark
    auto vis = vector<int>(N+1,0); // marking Source as visited
    auto par = vector<int>(N+1); // parent of source as 0
    
    
    for(int i=1; i<=N; i++) {
            if(vis[i] == 0) {
                if(DFS(G,vis,par,-1,i)) return 1;
            }
        }
        return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Finding DFS in undirected graph using DFS(depth first search)!\n";
    vector<int> U{1,1,3,3}, V{2,3,4,5};
    cout<<"Finding cycle : "<<cycleDetectionDFS(U, V, 7, 1)<<endl;
    return 0;
}
