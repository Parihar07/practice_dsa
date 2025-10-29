//
//  main.cpp
//  graphs_cycleindirectedgraph
//
//  Created by CodeBreaker on 18/03/25.
//
/*
 Cycle in Directed Graph
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].
 Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.
 NOTE:
 The cycle must contain atleast two nodes.
 There are no self-loops in the graph.
 There are no multiple edges between two nodes.
 The graph may or may not be connected.
 Nodes are numbered from 1 to A.
 Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


 Problem Constraints
 2 <= A <= 105
 1 <= M <= min(200000,A*(A-1))
 1 <= B[i][0], B[i][1] <= A


 Input Format
 The first argument given is an integer A representing the number of nodes in the graph.
 The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].


 Output Format
 Return 1 if cycle is present else return 0.


 Example Input
 Input 1:
  A = 5
  B = [  [1, 2]
         [4, 1]
         [2, 4]
         [3, 4]
         [5, 2]
         [1, 3] ]
 Input 2:
  A = 5
  B = [  [1, 2]
         [2, 3]
         [3, 4]
         [4, 5] ]


 Example Output
 Output 1:
  1
 Output 2:
  0

 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve(int A, vector<vector<int> > &B) {
    auto E = B.size();
    vector<int> G[A+1];
    //step creating adjacency list
    for(int i=0;i<E;i++)
    {
        G[B[i][0]].push_back(B[i][1]); //directed graph
    }
    
    //step 2 creating dependacny list
    auto dv = vector<int>(A+1);
    for(int i=1;i<=A;i++)
    {
        for(auto n: G[i])
        {
            dv[n]++;
        }
    }
    // chcek and push vertices with no dependancy into Q for BFS
    auto q = queue<int>();
    for(int i=1;i<=A;i++)
    {
        if(dv[i]==0) q.push(i);
    }
    
    //BFS
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        for(auto i:G[t])
        {
            dv[i]--;
            if(dv[i]==0) q.push(i);
        }
    }
    
    //chcek if all vertices are visted
    for(auto i: dv)
    {
        if(i!=0) return 1;
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, cycle in directed graph!\n";
    vector<vector<int>> B{{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};
    cout<<"Cycledetection : "<<solve(5, B)<<endl;
    return 0;
}
