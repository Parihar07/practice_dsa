//
//  main.cpp
//  bs_targetinksortedarray
//
//  Created by CodeBreaker on 13/01/25.
//
/*
 Rotated Sorted Array Search
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a sorted array of integers A of size N and an integer B,
 where array A is rotated at some pivot unknown beforehand.

 For example, the array [0, 1, 2, 4, 5, 6, 7] might become [4, 5, 6, 7, 0, 1, 2].

 Your task is to search for the target value B in the array. If found, return its index; otherwise, return -1.

 You can assume that no duplicates exist in the array.

 NOTE: You are expected to solve this problem with a time complexity of O(log(N)).


 Problem Constraints
 1 <= N <= 1000000
 1 <= A[i] <= 109
 All elements in A are Distinct.


 Input Format
 The First argument given is the integer array A.
 The Second argument given is the integer B.


 Output Format
 Return index of B in array A, otherwise return -1


 Example Input
 Input 1:
 A = [4, 5, 6, 7, 0, 1, 2, 3]
 B = 4
 Input 2:
 A : [ 9, 10, 3, 5, 6, 8 ]
 B : 5


 Example Output
 Output 1:
  0
 Output 2:
  3


 Example Explanation
 Explanation 1:
 Target 4 is found at index 0 in A.
 Explanation 2:
 Target 5 is found at index 3 in A.
 */
#include <iostream>
#include<vector>
using namespace std;

int search(const vector<int> &A, int B) {
    size_t N = A.size();
    int l=0,h=N-1,k=0;
    while(l<=h)
    {
        int m = (l+h)/2;
        if(A[0]>A[m])
        {
            k=m;
            h=m-1;
        } else {
            l=m+1;
        }
    }
    if(A[0]==B) return 0;
    if(k == 0) {
        l = 0; h = N-1;
    } else if(A[0]>B)
    {
        l=k;h=N-1;
    } else {
        l=0,h=k-1;
    }
    while(l<=h)
    {
        int m = (l+h)/2;
        if(A[m]==B) return m;
        if(A[m]>B)
        {
            h=m-1;
        } else {
            l=m+1;
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Search in sorted k time array!\n";
    vector<int> A{1,2,3,4,5};
    cout<<"found k "<<search(A,5)<<endl;
    return 0;
}
