//
//  main.cpp
//  graph_checkBiparte
//
//  Created by CodeBreaker on 06/03/25.
//
/*
 Check Bipartite Graph
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a undirected graph having A nodes. A matrix B of size M x 2 is given which represents the edges such that there is an edge between B[i][0] and B[i][1].
 Find whether the given graph is bipartite or not.
 A graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B
 Note:
 There are no self-loops in the graph.
 No multiple edges between two pair of vertices.
 The graph may or may not be connected.
 Nodes are Numbered from 0 to A-1.
 Your solution will run on multiple testcases. If you are using global variables make sure to clear them.


 Problem Constraints
 1 <= A <= 100000
 1 <= M <= min(A*(A-1)/2,200000)
 0 <= B[i][0],B[i][1] < A


 Input Format
 The first argument given is an integer A.
 The second argument given is the matrix B.


 Output Format
 Return 1 if the given graph is bipartide else return 0.


 Example Input
 Input 1:
 A = 2
 B = [ [0, 1] ]
 Input 2:
 A = 3
 B = [ [0, 1], [0, 2], [1, 2] ]


 Example Output
 Output 1:
 1
 Output 2:
 0


 Example Explanation
 Explanation 1:
 Put 0 and 1 into 2 different subsets.
 Explanation 2:
  
 It is impossible to break the graph down to make two different subsets for bipartite matching
 */
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int solve(int A, vector<vector<int> > &B) {
    vector<int> G[A];
    for(int i=0;i<B.size();i++)
    {
        G[B[i][0]].push_back(B[i][1]);
        G[B[i][1]].push_back(B[i][0]);
    }
    auto q=queue<int>();
    auto cv=vector<int>(A,0);
    q.push(0);cv[0]=1;
    while(!q.empty())
    {
        auto t = q.front();q.pop();
        for(auto i:G[t])
        {
            if(cv[i]==0)
            {
                cv[i]=3-cv[t];
                q.push(i);
            } else if(cv[i]!=cv[t]) {
                return 0;
            }
        }
        if(q.empty()==true)
        {
            for(int j=0;j<A;j++)
            {
                if(cv[j]==0)
                {
                    q.push(j);
                    cv[j]=1; break;
                }
            }
        }
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, chceking bipartideness!\n";
    vector<vector<int>> B{{0,1},{0,2},{1,2}};
    cout<<"If biparte graph : "<<solve(3, B)<<endl;
    
    return 0;
}
