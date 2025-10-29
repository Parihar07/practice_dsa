//
//  main.cpp
//  array_max_positivity
//
//  Created by CodeBreaker on 20/08/1946 Saka.
//
/*
 Maximum positivity
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A, of size N.
 Return the maximum size subarray of A having only non-negative elements. If there are more than one such subarray, return the one having the smallest starting index in A.
 NOTE: It is guaranteed that an answer always exists.


 Problem Constraints
 1 <= N <= 105
 -109 <= A[i] <= 109


 Input Format
 The first and only argument given is the integer array A.


 Output Format
 Return maximum size subarray of A having only non-negative elements. If there are more than one such subarrays, return the one having earliest starting index in A.


 Example Input
 Input 1:
  A = [5, 6, -1, 7, 8]
 Input 2:
  A = [1, 2, 3, 4, 5, 6]


 Example Output
 Output 1:
  [5, 6]
 Output 2:
  [1, 2, 3, 4, 5, 6]


 Example Explanation
 Explanation 1:
  There are two subarrays of size 2 having only non-negative elements.
  1. [5, 6]  starting point  = 0
  2. [7, 8]  starting point  = 3
  As starting point of 1 is smaller, return [5, 6]
 Explanation 2:
  There is only one subarray of size 6 having only non-negative elements:
  [1, 2, 3, 4, 5, 6]
 */

#include <iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int> &A) {
    size_t N=A.size();
    vector<int> ans(0);
    int s=0,e=0, len=0;
    for(int i=0;i<=N;i++)
    {
        if(i==N || A[i]<0)
        {
            if(i!=0)
            {
                e=i-1;
                if((e-s+1)>len)
                {
                    len = e-s+1;
                    ans.clear();
                    ans.resize(0);
                    for(int k=s;k<=e;k++)
                    {
                        ans.push_back(A[k]);
                    }
                }
            }
            s=i+1;
        }
    }
//    if(((N-1)-s+1)>len)
//    {
//        ans.clear();
//        ans.resize(0);
//        for(int k=s;k<N;k++)
//        {
//            ans.push_back(A[k]);
//        }
//    }
    return ans.size()==0?A:ans;
}

/*
 vector<int> Solution::solve(vector<int> &A) {
     int start = 0, max_start = 0, max_len = 0, current_len = 0;
     for (int i = 0; i <= A.size(); i++)
     {
         if (i == A.size() || A[i] < 0)
         {
             if (current_len > max_len)
             {
                 max_len = current_len;
                 max_start = start;
             }
             start = i + 1;
             current_len = 0;
         } else {
             current_len++;
         }
     }
     return vector<int>(A.begin() + max_start, A.begin() + max_start + max_len);
 }
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, max positivity!\n";
    cout<<"------------------\n";
    vector<int> A{1, -2, 3, 4, -1, 5, 6, 7};
    vector<int> ans = solve(A);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<< " ";
    }
    
    return 0;
}
