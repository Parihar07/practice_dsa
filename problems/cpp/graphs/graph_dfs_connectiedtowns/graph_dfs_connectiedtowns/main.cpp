//
//  main.cpp
//  graph_dfs_connectiedtowns
//
//  Created by CodeBreaker on 22/02/25.
//
/*
 First Depth First Search
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
You are given N towns (1 to N). All towns are connected via unique directed path as mentioned in the input.
Given 2 towns find whether you can reach the first town from the second without repeating any edge.
B C : query to find whether B is reachable from C.
Input contains an integer array A of size N and 2 integers B and C ( 1 <= B, C <= N ).
There exist a directed edge from A[i] to i+1 for every 1 <= i < N. Also, it's guaranteed that A[i] <= i for every 1 <= i < N.
NOTE: Array A is 0-indexed. A[0] = 1 which you can ignore as it doesn't represent any edge.


Problem Constraints
1 <= N <= 100000


Input Format
First argument is vector A
Second argument is integer B
Third argument is integer C


Output Format
Return 1 if reachable, 0 otherwise.


Example Input
Input 1:
 A = [1, 1, 2]
 B = 1
 C = 2
Input 2:
 A = [1, 1, 2]
 B = 2
 C = 1


Example Output
Output 1:
 0
Output 2:
 1


Example Explanation
Explanation 1:
 Tree is 1--> 2--> 3 and hence 1 is not reachable from 2.
Explanation 2:
 Tree is 1--> 2--> 3 and hence 2 is reachable from 1.
 */


#include <iostream>
#include <vector>
using namespace std;

int DFS(vector<int> G[], int B, int C)
{
    if(B==C) return 1;
      for(auto i:G[C])
      {
          if(DFS(G,B,i)) return 1;
      }
      return 0;
}

int solve(vector<int> &A, const int B, const int C) {
    auto E = A.size();
    auto N = A.size();
    vector<int> G[N+1];
    
    for(int i=1;i<E;i++)
    {
        G[A[i]].push_back(i+1);
    }
    return DFS(G,B,C);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, connected towns!\n";
    vector<int> A{1,1,2};
    cout<<"connected : "<<solve(A, 2, 1)<<endl;
    return 0;
}
