//
//  main.cpp
//  graph_cycledetectiondirectedgraph
//
//  Created by CodeBreaker on 13/03/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool cycleDetectionDirectedGraph(vector<int> &U, vector<int> &V, int N, int E)
{
    //Create Adjacency list
    vector<int> G[N+1];
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]); //directed graph
    }
    
    //Create Dependancy list;
    auto dv = vector<int>(N+1,0);
    for(int i=1;i<=N;i++)
    {
        for(auto n:G[i])
        {
            dv[n]++;
        }
    }
    
    // Push no devependant vertices into Queue
    auto q = queue<int>();
    for(int i=1;i<=N;i++)
    {
        if(dv[i]==0) q.push(i);
    }
    
    // BFS
    
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        for(auto i: G[t])
        {
            dv[i]--;
            if(dv[i]==0) q.push(i);
        }
    }
    
    //Cycle detection if there all tasks are not executed then then there is presence of cycle
    for(auto i:dv)
    {
        if(i!=0) return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Cycle detection in directed graph!\n";
    vector<int> U{8,2,9,2,2,3,7,7,3,3,4,10}, V{2,1,1,7,3,7,6,5,5,4,10,3};
    cout<<"If cycle is found : "<<cycleDetectionDirectedGraph(U, V, 10, 12)<<" true : "<<true<<" false : "<<false<<endl;
    return 0;
}
