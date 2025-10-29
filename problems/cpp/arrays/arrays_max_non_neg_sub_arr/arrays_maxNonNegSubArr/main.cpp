//
//  main.cpp
//  arrays_maxNonNegSubArr
//
//  Created by CodeBreaker on 20/12/24.
//
/*
 Max Non Negative SubArray
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.
 The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
 Maximum sub-array is defined in terms of the sum of the elements in the sub-array.
 Find and return the required subarray.
 NOTE:
     1. If there is a tie, then compare with segment's length and return segment which has maximum length.
     2. If there is still a tie, then return the segment with minimum starting index.

 Input Format:
 The first and the only argument of input contains an integer array A, of length N.
 Output Format:
 Return an array of integers, that is a subarray of A that satisfies the given conditions.
 Constraints:
 1 <= N <= 1e5
 -INT_MAX < A[i] <= INT_MAX
 Examples:
 Input 1:
     A = [1, 2, 5, -7, 2, 3]

 Output 1:
     [1, 2, 5]

 Explanation 1:
     The two sub-arrays are [1, 2, 5] [2, 3].
     The answer is [1, 2, 5] as its sum is larger than [2, 3].

 Input 2:
     A = [10, -1, 2, 3, -4, 100]

 Output 2:
     [100]

 Explanation 2:
     The three sub-arrays are [10], [2, 3], [100].
     The answer is [100] as its sum is larger than the other two.
 */
#include <iostream>
#include<vector>

using namespace std;

vector<int> maxset(vector<int> &A) {
    size_t N = A.size();
    int L=0; long sum=0,maxi=LONG_MIN;
    pair<int, int> set;
    for(int i=0;i<N;i++)
    {
        if(A[i]<0)
        {
            sum=0;
            L=i+1;
        } else {
            sum+=A[i];
        }
        if(sum > maxi || (sum == maxi && (i-L) > (set.second-set.first)))
        {
            maxi=sum;
            set.first=L;
            set.second=i;
        }
        
    }
    if(maxi==INT_MIN) return vector<int>();
    int len = set.second-set.first+1;
    vector<int> ans(len);
    int k=0;
    for(int i=set.first;i<=set.second;i++)
    {
        ans[k]=A[i]; k++;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, max non negative subarrayr̥!\n";
    vector<int> A{1967513926,1540383426,-1303455736,-521595368};
    vector<int> ans = maxset(A);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
