//
//  main.cpp
//  graph_topoSort
//
//  Created by CodeBreaker on 17/03/25.
//

/*
 opological Sort
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an directed acyclic graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].
 Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
 Return the topological ordering of the graph and if it doesn't exist then return an empty array.
 If there is a solution return the correct ordering. If there are multiple solutions print the lexographically smallest one.
 Ordering (a, b, c) is said to be lexographically smaller than ordering (e, f, g) if a < e or if(a==e) then b < f and so on.
 NOTE:
 There are no self-loops in the graph.
 The graph may or may not be connected.
 Nodes are numbered from 1 to A.
 Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


 Problem Constraints
 2 <= A <= 104
 1 <= M <= min(100000,A*(A-1))
 1 <= B[i][0], B[i][1] <= A


 Input Format
 The first argument given is an integer A representing the number of nodes in the graph.
 The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].


 Output Format
 Return a one-dimensional array denoting the topological ordering of the graph and it it doesn't exist then return empty array.


 Example Input
 Input 1:
  A = 6
  B = [  [6, 3]
         [6, 1]
         [5, 1]
         [5, 2]
         [3, 4]
         [4, 2] ]
 Input 2:
  A = 3
  B = [  [1, 2]
         [2, 3]
         [3, 1] ]


 Example Output
 Output 1:
  [5, 6, 1, 3, 4, 2]
 Output 2:
  []


 Example Explanation
 Explanation 1:
  The given graph contain no cycle so topological ordering exists which is [5, 6, 1, 3, 4, 2]
 Explanation 2:
  The given graph contain cycle so topological ordering not possible we will return empty array.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Handling lexicographically
vector<int> solve2(int A, vector<vector<int> > &B) {
//    auto ans = vector<int>();
//    //Creating adjacecy list
//    vector<int> G[A+1];
//    auto E = B.size();
//    for(int i=0;i<E;i++)
//    {
//        G[B[i][0]].push_back(B[i][1]); //directed graph
//    }
//    
//    //Creating dependency vector
//    auto dv = vector<int>(A+1, 0);
//    for(int i=1;i<=A;i++)
//    {
//        for(auto n: G[i])
//        {
//            dv[n]++;
//        }
//    }
//    
//    //prepare for traversal by creating Q
//    auto q = priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> >();
//    for(int i=1;i<=A;i++)
//    {
//      q.push({dv[i],i});
//    }
//    
//    //BFS traversal
//    while(!q.empty())
//    {
//        auto t = q.top(); q.pop();
//        ans.push_back(t.second);
//        for(auto i : G[t.second])
//        {
//            if(dv[i]!=0){
//                dv[i]--;
//                q.push({dv[i],i});
//            }
//        }
//    }
//    
//    for(auto i:dv)
//    {
//        if(i!=0) return vector<int>();
//    }
//    
//    vector<int> res(ans.begin(), ans.begin()+A);
//    return res;
    auto ans = vector<int>();
        //Creating adjacecy list
        vector<int> G[A+1];
        auto E = B.size();
        for(int i=0;i<E;i++)
        {
            G[B[i][0]].push_back(B[i][1]); //directed graph
        }
        
        //Creating dependency vector
        auto dv = vector<int>(A+1, 0);
        for(int i=1;i<=A;i++)
        {
            for(auto n: G[i])
            {
                dv[n]++;
            }
        }
        
        //prepare for traversal by creating Q
        auto q = priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> >();
        for(int i=1;i<=A;i++)
        {
            if(dv[i]==0)
                q.push({i,dv[i]});
        }
        
        //BFS traversal
        while(!q.empty())
        {
            auto t = q.top(); q.pop();
            ans.push_back(t.first);
            for(auto i : G[t.first])
            {
                if(dv[i]!=0){
                    dv[i]--;
                    if(dv[i]==0)
                        q.push({i,dv[i]});
                }
            }
        }
        
        for(auto i:dv)
        {
            if(i!=0) return vector<int>();
        }
        
       return ans;
}


vector<int> solve(int A, vector<vector<int> > &B) {
    auto ans = vector<int>(A, -1);
    //Creating adjacecy list
    vector<int> G[A+1];
    auto E = B.size();
    for(int i=0;i<E;i++)
    {
        G[B[i][0]].push_back(B[i][1]); //directed graph
    }
    
    //Creating dependency vector
    auto dv = vector<int>(A+1, 0);
    for(int i=1;i<=A;i++)
    {
        for(auto n: G[i])
        {
            dv[n]++;
        }
    }
    
    //prepare for traversal by creating Q
    auto q = queue<int>();
    for(int i=1;i<=A;i++)
    {
        if(dv[i]==0) q.push(i);
    }
    
    //BFS traversal
    int node=0;
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        ans[node++]=t;
        for(auto i : G[t])
        {
            dv[i]--;
            if(dv[i]==0)
            {
                q.push(i);
            }
        }
    }
    
    for(auto i:ans)
    {
        if(i==-1) return vector<int>();
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, topological sorting of graoh!\n";
    vector<vector<int>> B{{6,3},{6,1},{5,1},{5,2},{3,4},{4,2}};
    auto ans = solve2(6, B);
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
