//
//  main.cpp
//  graph_lenghtofshortpath
//
//  Created by CodeBreaker on 22/02/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<int> &U, vector<int> &V, int N, int E, int S, int D)
{
    vector<int> adjList[N+1];
    auto level = vector<int>(N+1,0);
    auto vis = vector<bool>(N+1, false);
    auto q = queue<int>();
    //adjacancy list
    for(int i=0; i<E; i++)
    {
        adjList[U[i]].push_back(V[i]);
        adjList[V[i]].push_back(U[i]);
    }
    
    //main logic
    int l=0;//level
    q.push(S);vis[S]=true;level[S]=0;
    while(!q.empty())
    {
        int t=q.front(); q.pop();
        l++;
        for(auto i: adjList[t])
        {
            if(vis[i]==false){
                vis[i]=true;
                level[i]=l;
                q.push(i);
            }
        }
    }
    return level[D];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Graph shortest path.!\n";
    vector<int> U{1,1,2,2,3,5,4}, V{2,4,4,3,5,6,5};
    cout<<" Visited : "<<shortestPath(U, V, 6, 7, 1, 6) <<endl;
    return 0;
}
