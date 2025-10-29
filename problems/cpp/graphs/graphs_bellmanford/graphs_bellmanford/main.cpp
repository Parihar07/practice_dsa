//
//  main.cpp
//  graphs_bellmanford
//
//  Created by CodeBreaker on 20/03/25.
//
/*
 Graphs haveing negative edges cannot be solved by Bellman ford Algorithm i.e. you need to iterate through the edges nodes -1 time to get hortest path for the corresponding vertices
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int> &U, vector<int> &V, vector<int> &W, int S, int N)
{
    // step one create distance vector with infinite values as we are getting lowest distance
    auto dv = vector<int>(N+1, INT_MAX);
    dv[S]=0;
    auto E = U.size();
    for(int i=1;i<N;i++)
    {
        auto change = false;
        for(int i=0;i<E;i++)
        {
            auto u=U[i], v=V[i], w=W[i];
            //Distance at vertex V via vertex U ( U -> V ) with weight W is dv[u] + w
            auto distance = (dv[u]==INT_MAX ? 0 : dv[u]) + w;
            if(dv[v]>distance)
            {
                dv[v]=distance; change=true;
            }
        }
        if(change==false) break;
    }
    vector<int> res(dv.begin()+1, dv.end());
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Bellman Ford algorithm!\n";
    vector<int> U{1,1,1,4,4,3,2,5};
    vector<int> V{2,3,4,3,6,2,5,6};
    vector<int> W{6,4,5,-2,1,-2,-1,3};
    auto ans = solve(U, V, W, 1, 6);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
