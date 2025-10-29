//
//  main.cpp
//  graphs_BridgesDfs
//
//  Created by CodeBreaker on 07/04/25.
//
/*
 Bridges in a graph
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an undirected graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge between node B[i][0] and node B[i][1].
 You have to find all the bridges in the graph.
 An edge in an undirected connected graph is a bridge if removing it disconnects the graph. For a disconnected undirected graph, the definition is similar, a bridge is an edge removing which increases the number of disconnected components.
 Return an two-dimensional arrays which contains all the edges that are bridges.
 You can return the bridges in any order but for nodes in a bridge order them in ascending order.
 For example:
 If there are 3 bridges in the graph having 7 nodes, (2, 1), (5, 3), (1, 7) Then you can return any one of the following array of array integers:
 [ [1, 2], [3, 5], [1, 7] ]
 [ [1, 2], [1, 7], [3, 5] ]
 [ [3, 5], [1, 2], [1, 7] ]
 [ [3, 5], [1, 7], [1, 2] ]
 [ [1, 7], [1, 2], [3, 5] ]
 [ [1, 7], [3, 5], [1, 2] ]
 NOTE:
 There are no self-loops in the graph.
 There are no multiple edges between two nodes.
 The graph may or may not be connected.
 Nodes are numbered from 1 to A.
 Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


 Problem Constraints
 1 <= A <= 105
 1 <= B[i][0], B[i][1] <= A


 Input Format
 The first argument given is an integer A representing the number of nodes in the graph.
 The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge between node B[i][0] and node B[i][1].


 Output Format
 Return the two-dimensional integer array C where C[i][0] and C[i][1] represents a bridge make sure that C[i][0]<=C[i][1].


 Example Input
 Input 1:
  A = 5
  B = [  [1, 2]
         [4, 1]
         [2, 4]
         [3, 4]
         [5, 2]
         [3, 1] ]
 Input 2:
  A = 5
  B = [  [1, 2]
         [2, 3]
         [3, 4]
         [4, 5] ]


 Example Output
 Output 1:
   [ [2,5] ]
 Output 2:
  [   [1, 2]
      [2, 3]
      [3, 4]
      [4, 5] ]


 Example Explanation
 Explanation 1:
  Edge (2, 5) is the only bridge as removing it graphs breaks down into two component one
     which contains nodes [5] and another with [1, 2, 3, 4].
 Explanation 2:
  Edge (1, 2) is a bridge as removing it graphs breaks down into two component one which contains
     nodes [1] and another with [2, 3, 4, 5].
  Edge (2, 3) is a bridge as removing it graphs breaks down into two component one which contains
     nodes [1, 2] and another with [3, 4, 5].
  Edge (3, 4) is a bridge as removing it graphs breaks down into two component one which contains
     nodes [1, 2, 3] and another with [4, 5].
  Edge (4, 5) is a bridge as removing it graphs breaks down into two component one which contains
     nodes [1, 2, 3, 4] and another with [5].
 */
#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> G[], vector<int> &vis, vector<int> &disc, vector<int> &low, vector<vector<int>> &bridges, int v, int p, int &t)
{
    t++;
    vis[v]=1;
    disc[v]=t;
    low[v]=t;
    for(auto i:G[v])
    {
        if(vis[i]==0)
        {
            DFS(G,vis,disc,low,bridges,i,v,t);
            low[v]=min(low[v],low[i]);
            if(low[i]>disc[v]){
                //its a bridge
                auto vB = vector<int>(2);
                vB[0]=min(i,v); vB[1]=max(i,v);
                bridges.push_back(vB);
            }
        } else if(i!=p){
            low[v]=min(low[v],disc[i]);
        }
    }
}
vector<vector<int> > solve(int A, vector<vector<int> > &B) {
    //creating adjaceny list
    auto E = B.size();
    vector<int> G[A+1]; // starting with 1 for graph representation
    for(int i =0; i<E;i++)
    {
        G[B[i][0]].push_back(B[i][1]);
        G[B[i][1]].push_back(B[i][0]);
    }
    
    //creating discovery, low, visited and list of bridges list
    vector<int> disc(A+1,0), low(A+1,0), vis(A+1,0);
    vector<vector<int>> bridges;
    int t=0;
    for(int i=1;i<=A;i++)
    {
        if(vis[i]==0) DFS(G,vis,disc,low,bridges,i,0,t);
    }
    
    return bridges;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, bridge in graph!\n";
    vector<vector<int>> B{{1,2},{4,1},{2,4},{3,4},{5,2},{3,1}};
    auto ans = solve(5, B);
    for(auto i : ans)
    {
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
