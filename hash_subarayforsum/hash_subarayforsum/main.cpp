//
//  main.cpp
//  hash_subarayforsum
//
//  Created by CodeBreaker on 29/11/24.
//
/*
 Subarray with given sum
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of positive integers A and an integer B, find and return first continuous subarray which adds to B.
 If the answer does not exist return an array with a single integer "-1".
 First sub-array means the sub-array for which starting index in minimum.


 Problem Constraints
 1 <= length of the array <= 100000
 1 <= A[i] <= 109
 1 <= B <= 109


 Input Format
 The first argument given is the integer array A.
 The second argument given is integer B.


 Output Format
 Return the first continuous sub-array which adds to B and if the answer does not exist return an array with a single integer "-1".


 Example Input
 Input 1:
  A = [1, 2, 3, 4, 5]
  B = 5
 Input 2:
  A = [5, 10, 20, 100, 105]
  B = 110


 Example Output
 Output 1:
  [2, 3]
 Output 2:
  [-1]


 Example Explanation
 Explanation 1:
  [2, 3] sums up to 5.
 Explanation 2:
  No subarray sums up to required number.
 */

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> solveOpt(vector<int> &A, int B) {
    size_t N = A.size();
    vector<int> ans(0); int s=-1,e=-1;
    unordered_map<long, int> um; // sum and index like for prefix sum
    um[0]=-1;
    long sum = 0;
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
        long t = sum - B;
        if(um.find(t)!=um.end())
        {
            s= um[t]+1;
            e=i; break;
        }
        um[sum]=i;
    }
    if(s==-1) return vector<int>(1,-1); // this means here it has never come
    for(int i=s;i<=e;i++)
    {
        ans.push_back(A[i]);
    }
    return ans;
}

vector<int> solve(vector<int> &A, int B) {
    size_t N = A.size();
    vector<int> ans(0); int s=0,e=0;
    int flag=0;
    for(int i=0;i<N;i++)
    {
        int sum=0;
        if(flag!=0) break;
        for(int j=i;j<N;j++)
        {
            sum+=A[j];
            if(sum==B)
            {
                flag=1;
                s=i;e=j;break;
            }
        }
    }
    for(int i=s;i<=e;i++)
    {
        ans.push_back(A[i]);
    }
    
    if(ans.size()==0)
    {
        ans.push_back(-1);
    }
   
    return ans;
   
}
 

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Subarray sum B!\n";
    cout<<"-------------------\n";
    vector<int> A{15,2,5,6,9};
    vector<int> ans = solveOpt(A, 100);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
