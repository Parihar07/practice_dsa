//
//  main.cpp
//  hashing_pairsum
//
//  Created by CodeBreaker on 01/12/24.
//
/*
 Count Pair Sum
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
You are given an array A of N integers and an integer B. Count the number of pairs (i,j) such that A[i] + A[j] = B and i ≠ j.

Since the answer can be very large, return the remainder after dividing the count with 109+7.

Note - The pair (i,j) is same as the pair (j,i) and we need to count it only once.


Problem Constraints
1 <= N <= 105
1 <= A[i] <= 109
1 <= B <= 109


Input Format
First argument A is an array of integers and second argument B is an integer.


Output Format
Return an integer.


Example Input
Input 1:
A = [3, 5, 1, 2]
B = 8
Input 2:
A = [1, 2, 1, 2]
B = 3


Example Output
Output 1:
1
Output 2:
4


Example Explanation
Example 1:
The only pair is (1, 2) which gives sum 8
Example 2:
The pair which gives sum as 3 are (1, 2), (1, 4), (2, 3) and (3, 4).
 */
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int solveOpt(vector<int> &A, int B) {
    int ans=0;
    size_t N=A.size();
    unordered_map<int,int> UM;//Element and frequency
//    for(int i=0;i<N;i++)
//    {
//        UM[A[i]]+=1;
//    }
    for(int j=0;j<N;j++)
    {
        int t = B-A[j];
        if(UM.find(t)!=UM.end())
        {
            ans+=UM[t];
        }
        UM[A[j]]+=1;
    }
    return ans;
}
int solve(vector<int> &A, int B) {
    int ans=0;
    size_t N=A.size();
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if((A[i]+A[j])==B) ans+=1;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Count Pair sum!\n";
    vector<int> A{3,3,3,3};
    cout<<"Pair sum : "<<solveOpt(A, 6)<<endl;
    return 0;
}
