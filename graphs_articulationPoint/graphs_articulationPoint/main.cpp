//
//  main.cpp
//  graphs_articulationPoint
//
//  Created by CodeBreaker on 06/04/25.
//

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> G[], vector<int> &vis, vector<int> &disc, vector<int> &low, vector<int> &ap, int v, int p, int &t)
{
    t++;
    vis[v]=1; disc[v]=t; low[v]=t;
    int child = 0; //need to handle root node separatley for articulation point
    for(auto ch : G[v])
    {
        child++; //if child are above 1 then root node is articulation point
        if(vis[ch]==0)
        {
            DFS(G,vis,disc,low,ap,ch,v,t);
            low[v]= min(low[v], low[ch]); //chceking if childrens are having backedge then there low time will lower
            if(low[ch]>=low[v])
            {
                //articulation point
                ap[v]=1;
            }
        } else if(p!=ch) // backedge case then update the lowest time for the ancestor
        {
            low[v]= min(low[v], low[ch]);
        }
    }
    
    if(p==0 && child > 1){
        ap[v]=1;
    }
    
    return;
}

void articulationPoint(vector<int> &U, vector<int> &V, int N)
{
    //creating adjacency list
    auto E = U.size(); //No of edges
    vector<int> G[N+1]; // vreating graph
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]); // undirected graph
    }
    
    //creating discovery, low discovery, visited, articulation point lists
    vector<int> vis(N+1,0), disc(N+1,0), low(N+1,0), ap(N+1,0);
    
    //Counter for time
    int t = 0;
    
    //Loop while visited list if disjoint componnet will covered
    for(int i=1;i<=N;i++)
    {
        if(vis[i]==0){
            DFS(G, vis, disc, low, ap, i, 0, t);
        }
    }
    
    //print all the details
    for(int i=1; i<=N; i++)
    {
        cout<<i<<"-"<<disc[i]<<"-"<<low[i]<<"-"<<ap[i]<<endl;
    }
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, getting articulation point!\n";
    vector<int> U{ 1,1,2,2,2,3,3,4,6,2,8,8 }, V{ 2,7,3,8,4,4,6,5,7,8,9,10,11};
    articulationPoint(U, V, 11);
    return 0;
}
