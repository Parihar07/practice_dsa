//
//  main.cpp
//  graph_ifnodevisited
//
//  Created by CodeBreaker on 21/02/25.
//

/*
 Given undirected graoh, source and destinition, chcek if node destintion can be visited resturn true or false
 */
#include <iostream>
#include <vector>
using namespace std;

bool canbevisited(vector<int> &U, vector<int> &V, int N, int E, int S, int D)
{
    vector<int> adj[N+1];
    vector<bool> vis(N+1,false);
    for(int i=0;i<E;i++)
    {
        adj[U[i]].push_back(V[i]);
        adj[V[i]].push_back(U[i]);
    }
    auto q = queue<int>(); q.push(S);
    
    while(!q.empty())
    {
        int t = q.front(); q.pop();
        if(vis[t]==false)
        {
            for(auto i: adj[t])
            {
                q.push(i); vis[t]=true;
            }
        }
    }
    return vis[D];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, if destintion can be visited !\n";
    vector<int> U{1,1,2,2,3,5,4}, V{2,4,4,3,5,6,5};
    cout<<" Visited : " << "true:"<<true<<"false: "<<false<<canbevisited(U, V, 6, 7, 1, 6) <<endl;
    return 0;
}
