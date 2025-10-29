//
//  main.cpp
//  graphs_articulationPointDfs
//
//  Created by CodeBreaker on 07/04/25.
//
/*
 Articulation Points
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an undirected graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge between node B[i][0] and node B[i][1].
 You have to find all the Articulation Points in the graph.
 A vertex in an undirected connected graph is an articulation point iff removing it (and edges through it) disconnects the graph.
 For a disconnected undirected graph, an articulation point is a vertex removing which increases number of connected components.
 Return an one-dimensional array which contains all the Articulation Points .
 You can return the Articulation points in any order.
 NOTE:
 There are no self-loops in the graph.
 There are no multiple edges between two nodes.
 The graph may or may not be connected.
 Nodes are numbered from 1 to A.
 Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


 Problem Constraints
 1 <= A, M <= 3×105
 1 <= B[i][0], B[i][1] <= A


 Input Format
 The first argument given is an integer A representing the number of nodes in the graph.
 The second argument given is an matrix B of size M x 2 which represents the M edges such that there is a edge between node B[i][0] and node B[i][1].


 Output Format
 Return an one-dimensional array which contains all the Articulation Points .


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
  [2]
 Output 2:
  [2, 3, 4]


 Example Explanation
 Explanation 1:
  Node 2 is the only articulation point in the graph as removing it graphs breaks down into two
     component one which contains nodes [5] and another with [1, 3, 4].
 Explanation 2:
  
  Node 2 is an articulation point in the graph as removing it graphs breaks down into two component,
     one which contains nodes [1] and another with [3, 4, 5].
  Node 3 is an articulation point in the graph as removing it graphs breaks down into two component,
     one which contains nodes [1, 2] and another with [4, 5].
  Node 4 is an articulation point in the graph as removing it graphs breaks down into two component,
     one which contains nodes [1, 2, 3] and another with [5].

 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void DFS(vector<int> G[], vector<int> &vis, vector<int> &disc, vector<int> &low, unordered_set<int> &ap, int v, int p, int &t)
{
    t++;
    vis[v]=1;
    disc[v]=t;
    low[v]=t;
    
    int child =0; //to handle root nodes
    for(auto i:G[v])
    {
        if(vis[i]==0)
        {
            child++;
            DFS(G,vis,disc,low,ap,i,v,t);
            low[v]=min(low[v],low[i]);
            if(p!=0 && low[i]>=disc[v]){ // articulation point if child has greater or equal time to reach ancestor then it connected/dependant on parent hence articulation point
                ap.insert(v);
            }
        } else if(i!=p)
        {
            low[v]=min(low[v],disc[i]);
        }
    }
    if(p==0 && child>1) ap.insert(v); // if root is having more than two child delete it will create multiple independant components
    return;
}

vector<int> solve(int A, vector<vector<int> > &B) {
    //creating adjanceny list
    auto E = B.size(); // number of edges
    vector<int> G[A+1]; // starting node as 1
    for(int i=0;i<E;i++)
    {
        G[B[i][0]].push_back(B[i][1]);
        G[B[i][1]].push_back(B[i][0]);
    }
    
    //creating discovery, lowest, visited, articulation pont list
    vector<int> disc(A+1,0), low(A+1,0), vis(A+1,0);
    //to handle unique values
    unordered_set<int> setAp;
    int t = 0; // timer
    for(int i=1;i<=A;i++)
    {
        if(vis[i]==0) DFS(G,vis,disc,low,setAp,i,0,t);
    }
    vector<int> ap(setAp.begin(), setAp.end());
    return ap;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Articulation point!\n";
    vector<vector<int>> B{{44,57},{57,59},{1,27},{4,50},{31,68},{53,58},{50,60},{1,50},{7,70},{23,52},{19,61},{30,65},{36,42},{14,48},{29,61},{4,58},{38,58},{31,33},{22,26},{54,63},{6,48},{16,31},{17,27},{26,33},{16,21},{24,59},{5,28},{41,54},{35,51},{16,64},{25,42},{35,37},{20,53},{6,26},{48,55},{21,44},{28,58},{9,46},{18,42},{29,63},{16,65},{27,47},{6,63},{31,36},{57,71},{11,43},{29,34},{4,69},{25,36},{7,59},{38,47},{31,53},{7,52},{9,23},{61,62},{40,71},{38,55},{15,67},{13,26},{35,67},{64,67},{7,67},{4,51},{29,62},{27,60},{33,56},{7,66},{5,30},{21,46},{15,54},{30,33},{47,50},{35,52},{26,45},{16,51},{20,65},{7,61},{31,60},{12,57},{12,16},{23,50},{43,59},{4,52},{21,57},{43,69},{14,17},{56,60},{45,69},{28,30},{53,72},{8,50},{8,40},{2,58},{16,47},{14,56},{35,65},{10,29},{7,14},{37,57},{43,50},{26,54},{41,59},{33,38},{34,39},{31,69},{44,50},{33,55},{49,56},{12,14},{45,66},{28,57},{45,61},{64,68},{12,24},{25,34},{11,58},{9,28},{11,70},{47,62},{24,45},{56,59},{9,70},{51,63},{50,57},{41,70},{33,48},{20,43},{40,67},{16,61},{19,28},{67,68},{32,45},{21,49},{67,72},{7,16},{8,36},{20,69},{6,29},{27,49},{2,60},{21,67},{17,61},{29,31},{47,58},{16,71},{4,63},{49,58},{41,66},{3,40},{46,59},{14,36},{43,56},{14,42},{63,69},{19,40},{56,70},{19,38},{15,24},{15,70}};
    auto ans = solve(72, B);
    for(auto i : ans)
    {
        cout<<i<<endl;
    }
    return 0;
}
