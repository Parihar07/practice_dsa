//
//  main.cpp
//  graph_getPathParenttable
//
//  Created by CodeBreaker on 23/02/25.
//
/*
 given undirected path U to V arrays find shorteset path using parent table
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<int> &U, vector<int> &V, int N, int E, int S, int D)
{
    vector<int> G[N+1];
    auto parenttable = vector<int>(N+1,0);
    //building grapgh adjancency list
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    
    auto q = queue<int>();
    q.push(S);parenttable[S]=-1;
    int ans=0;
    while(!q.empty())
    {
        int t = q.front(); q.pop();
        for(auto i : G[t])
        {
            if(parenttable[i]==0)
            {
                parenttable[i] = t;
                q.push(i);
            }
        }
    }
    int x=D;
    while(x!=-1)
    {
        x=parenttable[x];
        ans++;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Getting shortest path using parent table..!\n";
    vector<int> U{5,5,5,7,7,7,9,9,3,3,1,2,2,4,4,11}, V{7,8,11,9,10,8,10,3,6,1,2,4,6,6,11,8};
    cout<<"Shortest distance : " << shortestPath(U, V, 11, 16, 10, 2)<<endl;
    return 0;
}
