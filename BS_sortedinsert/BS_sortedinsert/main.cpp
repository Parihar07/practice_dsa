//
//  main.cpp
//  BS_sortedinsert
//
//  Created by CodeBreaker on 12/01/25.
//
/*
 Sorted Insert Position
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a sorted array A of size N and a target value B.
 Your task is to find the index (0-based indexing) of the target value in the array.

 If the target value is present, return its index.
 If the target value is not found, return the index of least element greater than equal to B.
 If the target value is not found and least number greater than equal to target is also not present, return the length of array (i.e. the position where target can be placed)
 Your solution should have a time complexity of O(log(N)).


 Problem Constraints
 1 <= N <= 105
 1 <= A[i] <= 105
 1 <= B <= 105


 Input Format
 The first argument is an integer array A of size N.
 The second argument is an integer B.


 Output Format
 Return an integer denoting the index of target value.


 Example Input
 Input 1:
 A = [1, 3, 5, 6]
 B = 5
 Input 2:
 A = [1, 4, 9]
 B = 3


 Example Output
 Output 1:
 2
 Output 2:
 1


 Example Explanation
 Explanation 1:
 The target value is present at index 2.
 Explanation 2:
 The target value should be inserted at index 1.
 */
#include <iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int> &A, int B) {
    size_t N = A.size();
    int s=0,e=(int)N-1;
    int m=0;
    while(s<=e)
    {
        m=(s+e)/2;
        if(B==A[m]) return m;
        if(B<A[m])
        {
            e=m-1;
        } else {
            s=m+1;
        }
    }
    
    return s;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Binary search!\n";
    vector<int> A{1,3,5,7};
    cout<<"Value index :" << searchInsert(A, 8)<<endl;
    return 0;
}
