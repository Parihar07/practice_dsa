//
//  main.cpp
//  matrix_maxSumSubarray
//
//  Created by CodeBreaker on 25/12/24.
//
/*
 Maximum Sum Submatrix
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a N * M 2D matrix A. Find the maximum sum sub-matrix from the matrix A. Return the Sum.


 Problem Constraints
 1 <= N, M <= 300
 -104 <= A[i][j] <= 104


 Input Format
 The first argument is a 2D Integer array A.


 Output Format
 Return the sum of the maximum sum sub-matrix from matrix A.


 Example Input
 Input 1:-
     -6 -6
    -29 -8
 A =  3 -8
    -15  2
     25 25
     20 -5
 Input 2:-
 A = -17 -2
      20 10


 Example Output
 Output 1:-
 65
 Output 2:-
 30


 Example Explanation
 Explanation 1:-
 The submatrix
 25 25
 20 -5
 has the highest submatrix sum 65.
 Explanation 2:-
 The submatrix
 20 10
 has the highest sub matrix sum 30.
 */
#include <iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int> > &A) {
    long ans=LONG_MIN;
    size_t row = A.size(), col=A[0].size();
    //vector<vector<int>> PFSM(row,vector<int>(col));
    for(int r=0;r<row;r++)
    {
        for(int c=0;c<col;c++)
        {
            for(int s=r;s<row;s++)
            {
                for(int e=c;e<col;e++)
                {
                    long sum=0;
                    for(int i=r;i<=s;i++)
                    {
                        for(int j=c;j<=e;j++)
                        {
                            sum+=A[i][j];
                        }
                    }
                    ans = max(sum,ans);
                }
            }
        }
    }
    
//    int r=0;
//    while(r<row)
//    {
//        PFSM[r][0]= A[r][0];
//        for(int i=1;i<col;i++)
//        {
//            PFSM[r][i]=PFSM[r][i-1]+A[r][i];
//        }
//        r++;
//    }
//    for(int i=0;i<row;i++)
//    {
//        for(int j=0;j<col;j++)
//        {
//            cout<<PFSM[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    int c=0;
//    while(c<col)
//    {
//        for(int i=1;i<row;i++)
//        {
//            PFSM[i][c] = PFSM[i-1][c]+PFSM[i][c];
//        }
//        c++;
//    }
//    
//    for(int i=0;i<row;i++)
//    {
//        for(int j=0;j<col;j++)
//        {
//            cout<<PFSM[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    int TLx=0,TLy=0,BRx=(int)row-1,BRy=(int)col-1;
//    for(r=0;r<row;r++)
//    {
//        for(c=0;c<col;c++)
//        {
//            TLx=r;TLy=c;
//            long sum=PFSM[BRx][BRy];
//            if(TLx!=0 && TLy!=0)
//            {
//                sum+=PFSM[TLx-1][TLy-1];
//            }
//            if(TLy!=0)
//            {
//                sum-=PFSM[BRx][TLy-1];
//            }
//            if(TLx!=0)
//            {
//                sum-=PFSM[TLx-1][BRy];
//            }
//            ans = max(ans,sum);
//        }
//    }
    
    
    return (int)ans;
}

int kadane(vector<int> v)
{
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0;
         i < (int)v.size(); i++) {
        currSum += v[i];
        if (currSum > maxSum) {
            maxSum = currSum;
        }
 
        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}
//int solveOpt(vector<vector<int>> &A)
//{
//    int r = A.size();
//    int c = A[0].size();
////    assert(r>=1 && r<=300);
////    assert(c>=1 && c<=300);
//    for(auto it:A)
//        for(auto it2:it)
//            assert(it2>=-10000 && it2<=10000);
//    vector <vector <int>> prefix(r,vector <int> (c,0));
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            if (j == 0)
//                prefix[i][j] = A[i][j];
//            else
//                prefix[i][j] = A[i][j] + prefix[i][j - 1];
//        }
//    }
//    int maxSum = INT_MIN;
//    for (int i = 0; i < c; i++) {
//        for (int j = i; j < c; j++) {
//            vector<int> v;
//            for (int k = 0; k < r; k++) {
//                int el = 0;
//                if (i == 0)
//                    el = prefix[k][j];
//                else
//                    el = prefix[k][j] - prefix[k][i - 1];
//                v.push_back(el);
//            }
//            maxSum = max(maxSum, kadane(v));
//        }
//    }
//    return maxSum;
//}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Maximum sum subarray!\n";
    vector<vector<int>> A{{-6,-6},{-29,-8},{3,-8},{-15,2},{25,25},{20,-5}};
    cout<<"max Sum : "<<solve(A)<<endl;
    return 0;
}
