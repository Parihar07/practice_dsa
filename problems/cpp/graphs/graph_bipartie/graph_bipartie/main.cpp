//
//  main.cpp
//  graph_bipartie
//
//  Created by CodeBreaker on 04/03/25.
//

/*
 Biparte Graph, A graph which has chromatic number 2 then ot is called Biparte Graph,
 Chromatic Number, Minimum number required to color all the vertices of graph is chromatic number, where no two adjacent vertices have same color
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bipartie(vector<int> &U, vector<int> &V, int N, int E)
{
    auto cv = vector<int>(N+1,0);
    vector<int> G[N+1];
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    auto q = queue<int>();
    q.push(1);
    cv[1]=1;
    while(!q.empty())
    {
        int t = q.front(); q.pop();
        for(auto i:G[t])
        {
            if(cv[i]==0)
            {
                cv[i]=3-cv[t];
                q.push(i);
            } else if(cv[i]==cv[t]){
                return false; //expected color should be different here !
                
            }
        }
        
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Biparte Graph!\n";
    vector<int> U{1,1,2,2,5,4,9,8,3,6}, V{2,9,3,5,4,7,8,7,6,7};
    cout<<"if Biparte : "<<(bipartie(U, V, 9, 10) ? "true" : "false")<<endl;
    return 0;
}
