//
//  main.cpp
//  graph_petrolbunkblast
//
//  Created by CodeBreaker on 14/03/25.
//
/*
 Petrol bunk blast
 -- Nodes indicates petrol bunks
 -- Edge indicates time taken to burn the adjacent node
 -- Initially Bunk is blasted
 -- Calculate the time at which each bunk is blasted
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> blastedTimes(vector<int> &U, vector<int> &V, vector<int> &W, int N, int E)
{
    //Create adjacency list
    vector<pair<int, int>> G[N+1]; // pair< vertex, distance/time>
    for(int i=0; i<E;i++)
    {
        G[U[i]].push_back({V[i],W[i]});
        G[V[i]].push_back({U[i],W[i]});
    }
    
    //creating time array and min heap to iterate or traverse
    auto minHeap = priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>(); // pair here is combinition of <time, vertex>
    auto tv = vector<int>(N+1, INT_MAX); // we are taking INT_MAX as we want to get min time at each vertices
    minHeap.push({0,1}); // time at vertex 1 is 0;
    tv[1]=0;
    
    //Traverse and pick the vertex which has shorter time
    while(!minHeap.empty())
    {
        auto tmp = minHeap.top(); minHeap.pop();
        for(auto [ver, time] : G[tmp.second])
        {
            int timeTaken = time + tmp.first;
            if(tv[ver]>timeTaken)
            {
                tv[ver]=timeTaken;
                minHeap.push({timeTaken,ver});
            }
        }
    }
    vector<int> ans(tv.begin()+1,tv.end());
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Petrol bunk blas problem !\n";
    vector<int> U{1,1,1,2,2,2,3,7,7,4}, V{4,2,7,7,3,6,6,6,5,7}, W{8,4,2,1,5,9,1,4,6,3};
    auto ans = blastedTimes(U, V, W, 7, 10);
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
