//
//  main.cpp
//  graph_cycleBellMenFord
//
//  Created by CodeBreaker on 20/03/25.
//

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &U, vector<int> &V, vector<int> &W, int N, int S)
{
    //bellman ford algo to fidn cycle. AS per theory when we iterate through the edges for N-1 times N being here numbre of nodes of graphthen we should b able to get the shortest path of each node to the given source node. applying same here we will itreate N time and if see we sre still see values are changing for each node then it is confirmed there is cycle in the graph
    // hence will traverse on edges here will not create Adjacency list
    auto E = U.size();
    //creating distance vector
    auto dv = vector<int>(N+1, INT_MAX); // here we are finding min so we will initalize with infinite
    dv[S]=0;
    for(int i=1;i<=N;i++)
    {
        auto change = false;
        for(int e=0;e<E;e++){
            auto u = U[e], v=V[e], w=W[e];
            //distance at node v from u is dv[u]+w;
            auto distance = (dv[u]==INT_MAX?0:dv[u])+w;
            if(dv[v]>distance)
            {
                dv[v]=distance; change=true;
            }
        }
        if(!change) return false; // early temination if you see no change
        if(i==N && change==true) return true; //cycle exists
    }
   
    return false; //No cycle
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
