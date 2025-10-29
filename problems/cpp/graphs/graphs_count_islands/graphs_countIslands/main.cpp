//
//  main.cpp
//  graphs_countIslands
//
//  Created by CodeBreaker on 26/02/25.
//

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &M, int i, int j)
{
    if(i<0 || j<0) return;
    if(i>M.size() || j>M[0].size()) return;
    if(M[i][j]==0) return;
    M[i][j] = 0;
    dfs(M,i+1,j);
    dfs(M,i-1,j);
    dfs(M,i,j+1);
    dfs(M,i,j-1);
}

int countIslands(vector<vector<int>> &M)
{
    auto m = M.size(), n = M[0].size();
    int islands=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(M[i][j] == 1)
            {
                islands++;
                dfs(M,i,j);
            }
        }
    }
    return islands;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, counting islands!\n";
    vector<vector<int>> A{{1,1,0,0,1},{0,1,0,1,0},{1,0,0,1,1},{1,1,0,0,0},{1,0,1,1,1}};
    cout<<"No of islands : "<<countIslands(A)<<endl;
    return 0;
}
