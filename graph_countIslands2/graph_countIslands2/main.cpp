//
//  main.cpp
//  graph_countIslands2
//
//  Created by CodeBreaker on 01/03/25.
//

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &A, int i, int j)
{
    if(i<0 || j<0) return;
    if(i<=A.size() || j<=A[0].size()) return;
    if(A[i][j] == 0) return;
    
    A[i][j]=0;
    
    dfs(A,i-1,j);
    dfs(A,i+1,j);
    dfs(A,i,j-1);
    dfs(A,i,j+1);
    dfs(A,i+1,j+1);
    dfs(A,i-1,j-1);
    dfs(A,i-1,j+1);
    dfs(A,i+1,j-1);
}

int solve(vector<vector<int> > &A) {
    auto r = A.size(), c=A[0].size();
    int islands=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(A[i][j]==1)
            {
                islands++;
                dfs(A,i,j);
            }
        }
    }
    return islands;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<vector<int>> A{{1,1,0,0,0},{0,1,0,0,0},{1,0,0,1,1},{0,0,0,0,0},{1,0,1,0,1}};
    cout<<"No of islands : " << solve(A) <<endl;
    return 0;
}
