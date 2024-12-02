//
//  main.cpp
//  hashing_subArraySum
//
//  Created by CodeBreaker on 01/12/24.
//
/*
 Subarray Sum Equals K
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A and an integer B.
 Find the total number of subarrays having sum equals to B.


 Problem Constraints
  1 <= length of the array <= 50000
 -1000 <= A[i] <= 1000


 Input Format
 The first argument given is the integer array A.
 The second argument given is integer B.


 Output Format
 Return the total number of subarrays having sum equals to B.


 Example Input
 Input 1:
 A = [1, 0, 1]
 B = 1
 Input 2:
 A = [0, 0, 0]
 B = 0


 Example Output
 Output 1:
 4
 Output 2:
 6


 Example Explanation
 Explanation 1:
 [1], [1, 0], [0, 1] and [1] are four subarrays having sum 1.
 Explanation 1:
 All the possible subarrays having sum 0.
 */
#include <iostream>
#include<vector>
using namespace std;

int solveOpt(vector<int> &A, int B) {
    int ans=0;
    size_t N = A.size();
    unordered_map<int, int> UM;
    int sum=0;
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
        int t = sum-B;
        if(UM.find(t)!=UM.end())
        {
            ans+=UM[t];
        }
        UM[sum]+=1;
    }
    return ans;
}

int solve(vector<int> &A, int B) {
    int ans=0;
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        int sum=0;
        for(int j=i;j<N;j++)
        {
            sum+=A[j];
            if(sum==B) ans+=1;
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Subbaray Sum!\n";
    vector<int> A{1,2,4,3,6,4,7,5};
    cout<<"Sum subbarrays : "<<solve(A, 9)<<endl;
    return 0;
}
