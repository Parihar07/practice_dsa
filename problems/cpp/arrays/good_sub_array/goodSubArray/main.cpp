//
//  main.cpp
//  goodSubArray
//
//  Created by CodeBreaker on 14/08/1946 Saka.
//
/*
 Good Subarrays Easy
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A, a subarray of an array is said to be good if it fulfills any one of the criteria:
 1. Length of the subarray is be even, and the sum of all the elements of the subarray must be less than B.
 2. Length of the subarray is be odd, and the sum of all the elements of the subarray must be greater than B.
 Your task is to find the count of good subarrays in A.


 Problem Constraints
 1 <= len(A) <= 5 x 103
 1 <= A[i] <= 103
 1 <= B <= 107


 Input Format
 The first argument given is the integer array A.
 The second argument given is an integer B.


 Output Format
 Return the count of good subarrays in A.


 Example Input
 Input 1:
 A = [1, 2, 3, 4, 5]
 B = 4
 Input 2:
 A = [13, 16, 16, 15, 9, 16, 2, 7, 6, 17, 3, 9]
 B = 65


 Example Output
 Output 1:
 6
 Output 2:
 36


 Example Explanation
 Explanation 1:
 Even length good subarrays = {1, 2}
 Odd length good subarrays = {1, 2, 3}, {1, 2, 3, 4, 5}, {2, 3, 4}, {3, 4, 5}, {5}
 Explanation 1:
 There are 36 good subarrays
 */
#include <iostream>
#include<vector>
using namespace std;
 
int solve(vector<int> &A, int B) {
    int ans=0;
    int N=A.size();
    vector<int> PFS(N);
    PFS[0]=A[0];
    for(int i=1;i<N;i++)
    {
        PFS[i]=PFS[i-1]+A[i];
    }
    
    for(int s=0; s<N;s++)
    {
        int sum=0;
        for(int e=s;e<N;e++)
        {
            if(s==0)
            {
                sum+=PFS[e];
            } else {
                sum+=PFS[e]-PFS[s-1];
            }
            int len = e-s+1;
            if(len%2==0)
            {
                if(sum<B)
                {
                    ans+=1;
                }
            } else {
                if(sum>B)
                {
                    ans+=1;
                }
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Good Sub Array!\n";
    vector<int> v{1, 2, 3, 4, 5};
    cout<<"Good SubArrays : "<<solve(v, 4)<<endl;
    return 0;
}
