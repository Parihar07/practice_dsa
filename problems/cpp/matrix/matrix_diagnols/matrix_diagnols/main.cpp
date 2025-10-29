//
//  main.cpp
//  matrix_diagnols
//
//  Created by CodeBreaker on 15/08/1946 Saka.
//
/*
 Anti Diagonals
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Give a N * N square matrix A, return an array of its anti-diagonals. Look at the example for more details.


 Problem Constraints
 1<= N <= 1000
 1<= A[i][j] <= 1e9


 Input Format
 Only argument is a 2D array A of size N * N.


 Output Format
 Return a 2D integer array of size (2 * N-1) * N, representing the anti-diagonals of input array A.
 The vacant spaces in the grid should be assigned to 0.


 Example Input
 Input 1:
 1 2 3
 4 5 6
 7 8 9
 Input 2:
 1 2
 3 4


 Example Output
 Output 1:
 1 0 0
 2 4 0
 3 5 7
 6 8 0
 9 0 0
 Output 2:
 1 0
 2 3
 4 0


 Example Explanation
 For input 1:
 The first anti diagonal of the matrix is [1 ], the rest spaces shoud be filled with 0 making the row as [1, 0, 0].
 The second anti diagonal of the matrix is [2, 4 ], the rest spaces shoud be filled with 0 making the row as [2, 4, 0].
 The third anti diagonal of the matrix is [3, 5, 7 ], the rest spaces shoud be filled with 0 making the row as [3, 5, 7].
 The fourth anti diagonal of the matrix is [6, 8 ], the rest spaces shoud be filled with 0 making the row as [6, 8, 0].
 The fifth anti diagonal of the matrix is [9 ], the rest spaces shoud be filled with 0 making the row as [9, 0, 0].
 For input 2:
 The first anti diagonal of the matrix is [1 ], the rest spaces shoud be filled with 0 making the row as [1, 0, 0].
 The second anti diagonal of the matrix is [2, 4 ], the rest spaces shoud be filled with 0 making the row as [2, 4, 0].
 The third anti diagonal of the matrix is [3, 0, 0 ], the rest spaces shoud be filled with 0 making the row as [3, 0, 0].
 */
#include <iostream>
#include<vector>
using namespace std;
vector<vector<int> > diagonal(vector<vector<int> > &A) {
    
    int N = A.size(); //given N*N, hence square matrix;
    vector<vector<int>> ans(N+(N-1), vector<int>(N, 0));
    int ans_r = 0;
    for(int c=0;c<N;c++)
    {
        int i=0, j=c;
        while(i<N)
        {
            if(j>=0){
               ans[ans_r][i]=A[i][j];
            } //else {
//                ans[i].push_back(0);
//            }
            i++;j--;
        }
        ans_r++;
    }
    for(int r=1;r<N;r++)
    {
        int i=r, j=N-1;
        while(j>=0)
        {
            if(i<N){
                ans[ans_r][(N-1)-j]=A[i][j];
//                cout<<A[i][j]<<" ";
           } /*else {
               cout<<0<<" ";
            }*/
            i++;j--;
        }
        cout<<endl;
        ans_r++;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Dialgnol matrix!\n";
    vector<vector<int> > A{{1,1},{2,2}};
//        {{1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}};
    vector<vector<int>> ans = diagonal(A);
    cout<< "\n---------------------------\n";
    for (int r=0; r<ans.size(); r++) {
        for (int c=0; c<ans[0].size(); c++) {
            cout<<ans[r][c] << " ";
        }
        cout<<endl;
        }
    return 0;
}
