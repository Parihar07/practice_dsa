//
//  main.cpp
//  maxSubArray
//
//  Created by CodeBreaker on 12/08/1946 Saka.
//
/*
 Maximum Subarray Easy
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an integer array C of size A. Now you need to find a subarray (contiguous elements) so that the sum of contiguous elements is maximum.
 But the sum must not exceed B.


 Problem Constraints
 1 <= A <= 103
 1 <= B <= 109
 1 <= C[i] <= 106


 Input Format
 The first argument is the integer A.
 The second argument is the integer B.
 The third argument is the integer array C.


 Output Format
 Return a single integer which denotes the maximum sum.


 Example Input
 Input 1:
 A = 5
 B = 12
 C = [2, 1, 3, 4, 5]
 Input 2:
 A = 3
 B = 1
 C = [2, 2, 2]


 Example Output
 Output 1:
 12
 Output 2:
 0


 Example Explanation
 Explanation 1:
 We can select {3,4,5} which sums up to 12 which is the maximum possible sum.
 Explanation 2:
 All elements are greater than B, which means we cannot select any subarray.
 Hence, the answer is 0.
 */
#include <iostream>
#include<vector>
using namespace std;

int maxSubarray(int A, int B, vector<int> &C) {
    int ans=INT_MIN;
    int N = C.size();
    for(int i=0;i<N;i++)
    {
        int t=0;
        for(int j=i;j<N;j++)
        {
            t+=C[j];
            if(t<=B)
            {
                ans=max(t,ans);
            } else {
                break;
            }
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Max sum subarray !\n";
    vector<int> v{2, 1, 3, 4, 5};
    cout<<"max Sub arry : "<<maxSubarray(5, 12, v) <<endl;
    return 0;
}
