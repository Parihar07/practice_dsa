//
//  main.cpp
//  graphs_multiplesourcesdistance
//
//  Created by CodeBreaker on 26/02/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> multiSourceDistance(vector<int> &U, vector<int> &V, int s1, int s2, int s3, int N, int E)
{
    vector<int> G[N+1];
    for(int i=0;i<E;i++)
    {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    auto q = queue<pair<int, int>>();
    q.push({s1,0});q.push({s2,0}),q.push({s3,0});
    auto distance = vector<int>(N+1, -1);
    distance[s1]=0;distance[s2]=0;distance[s3]=0;
    while(!q.empty())
    {
        auto t = pair<int, int>();
        t = q.front(); q.pop();
        for(auto i : G[t.first])
        {
            if(distance[i]==-1){
                q.push({i,t.second+1});
                distance[i]=t.second+1;
            }
        }
    }
    return distance;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, multiple sources in graph and sortest distance...!\n";
    
    vector<int> U{2,2,3,3,9,13,10,7,8,4,5,11,11}, V{3,5,12,9,13,10,7,8,4,5,11,6,1};
    auto as = multiSourceDistance(U, V, 11, 7, 2, 13, 13);
    cout<<"distance from s to d " << as[13] <<endl;
    return 0;
}
