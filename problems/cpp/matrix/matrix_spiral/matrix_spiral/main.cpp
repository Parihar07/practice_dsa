//
//  main.cpp
//  matrix_spiral
//
//  Created by CodeBreaker on 18/08/1946 Saka.
//
/*
 Spiral Order Matrix II
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order and return the generated square matrix.


 Problem Constraints
 1 <= A <= 1000


 Input Format
 First and only argument is integer A


 Output Format
 Return a 2-D matrix which consists of the elements added in spiral order.


 Example Input
 Input 1:
 1
 Input 2:
 2
 Input 3:
 5


 Example Output
 Output 1:
 [ [1] ]
 Output 2:
 [ [1, 2],
   [4, 3] ]
 Output 3:
 [ [1,   2,  3,  4, 5],
   [16, 17, 18, 19, 6],
   [15, 24, 25, 20, 7],
   [14, 23, 22, 21, 8],
   [13, 12, 11, 10, 9] ]


 Example Explanation
 Explanation 1:
 Only 1 is to be arranged.
 Explanation 2:
 1 --> 2
       |
       |
 4<--- 3
 Explanation 3:

 */

#include <iostream>
#include<vector>
using namespace std;

vector<vector<int> > generateMatrix(int A) {
    vector<vector<int>> ans(A,vector<int>(A,0));
    int N=A;
    int r=0,c=0;
    int cnt=1;
    while(N>1)
    {
        //row wise or towards right
        for(int k=1;k<N;k++)
        {
            ans[r][c]=cnt++;
            c++;
        }
        // column wise or towards bottom
        for(int k=1;k<N;k++)
        {
            ans[r][c]=cnt++;
            r++;
        }
        // row wise or towards left
        for(int k=1;k<N;k++)
        {
            ans[r][c]=cnt++;
            c--;
        }
        // row wise or bottom to upwards
        for(int k=1;k<N;k++)
        {
            ans[r][c]=cnt++;
            r--;
        }
        N-=2;r++;c++;
    }
    if(A%2!=0)
    {
        ans[r][c]=cnt;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Spiral Mattrix!\n";
    vector<vector<int>> ans = generateMatrix(5);
    cout<< "\n---------------------------\n";
    for (int r=0; r<ans.size(); r++) {
        for (int c=0; c<ans[0].size(); c++) {
            cout<<ans[r][c] << " ";
        }
        cout<<endl;
    }
    return 0;
}
