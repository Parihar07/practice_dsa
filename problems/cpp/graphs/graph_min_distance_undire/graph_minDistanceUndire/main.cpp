//
//  main.cpp
//  graph_minDistanceUndire
//
//  Created by CodeBreaker on 17/03/25.
//
/*
 Dijkstra
Solved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
Given a weighted undirected graph having A nodes and M weighted edges, and a source node C.
You have to find an integer array D of size A such that:
D[i]: Shortest distance from the C node to node i.
If node i is not reachable from C then -1.
Note:
There are no self-loops in the graph.
There are no multiple edges between two pairs of vertices.
The graph may or may not be connected.
Nodes are numbered from 0 to A-1.
Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.


Problem Constraints
1 <= A <= 1e5
0 <= B[i][0],B[i][1] < A
0 <= B[i][2] <= 1e3
0 <= C < A


Input Format
The first argument is an integer A, representing the number of nodes in the graph.
The second argument is a matrix B of size M x 3, where each row represents an edge in the graph. The three columns of each row denote the source node B[i][0], the destination node B[i][1], and the weight of the edge B[i][2].
The third argument is an integer C, representing the source node for which the shortest distance to all other nodes needs to be found.


Output Format
Return the integer array D.


Example Input
Input 1:
A = 6
B = [   [0, 4, 9]
        [3, 4, 6]
        [1, 2, 1]
        [2, 5, 1]
        [2, 4, 5]
        [0, 3, 7]
        [0, 1, 1]
        [4, 5, 7]
        [0, 5, 1] ]
C = 4
Input 2:
A = 5
B = [   [0, 3, 4]
        [2, 3, 3]
        [0, 1, 9]
        [3, 4, 10]
        [1, 3, 8]  ]
C = 4


Example Output
Output 1:
D = [7, 6, 5, 6, 0, 6]
Output 2:
D = [14, 18, 13, 10, 0]


Example Explanation
Explanation 1:
 All Paths can be considered from the node C to get shortest path
Explanation 2:
 All Paths can be considered from the node C to get shortest path
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> solve(int A, vector<vector<int> > &B, int C) {
    //create adjacency list
    vector<pair<int, int>> G[A]; // pair <node, distance>
    auto E = B.size(); //Edges
    for(int i=0;i<E;i++)
    {
        G[B[i][0]].push_back({B[i][1], B[i][2]}); //fromNode - > toNode with weight
        G[B[i][1]].push_back({B[i][0], B[i][2]}); //Undirected graph
    }
    
    //create distance vector
    auto dv = vector<int>(A,INT_MAX);
    dv[C]=0; // source node to calculate distance from
    auto minHeap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >();
    minHeap.push({0,C}); // we have to pick shortest distance form the given source so will push adjacent node of source and pick one
    
    while(!minHeap.empty())
    {
        auto [dis, ver] = minHeap.top(); minHeap.pop();
        for(auto [v, d] : G[ver])
        {
            auto totalDistance = dis+d;
            if(dv[v]>totalDistance)
            {
                dv[v]=totalDistance;
                minHeap.push({totalDistance,v});
            }
        }
    }
    for(auto &i : dv)
    {
        if(i==INT_MAX)
            i=-1;
    }
    return dv;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Dijekstra Algorithm min distance in undireccted graph given soiurce at each node!\n";
    vector<vector<int>> B{
        {0,4,9},
        {3,4,6},
        {1,2,1},
        {2,5,1},
        {2,4,5},
        {0,3,7},
        {0,1,1},
        {4,5,7},
        {0,5,1}};
    auto ans = solve(6, B, 4);
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
