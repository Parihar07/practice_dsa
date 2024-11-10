//
//  main.cpp
//  matrix_transpose
//
//  Created by CodeBreaker on 17/08/1946 Saka.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > solveImproved(vector<vector<int> > &A) {
    size_t M=A.size(), N=A[0].size();
    vector<vector<int>> ans(N,vector<int>(M,0)); // if transpose row will become columns and columns will become rows
    for(int r=0;r<M;r++)
    {
        for(int c=0;c<N;c++)
        {
            ans[c][r]=A[r][c];
        }
    }
    return ans;
}

vector<vector<int> > solve(vector<vector<int> > &A) {
    size_t M=A.size(), N=A[0].size();
    vector<vector<int>> ans(N,vector<int>(M,0)); // if transpose row will become columns and columns will become rows
    int t=0;
    for(int r=0;r<M;r++)
    {
        int c=r;
        if(c>=N) c=0;
        for(;c<N;c++,t++)
        {
            ans[c][r]=A[r][c];
            if(t<N)
            {
                ans[r][c]=A[c][r];
            }
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Transpose matrix!\n";
    vector<vector<int>> A{{4,67,11,48,81,69,53,27,64,74},{13,40,32,40,21,33,44,82,58,4},{34,84,40,75,95,82,57,89,86,46},{98,89,64,8,89,44,28,41,70,91},{66,83,82,50,74,2,82,69,83,39},{72,17,23,63,43,69,45,51,57,82},{48,54,71,11,13,59,6,41,51,76},{83,17,10,65,18,35,66,99,3,1}};
    vector<vector<int>> ans = solveImproved(A);
    cout<< "\n---------------------------\n";
    for (int r=0; r<ans.size(); r++) {
        for (int c=0; c<ans[0].size(); c++) {
            cout<<ans[r][c] << " ";
        }
        cout<<endl;
    }
    return 0;
}
