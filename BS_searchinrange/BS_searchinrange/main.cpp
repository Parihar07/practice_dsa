//
//  main.cpp
//  BS_searchinrange
//
//  Created by CodeBreaker on 12/01/25.
//
/*
 Search for a Range
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a sorted array of integers A (0-indexed) of size N, find the left most and the right most index of a given integer B in the array A.

 Return an array of size 2, such that
           First element = Left most index of B in A
           Second element = Right most index of B in A.
 If B is not found in A, return [-1, -1].

 Note : Note: The time complexity of your algorithm must be O(log n)..


 Problem Constraints
 1 <= N <= 106
 1 <= A[i], B <= 109


 Input Format
 The first argument given is the integer array A.
 The second argument given is the integer B.


 Output Format
 Return the left most and right most index (0-based) of B in A as a 2-element array. If B is not found in A, return [-1, -1].


 Example Input
 Input 1:
  A = [5, 7, 7, 8, 8, 10]
  B = 8
 Input 2:
  A = [5, 17, 100, 111]
  B = 3


 Example Output
 Output 1:
  [3, 4]
 Output 2:
  [-1, -1]


 Example Explanation
 Explanation 1:
  The first occurrence of 8 in A is at index 3.
  The last occurrence of 8 in A is at index 4.
  ans = [3, 4]
 Explanation 2:
  There is no occurrence of 3 in the array.
 */
#include <iostream>
#include<vector>
using namespace std;
vector<int> searchRange(const vector<int> &A, int B) {
    vector<int> ans{-1,-1};
    int l=0, h=(int)A.size()-1;
    while(l<=h)
    {
        int m = (l+h)/2;
        if(A[m]==B)
        {
            ans[0]=m;
            h=m-1;
        } else if(A[m]<B)
        {
            l=m+1;
        } else if(A[m]>B){
            h=m-1;
        }
    }
    l=0;h=(int)A.size()-1;
    while(l<=h)
    {
        int m = (l+h)/2;
        if(A[m]==B)
        {
            ans[1]=m;
            l=m+1;
        } else if(A[m]<B)
        {
            l=m+1;
        } else if(A[m]>B){
            h=m-1;
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, search in range!\n";
    vector<int> A{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    vector<int> ans = searchRange(A, 3);
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
