//
//  main.cpp
//  graphs_diameterofbridge
//
//  Created by CodeBreaker on 08/04/25.
//
/*
 Diameter of Bridge Tree
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a undirected graph with A nodes labelled from 1 to A containing M edges given in a form of 2D-matrix B of size M * 2 where there is a edge between node B[i][0] and B[i][1]
 For the given graph, the edges, which on deletion do not disconnect the graph are compressed into a node and the edges which on deletion disconnect the graph form an edge between these nodes.
 The resultant structure will be a tree of course!
 You have to find and return the diameter of this resultant tree.
 NOTE:
 Input graph is connected.
 No multiple edges and self loops are present.
 Diameter of a tree is defined as the number of edges on the longest path in the tree.


 Problem Constraints

 1 <= A <= 3*105
 A-1 <= M <= 3*105


 Input Format

 The first argument given is an integer A representing the number of nodes in the graph.
 The second argument given is an matrix B of size M x 2 which represents the M edges such that there is a edge between node B[i][0] and node B[i][1].


 Output Format

 Return a single integer denoting the diameter of the resultant tree.


 Example Input

 Input 1:
  A = 4
  B = [ [1, 2]
        [1, 3]
        [2, 4]
      ]
 Input 2:
  A = 6
  B = [ [1, 2]
        [2, 3]
        [3, 1]
        [3, 4]
        [4, 5]
        [5, 6]
        [6, 4]
      ]


 Example Output

 Output 1:
  3
 Output 2:
  1


 Example Explanation

 Explanation 1:
  Each edge has to be there in the resulting tree as removing any of them disconnects the graph.
  So the longest path is 4 -> 2 -> 1 -> 3 and the number of edges in this path is 3 so we will return 3
 Explanation 2:
  Initially the graph looks like :            1         5
                                            /   \     /  \
                                           2 --- 3---4----6
     Edge (1, 2), (1, 3), (2, 3) (4, 5), (4, 6), (5,6) are of no use as removing them doesn't disconnect the graph.
     But Edge (3, 4) has to be there in the resulting tree as removing this edge disconnects the graph.
     So the resulting tree looks like:
              A --- B
     Where A is a compressed node formed by nodes (1, 2, 3) and B is compressed node formed by nodes (4, 5, 6)
     So the answer will be the diameter of this tree which is clearly visible as 1.
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void DFS(vector<int> G[], vector<int> &vis, vector<int> &disc, vector<int> &low, set<pair<int,int>> bridges, int v, int p, int &t, int &ans)
{
    t++;
    vis[v]=1;
    disc[v]=t;
    low[v]=t;
    for(auto i:G[v])
    {
        if(vis[i]==0)
        {
            DFS(G,vis,disc,low, bridges,i,v,t,ans);
            low[v]=min(low[v],low[i]);
            if(low[i]>disc[v]){
                //its a bridge
                ans++;
                bridges.insert({min(i,v), max(i,v)});
            }
        } else if(i!=p){
            low[v]=min(low[v],disc[i]);
        }
    }
}

void findComponent(vector<int> G[], int node, vector<int> &component, vector<bool> &visited,
                  set<pair<int,int>> &bridges) {
    visited[node] = true;
    component.push_back(node);
    for(int next : G[node]) {
        // Skip if visited or if edge is a bridge
        if(!visited[next] && bridges.find({min(node,next), max(node,next)}) == bridges.end()) {
            findComponent(G, next, component, visited, bridges);
        }
    }
}

pair<int,int> findFarthest(vector<int> G[], int start, int n) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int maxDist = 0, farNode = start;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int next : G[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                if(dist[next] > maxDist) {
                    maxDist = dist[next];
                    farNode = next;
                }
                q.push(next);
            }
        }
    }
    return {farNode, maxDist};
}

int solve(int A, vector<vector<int> > &B) {
    int ans =0;
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
    int t=0;
    auto bridges = set<pair<int,int>>();
    
    for(int i=1;i<=A;i++)
    {
        if(vis[i]==0) DFS(G,vis,disc,low,bridges,i,0,t,ans);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, diameter of bridge!\n";
    vector<vector<int>> B{{1,2},{1,3},{2,4}};//{{1,2},{2,3},{3,1},{3,4},{4,5},{5,6},{6,4}};
    cout<<"Diameter of bridge : "<<solve(4, B)<<endl;
    return 0;
}
