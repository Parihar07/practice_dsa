//
//  main.cpp
//  graph_toplogicalSort
//
//  Created by CodeBreaker on 13/03/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(vector<int> &U, vector<int> &V, int N, int E)
{
    vector<int> ans;
    //create adjacency list
    vector<int> G[N+1];
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]); //direccted graph
    }
    
    //dependancy vector
    auto dv = vector<int>(N+1,0); //initalizing with zero
    for(int i=1;i<N;i++)
    {
        for(auto &i:G[i])
        {
            dv[i]++;
        }
    }
    
    //push all the vertices having no dependency to start with
    auto q = queue<int>();
    for(int i=1;i<N;i++)
    {
        if(dv[i]==0) q.push(i);
    }
    
    //BFS
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        ans.push_back(t);
        for(auto &i:G[t])
        {
            dv[i]--;
            if(dv[i]==0) q.push(i);
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Topological Sort!\n";
    vector<int> U{9,8,2,2,2,3,10,3,3,7,7}, V{1,2,1,7,3,7,3,4,5,6,5};
    auto ans = topologicalSort(U, V, 10, 11);
    for(auto &i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
