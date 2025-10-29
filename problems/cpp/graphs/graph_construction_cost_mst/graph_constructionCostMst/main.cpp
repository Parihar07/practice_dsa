//
//  main.cpp
//  graph_constructionCostMst
//
//  Created by CodeBreaker on 25/03/25.
//

#include <iostream>
#include <vector>
using namespace std;

int findComp(int v, vector<int> &c)
{
    if(v==c[v]) return v;
    c[v]=findComp(c[v], c);
    return c[v];
}
int solve(int A, vector<vector<int> > &B) {
    int ans=0;
    //step 1 - sort edges based on weights
    auto E = B.size(); // number of edges
    auto costs = vector<pair<int, pair<int,int>>>(E);
    for(int i=0;i<E;i++)
    {
        costs[i] = make_pair(B[i][2], make_pair(B[i][0], B[i][1]));
    }
    sort(costs.begin(), costs.end());
    
    //step 2 create component root list
    auto comp = vector<int>(A+1);
    for(int i=0;i<=A;i++) comp[i]=i; // as of now all component are independant mean there roots for themselves
    
    // Create one ran list t create union-find technique
    auto rank = vector<int>(A+1, 0); // all have there own roots so the rank is zero
    //Iterate over the sorted edges and create the map
    for(int i=0;i<E;i++)
    {
        auto u = costs[i].second.first, v = costs[i].second.second, w = costs[i].first;
        auto cu = findComp(u, comp), cv = findComp(v, comp); //this will vaidate if edge create the cycle in graph
        
        
        if(cu!=cv)
        {
            if(rank[cu] < rank[cv])
            {
                comp[cv]=cu;
            } else if(rank[cu] > rank[cv]){
                comp[cu]=cv;
            } else {
                comp[cv]=cu;
                rank[cu]++;
            }
            //comp[max(cu, cv)] = comp[min(cu,cv)];
            ans+=w; //add weights which lowest cost
        }
    }
    
    return ans;
}

void testKruskalWithNegativeEdges() {
    // Test case 1: Mixed positive and negative edges
    vector<vector<int>> B1 = { {1, 2, -3}, {2, 3, 4}, {3, 4, -2}, {4, 1, 1} };
    cout << "MST Total Weight: " << solve(4, B1) << endl;

    // Test case 2: All negative edges
    vector<vector<int>> B2 = { {1, 2, -5}, {2, 3, -10}, {3, 1, -7} };
    cout << "MST Total Weight: " << solve(3, B2) << endl;

    // Test case 3: Negative cycle
    vector<vector<int>> B3 = { {1, 2, -4}, {2, 3, -3}, {3, 4, -2}, {4, 1, -1} };
    cout << "MST Total Weight: " << solve(4, B3) << endl;

    // Test case 4: Disconnected graph
    vector<vector<int>> B4 = { {1, 2, -1}, {3, 4, 2} };
    cout << "MST Total Weight: " << solve(4, B4) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, MST using Union-Find!\n";
    std::cout << "Hello, distribution center using shortest path..!\n";
    testKruskalWithNegativeEdges();
    return 0;
}
