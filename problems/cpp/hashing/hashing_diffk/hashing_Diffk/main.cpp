//
//  main.cpp
//  hashing_Diffk
//
//  Created by CodeBreaker on 30/11/24.
//
/*
 Diffk II
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array A of integers and another non negative integer B .
 Find if there exists 2 indices i and j such that A[i] - A[j] = B and i != j.


 Problem Constraints
 1 <= |A| <= 106
 0 <= A[i] <= 109
 0 <= B <= 109


 Input Format
 First argument A is an array of integer
 Second argument B is an integer


 Output Format
 Return 1 if two such indexes are found and 0 otherwise


 Example Input
 Input 1:
 A = [1, 5, 3]
 B = 2
 Input 2:
 A = [2, 4, 3]
 B = 3


 Example Output
 Output 1:
 1
 Output 2:
 0


 Example Explanation
 For Input 1:
 The given value of A[1] = 1 and A[3] = 3.
 The value of A[3] - A[1] = 2.
 For Input 2:
 There are no pairs such that difference is B
 */
#include <iostream>
#include<unordered_set>
using namespace std;

int diffPossibleOpt(const vector<int> &A, int B) {
    if (A.size() < 2 || B < 0) return false;
 unordered_set<int> S;
 for (int i = 0; i < A.size(); i++) {
     int aj = A[i] - B;
     int ai = A[i] + B;
     if (S.find(aj) != S.end()) return true;
     if (S.find(ai) != S.end()) return true;
     S.insert(A[i]);
 }
 return false;
}

int diffPossible(const vector<int> &A, int B) {
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(abs(A[i]-A[j]) == B) return 1;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> A{1,3,2};
    cout<<"Diff K : "<<diffPossibleOpt(A, 0)<<endl;
    return 0;
}
