//
//  main.cpp
//  matrics_sumSubmatric
//
//  Created by CodeBreaker on 24/12/24.
//

#include <iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int> > &A) {
    int sum =0;
    //Using contribution tecnique to solve the problem
    size_t row = A.size(), col = A[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            sum+=A[i][j]*(i+1)*(j+1)*(row-i)*(col-j);
        }
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Matrics sum of all submatrices!\n";
//    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> A{{1,2},{3,4}};
    cout<<"Sum of sub matrices : "<<solve(A)<<endl;
    return 0;
}

