//
//  main.cpp
//  graph_MSTEdges
//
//  Created by CodeBreaker on 28/03/25.
//
/*
 Edge in MST
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
Given a undirected weighted graph with A nodes labelled from 1 to A with M edges given in a form of 2D-matrix B of size M * 3 where B[i][0] and B[i][1] denotes the two nodes connected by an edge of weight B[i][2].
For each edge check whether it belongs to any of the possible minimum spanning tree or not , return 1 if it belongs else return 0.
Return an one-dimensional binary array of size M denoting answer for each edge.
NOTE:
The graph may be disconnected in that case consider mst for each component.
No self-loops and no multiple edges present.
Answers in output array must be in order with the input array B output[i] must denote the answer of edge B[i][0] to B[i][1].


Problem Constraints
1 <= A, M <= 3*105
1 <= B[i][0], B[i][1] <= A
1 <= B[i][1] <= 103


Input Format
The first argument given is an integer A representing the number of nodes in the graph.
The second argument given is an matrix B of size M x 3 which represents the M edges such that there is a edge between node B[i][0] and node B[i][1] with weight B[i][2].


Output Format
Return an one-dimensional binary array of size M denoting answer for each edge.


Example Input
Input 1:
 A = 3
 B = [ [1, 2, 2]
       [1, 3, 2]
       [2, 3, 3]
     ]


Example Output
Output 1:
 [1, 1, 0]


Example Explanation
Explanation 1:
 Edge (1, 2) with weight 2 is included in the MST           1
                                                          /   \
                                                         2     3
 Edge (1, 3) with weight 2 is included in the same MST mentioned above.
 Edge (2,3) with weight 3 cannot be included in any of the mst possible.
 So we will return [1, 1, 0]
 */
#include <iostream>
#include <vector>
using namespace std;

int findComp(int v, vector<int> &c)
{
    if(v==c[v]) return v;
    c[v]=findComp(c[v], c);
    return c[v];
}

vector<int> solve(int A, vector<vector<int> > &B) {
    auto E = B.size();
    auto ans = vector<int>(E,0);
    //step 1- Creating edges based on edges edges
    auto edges = vector<pair<int, pair<int, int>>>(E);
    for(int i=0;i<E;i++)
    {
        auto edge = make_pair(B[i][2], make_pair(B[i][0], B[i][1]));
        edges[i] = edge;
    }
    sort(edges.begin(), edges.end());
    //step 2- creating component root components
    auto comp = vector<int>(A+1);
    for(int i=0;i<=A;i++) comp[i]=i;
    
    //step 3 - edges in MST graph
    auto mstEdges = vector<pair<pair<int,int>, int>>();
    
    //step 4 - iterate of edges by picking lesser weight first
    for(int i=0;i<E;i++)
    {
        auto u = edges[i].second.first, cu = findComp(u, comp);
        auto v = edges[i].second.second, cv = findComp(v, comp);
        auto w = edges[i].first;
        if(cu!=cv)
        {
            comp[max(cu,cv)] = comp[min(cu,cv)];
            pair<pair<int, int>,int> ed{{u,v},w};
            mstEdges.push_back(ed);
        }
    }
    
    //step 5- creating adjaceny list to traverse and mark the given edges in ans list
    vector<int> mstG[A+1];
    for(int i=0;i<mstEdges.size();i++)
    {
        auto u = mstEdges[i].first.first, v = mstEdges[i].first.second;
        mstG[u].push_back(v);
        mstG[v].push_back(u);
    }
    
    //Fullfiling the ask like if edges are present in mst
    for(int i=1;i<=A;i++)
    {
        for(auto k : mstG[i])
        {
            for(int j=0;j<E;j++)
            {
                if(B[j][0]==i && B[j][1]==k) ans[j]=1;
                else if(B[j][0]==k && B[j][1]==i) ans[j]=1;
            }
        }
    }
    
    return ans;
}

vector<int> solve2(int A, vector<vector<int>> &B) {
//    int E = B.size();
//       vector<int> ans(E, 0);
//       // Store {weight, {originalIndex, {u, v}}}
//       vector<pair<int, pair<int, pair<int, int>>>> edges(E);
//
//       // Store original indices
//       for(int i = 0; i < E; i++) {
//           edges[i] = {B[i][2], {i, {B[i][0], B[i][1]}}};
//       }
//       sort(edges.begin(), edges.end());
//
//       int i = 0;
//       while(i < E) {
//           int currWeight = edges[i].first;
//           vector<int> comp(A + 1);
//           for(int j = 0; j <= A; j++) comp[j] = j;
//
//           // Connect all edges of less weight
//           for(int j = 0; j < i; j++) {
//               int u = edges[j].second.second.first;
//               int v = edges[j].second.second.second;
//               int cu = findComp(u, comp);
//               int cv = findComp(v, comp);
//               if(cu != cv) comp[cv] = cu;
//           }
//
//           // Process current weight edges
//           int j = i;
//           while(j < E && edges[j].first == currWeight) {
//               int u = edges[j].second.second.first;
//               int v = edges[j].second.second.second;
//               int origIndex = edges[j].second.first;
//               int cu = findComp(u, comp);
//               int cv = findComp(v, comp);
//               if(cu != cv) {
//                   ans[origIndex] = 1;
//               }
//               j++;
//           }
//           i = j;
//       }
//       return ans;
    int E = B.size();
    vector<int> ans(E, 0);
    
    // Sort edges by weight, keeping original indices
    vector<pair<int, int>> edges(E);
    for(int i = 0; i < E; i++) {
        edges[i] = {B[i][2], i};
    }
    sort(edges.begin(), edges.end());
    
    vector<int> comp(A+1);
    for(int i = 0; i <= A; i++) comp[i] = i;
    
    int i = 0;
    while(i < E) {
        int currWeight = edges[i].first;
        vector<int> tempComp = comp;
        
        // Find components without current weight edges
        int j = i;
        while(j < E && edges[j].first == currWeight) {
            int idx = edges[j].second;
            int u = B[idx][0], v = B[idx][1];
            int cu = findComp(u, tempComp);
            int cv = findComp(v, tempComp);
            if(cu != cv) {
                ans[idx] = 1;
            }
            j++;
        }
        
        // Connect components using current weight edges
        j = i;
        while(j < E && edges[j].first == currWeight) {
            int idx = edges[j].second;
            int u = B[idx][0], v = B[idx][1];
            int cu = findComp(u, comp);
            int cv = findComp(v, comp);
            if(cu != cv) {
                comp[cv] = cu;
            }
            j++;
        }
        i = j;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Chceking if all edges are prestin in MST!\n";
    vector<vector<int>> A{{1,2,2},{1,4,2},{2,3,2},{3,5,3},{2,6,1},{4,3,2}};
    auto ans = solve2(6, A);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
