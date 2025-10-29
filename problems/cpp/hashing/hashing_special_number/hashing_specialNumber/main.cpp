//
//  main.cpp
//  hashing_specialNumber
//
//  Created by CodeBreaker on 29/11/24.
//
/*
 Shaggy and distances
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Shaggy has an array A consisting of N elements. We call a pair of distinct indices in that array a special if elements at those indices in the array are equal.
 Shaggy wants you to find a special pair such that the distance between that pair is minimum. Distance between two indices is defined as |i-j|. If there is no special pair in the array, then return -1.


 Problem Constraints
 1 <= |A| <= 105


 Input Format
 The first and only argument is an integer array A.


 Output Format
 Return one integer corresponding to the minimum possible distance between a special pair.


 Example Input
 Input 1:
 A = [7, 1, 3, 4, 1, 7]
 Input 2:
 A = [1, 1]


 Example Output
 Output 1:
  3
 Output 2:
  1


 Example Explanation
 Explanation 1:
 Here we have 2 options:
 1. A[1] and A[4] are both 1 so (1,4) is a special pair and |1-4|=3.
 2. A[0] and A[5] are both 7 so (0,5) is a special pair and |0-5|=5.
 Therefore the minimum possible distance is 3.
 Explanation 2:
 Only possibility is choosing A[1] and A[2].
 */
#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int solveOpt(vector<int> &A) {
    size_t N = A.size();
    int ans = INT_MAX;
    unordered_map<int,int> um; // element and index
    
    for(int i=0;i<N;i++)
    {
        if(um.find(A[i]) != um.end())
        {
            ans=min(ans,abs(um[A[i]]-i));
        }
        um[A[i]]=i;
    }
    return ans==INT_MAX?-1:ans;
}
int solve(vector<int> &A) {
    int ans = INT_MAX;
    size_t N = A.size();
    
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(A[i]==A[j])
            {
                ans=min(ans,abs(i-j));
            }
        }
    }
    return ans==INT_MAX?-1:ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Special Number !\n";
    cout<<"-------------------\n";
    vector<int> A{7, 1, 3, 4, 1, 7};
    cout<<"Minimum distance : "<<solveOpt(A)<<endl;
    return 0;
}
