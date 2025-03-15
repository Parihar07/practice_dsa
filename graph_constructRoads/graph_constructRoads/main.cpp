//
//  main.cpp
//  graph_constructRoads
//
//  Created by CodeBreaker on 07/03/25.
//
/*
 Construct Roads
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 A country consist of N cities connected by N - 1 roads. King of that country want to construct maximum number of roads such that the new country formed remains bipartite country.
 Bipartite country is a country, whose cities can be partitioned into 2 sets in such a way, that for each road (u, v) that belongs to the country, u and v belong to different sets. Also, there should be no multiple roads between two cities and no self loops.
 Return the maximum number of roads king can construct. Since the answer could be large return answer % 109 + 7.
 NOTE: All cities can be visited from any city.


 Problem Constraints
 1 <= A <= 105
 1 <= B[i][0], B[i][1] <= N


 Input Format
 First argument is an integer A denoting the number of cities, N.
 Second argument is a 2D array B of size (N-1) x 2 denoting the initial roads i.e. there is a road between cities B[i][0] and B[1][1] .


 Output Format
 Return an integer denoting the maximum number of roads king can construct.


 Example Input
 Input 1:
  A = 3
  B = [
        [1, 2]
        [1, 3]
      ]
 Input 2:
  A = 5
  B = [
        [1, 3]
        [1, 4]
        [3, 2]
        [3, 5]
      ]


 Example Output
 Output 1:
  0
 Output 2:
  2


 Example Explanation
 Explanation 1:
  We can't construct any new roads such that the country remains bipartite.
 Explanation 2:
  We can add two roads between cities (4, 2) and (4, 5).
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve(int A, vector<vector<int> > &B) {
    int E = (int)B.size();
    //creating adjacency list
    vector<int> G[A+1];
    for(int i=0;i<E;i++)
    {
        G[B[i][0]].push_back(B[i][1]);
        G[B[i][1]].push_back(B[i][0]);
    }
    
    //dividing the edges
    auto cv = vector<int>(A+1,0);
    auto q = queue<int>();
    cv[1]=1;q.push(1);
    
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        for(auto i: G[t])
        {
            if(cv[i]==0)
            {
                cv[i]=3-cv[t];
                q.push(i);
            }
        }
    }
    
    //getting count of each edges
    int c1=0,c2=0;
    for(int i=0;i<A+1;i++)
    {
        if(cv[i]==1) c1++;
        else if(cv[i]==2) c2++;
    }
    
    return (c1*c2)-E;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, cnnected roads !\n";
    vector<vector<int>> B{{1,3},{1,4},{3,2},{3,5}};
    cout<<"maximum connected roads : "<<solve(5, B)<<endl;
    return 0;
}
