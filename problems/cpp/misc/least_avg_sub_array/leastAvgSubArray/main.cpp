//
//  main.cpp
//  leastAvgSubArray
//
//  Created by CodeBreaker on 12/08/1946 Saka.
//
/*
 Subarray with least average
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array A of size N, find the subarray of size B with the least average.


 Problem Constraints
 1 <= B <= N <= 105
 -105 <= A[i] <= 105


 Input Format
 First argument contains an array A of integers of size N.
 Second argument contains integer B.


 Output Format
 Return the index of the first element of the subarray of size B that has least average.
 Array indexing starts from 0.


 Example Input
 Input 1:
 A = [3, 7, 90, 20, 10, 50, 40]
 B = 3
 Input 2:
 A = [3, 7, 5, 20, -10, 0, 12]
 B = 2


 Example Output
 Output 1:
 3
 Output 2:
 4


 Example Explanation
 Explanation 1:
 Subarray between indexes 3 and 5
 The subarray {20, 10, 50} has the least average
 among all subarrays of size 3.
 Explanation 2:
  Subarray between [4, 5] has minimum average
 */
#include <iostream>
#include<vector>
using namespace std;

int solveOpt(vector<int> &A, int B)
{
    int ind=0;
    int N=A.size();
    double avg=INT_MAX, t=0;
    vector<int> PFS(A.size());
    PFS[0]=A[0];
    for(int i=1;i<N;i++)
    {
        PFS[i]=PFS[i-1]+A[i];
    }
    for(int i=0;i<=N-B;i++)
    {
        int j=(B-1)+i;
        if(i==0)
        {
            t=(double)PFS[j]/B;
        } else {
            t= ((double)PFS[j]-(double)PFS[i-1])/B;
        }
        if(t<avg)
        {
            avg=t;
            ind=i;
        }
    }
    return ind;
}

int solve(vector<int> &A, int B) {
  
    int ind=0;
    int N = A.size();
    double avg=INT_MAX, t=0;
    vector<int> PFS(A.size());
    PFS[0]=A[0];
    for(int i=1;i<N;i++)
    {
        PFS[i]=PFS[i-1]+A[i];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            if((j-i+1)==B)
            {
                if(i==0)
                {
                    t=(double)PFS[j];
                } else {
                    t=(double)PFS[j]-(double)PFS[i-1];
                }
                if(t<avg)
                {
                    avg=t;
                    ind=i;
                }
//                avg=min(avg,t);
            }
        }
    }
    return ind;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Least AverageSubarrays!\n";
    vector<int> v{3, 7, 90, 20, 10, 50, 40};
    cout<<"LEast average index "<<solveOpt(v, 3);
    return 0;
}
