//
//  main.cpp
//  graph_countComponents
//
//  Created by CodeBreaker on 24/02/25.
//

/*
 
 below represents single graph which are not connected, hence component is somethoing which is not connected !
 
    3
   / \
 1  |  4
   \2  /
  \   /
   \ /
    6
 
    9
   / \
  5   8
   \ /
    7
 
 10    12
   \  /
  \ 10 /
   \  /
    14
 
  15---13
  
  16
  
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(vector<int> G[], vector<bool> &vis, int n)
{
    if(vis[n]==true) return;
    vis[n] = true;
    for(auto i: G[n])
    {
        DFS(G,vis,i);
    }
    return;
}

int countComponentsDfs(vector<int> &U, vector<int> &V, int N, int E)
{
    int components = 0;
    vector<int> G[N+1];
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    
    auto vis = vector<bool>(N+1, false);
    for(int i=1;i<N+1;i++)
    {
        if(vis[i]==false)
        {
            DFS(G,vis,i); components++;
        }
    }
    return components;
}

int countComponents(vector<int> &U, vector<int> &V, int N, int E)
{
    vector<int> G[N+1]; //adjanceny list
    auto vis = vector<bool>(N+1, false);
    //creating adjacency list
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    
    auto q=queue<int>();
    q.push(1);
    int components=0;
    while(!q.empty())
    {
        int t=q.front();q.pop();vis[t]=true;
        for(auto i : G[t])
        {
            if(vis[i]==false)
            {
                vis[i]=true;
                q.push(i);
            }
        }
        if(q.empty()==true)
        {
            components++;
            for(int i=1;i<N+1;i++)
            {
                if(vis[i]==false){
                    q.push(i);
                    break;
                }
            }
        }
    }
    return components;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, counting total components...!\n";
    vector<int> U{1,1,1,3,6,5,5,9,7,10,11,11,10,15,3,12}, V{3,2,6,4,4,9,7,8,8,11,12,14,14,13,2,14};
    cout<<"total components : "<<countComponents(U, V, 16, 16)<<endl;
    return 0;
}
