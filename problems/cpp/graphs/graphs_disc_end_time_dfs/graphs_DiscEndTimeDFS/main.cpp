//
//  main.cpp
//  graphs_DiscEndTimeDFS
//
//  Created by CodeBreaker on 05/04/25.
//

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> G[], vector<int> &disc, vector<int> &end, vector<int> &vis, int v)
{
    static int t=0;
    disc[v]=t++;
    vis[v]=1;
    for(auto i: G[v])
    {
        if(vis[i]==0)
        {
            DFS(G,disc,end,vis,i);
        }
    }
    end[v]=t++;
    return;
}
void getDescEndTime(vector<int> &U, vector<int> &V, int N)
{
    //Creating Adjacency list
    vector<int> G[N+1];
    auto E = U.size();
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    
    //creating discovery, endtime and visited list
    vector<int> disc(N+1,0), end(N+1,0), vis(N+1,0);
    
    DFS(G,disc,end,vis,1);
    
    for(int i=0;i<disc.size();i++)
    {
        cout<<i<<"-"<<disc[i]<<"-"<<end[i]<<endl;
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Getting discovery time and end visted time of nodes!\n";
    vector<int> U{1,2,2,3,3,4,6,8,8,8}, V{2,3,8,4,6,5,7,9,10,11};
    getDescEndTime(U, V, 11);
    return 0;
}
