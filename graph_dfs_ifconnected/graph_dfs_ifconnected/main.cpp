//
//  main.cpp
//  graph_dfs_ifconnected
//
//  Created by CodeBreaker on 22/02/25.
//

#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<int> G[], vector<bool> &vis, int S, int D)
{
    if(vis[S]==true) return;
    
    vis[S]=true;
    for(auto i:G[S])
    {
        dfs(G, vis, i, D);
    }
    return;
}

bool ifConnected(vector<int> &U, vector<int> &V, int N, int E, int S, int D)
{
    vector<int> G[N+1];
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    auto vis = vector<bool>(N+1, false);
//    dfs(G,vis,S,D);
    dfs(G, vis, S, D);
    return vis[D];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, DFS connected nodes!\n";
    vector<int> U{1,1,2,2,3,3,3,4,4,5,5,11,11,13,15}, V{2,9,15,3,2,8,4,8,5,6,11,12,13,14,10};
    cout<<"Connected : "<<ifConnected(U, V, 15, 15, 5, 14)<<endl;
    
    return 0;
}
