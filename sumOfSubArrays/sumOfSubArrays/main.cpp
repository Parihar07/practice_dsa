//
//  main.cpp
//  sumOfSubArrays
//
//  Created by CodeBreaker on 11/08/1946 Saka.
//
/*
 Sum of All Subarrays
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an integer array A of length N.
 You have to find the sum of all subarray sums of A.
 More formally, a subarray is defined as a contiguous part of an array which we can obtain by deleting zero or more elements from either end of the array.
 A subarray sum denotes the sum of all the elements of that subarray.
 Note : Be careful of integer overflow issues while calculations. Use appropriate datatypes.


 Problem Constraints
 1 <= N <= 105
 1 <= Ai <= 10 4


 Input Format
 The first argument is the integer array A.


 Output Format
 Return a single integer denoting the sum of all subarray sums of the given array.


 Example Input
 Input 1:
 A = [1, 2, 3]
 Input 2:
 A = [2, 1, 3]


 Example Output
 Output 1:
 20
 Output 2:
 19


 Example Explanation
 Explanation 1:
 The different subarrays for the given array are: [1], [2], [3], [1, 2], [2, 3], [1, 2, 3].
 Their sums are: 1 + 2 + 3 + 3 + 5 + 6 = 20
 Explanation 2:
 The different subarrays for the given array are: [2], [1], [3], [2, 1], [1, 3], [2, 1, 3].
 Their sums are: 2 + 1 + 3 + 3 + 4 + 6 = 19
 */
#include <iostream>
#include<vector>
using namespace std;

long subarraySum(vector<int> &A) { // O(n^3)
    long ans=0;
    int N = A.size();
    for(int s=0;s<N;s++)
    {
        for(int e=0;e<N;e++)
        {
            for(int i=s;i<=e;i++)
            {
                ans+=A[i];
            }
        }
    }
    return ans;
}

long subarraySumOpt1(vector<int> &A)
{
    long ans=0;
    int N = A.size();
    vector<int> PFS(N);
    PFS[0]=A[0];
    for(int i=1;i<N;i++)
    {
        PFS[i]=PFS[i-1]+A[i];
    }
    
    for(int s=0;s<N;s++)
    {
        for(int e=s;e<N;e++)
        {
           if(s==0)
           {
               ans+=PFS[e];
           } else {
               ans+=PFS[e]-PFS[s-1];
           }
        }
    }
    return ans;
}

long subarraySumOpt2(vector<int> &A)
{
    long ans=0;
    int N=A.size();
    for(int i=0;i<N;i++)
    {
        ans+=(long)A[i]*((long)(i+1)*(long)(N-i));
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Sum of all subarrays!\n";
    vector<int> v{1,2,4,6};
    cout<<"sum of all subarrays "<<subarraySumOpt2(v)<<endl;
    return 0;
}
