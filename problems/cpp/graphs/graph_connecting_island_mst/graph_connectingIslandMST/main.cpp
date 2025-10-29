//
//  main.cpp
//  graph_connectingIslandMST
//
//  Created by CodeBreaker on 24/03/25.
//

/*
 Commutable Islands
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.
We need to find bridges with minimal cost such that all islands are connected.
It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.


Problem Constraints
1 <= A, M <= 6*104
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 103


Input Format
The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3 where Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].


Output Format
Return an integer representing the minimal cost required.


Example Input
Input 1:
 A = 4
 B = [  [1, 2, 1]
        [2, 3, 4]
        [1, 4, 3]
        [4, 3, 2]
        [1, 3, 10]  ]
Input 2:
 A = 4
 B = [  [1, 2, 1]
        [2, 3, 2]
        [3, 4, 4]
        [1, 4, 3]   ]


Example Output
Output 1:
 6
Output 2:
 6


Example Explanation
Explanation 1:
 We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.
Explanation 2:
 We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.
 */

#include <iostream>
#include <vector>
using namespace std;
int findComp(int v, vector<int> &c)
{
    if(v==c[v]) return v; // this mean independant island no parent
    c[v]=findComp(c[v],c);
    return c[v];
}

int solve(int A, vector<vector<int> > &B) {
    int ans=0;
    //step 1
    //Create independant list of components as of now they are idependent components
    auto comp = vector<int>(A+1,0);
    for(int i=0;i<=A;i++) comp[i]=i;
    
    //step 2
    //creating list of edges in sorted order based on weights
    auto E= B.size(); //Number of edges
    auto bridges = vector<pair<int, pair<int, int>>>(E);
    for(int i=0;i<E;i++)
    {
        bridges[i]=make_pair(B[i][2], make_pair(B[i][0], B[i][1]));
    }
    sort(bridges.begin(), bridges.end()); //sorting bridges/edges based on weights
    //step 3
    //iterate over sorted edges and create map of islans with shortes bridges connected
    for(int i=0;i<E;i++)
    {
        auto u = bridges[i].second.first;
        auto v = bridges[i].second.second;
        auto w = bridges[i].first;
        auto cu = findComp(u, comp), cv = findComp(v, comp);
        if(cu!=cv)
        {
            ans+=w;
            comp[max(cu,cv)]=comp[min(cu,cv)];
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Commutable Island using shortest bridge..!\n";
    vector<vector<int>> B{{1,2,1},{2,3,4},{1,4,3},{4,3,2},{1,3,10}};
    cout<<"Island map with shortest bridges - "<<solve(4, B)<<endl;
    return 0;
}
