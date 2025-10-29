//
//  main.cpp
//  hashing_countpairdiff
//
//  Created by CodeBreaker on 01/12/24.
//
/*
 Count Pair Difference
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an array A of N integers and an integer B.
 Count the number of pairs (i,j) such that A[i] - A[j] = B and i ≠ j.

 Since the answer can be very large, return the remainder after dividing the count with 109+7.


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
 B = 4
 Input 2:
 A = [1, 2, 1, 2]
 B = 1


 Example Output
 Output 1:
 1
 Output 2:
 4


 Example Explanation
 Example 1:
 The only pair is (2, 3) which gives difference as 4
 Example 2:
 The pair which gives difference as 3 are (2, 1), (4, 1), (2, 3) and (4, 3).
 */
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(vector<int> &A, int B) {
    int ans=0;
    size_t N = A.size();
    unordered_map<int, int> UM; //eleemt and frequency
    
    for(int k=0;k<N;k++)
    {
        int i=B+A[k], j=A[k]-B;
        if( (UM.find(i) != UM.end()) )
        {
            ans+=UM[i];
        }
        if((UM.find(j) != UM.end()) )
        {
            ans+=UM[j];
        }
        UM[A[k]]+=1;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Count diff pair sum!\n";
    vector<int> A{988,264,598,236,659,271,398,766,849,91,544,977,948,55,964,323,664,722,79,886,874,431,537,246,748,734,93,636,501,73,508,526,14,144,194,4,77,365,784,325,918,57,40,280,261,741,717,459,445,666,800,720};
    cout<<"Diff pair count : "<<solve(A, 420)<<endl;
    
    return 0;
}
