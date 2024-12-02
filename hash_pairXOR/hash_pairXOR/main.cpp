//
//  main.cpp
//  hash_pairXOR
//
//  Created by CodeBreaker on 30/11/24.
//
/*
 Pairs With Given Xor
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer array A containing N distinct integers.
 Find the number of unique pairs of integers in the array whose XOR is equal to B.
 NOTE:
 Pair (a, b) and (b, a) is considered to be the same and should be counted once.


 Problem Constraints
 1 <= N <= 105
 1 <= A[i], B <= 107


 Input Format
 The first argument is an integer array A.
 The second argument is an integer B.


 Output Format
 Return a single integer denoting the number of unique pairs of integers in the array A whose XOR is equal to B.


 Example Input
 Input 1:
  A = [5, 4, 10, 15, 7, 6]
  B = 5
 Input 2:
  A = [3, 6, 8, 10, 15, 50]
  B = 5


 Example Output
 Output 1:
  1
 Output 2:
  2


 Example Explanation
 Explanation 1:
  (10 ^ 15) = 5
 Explanation 2:
  (3 ^ 6) = 5 and (10 ^ 15) = 5
 */

#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int solve_opt(vector<int> &A, int B) {
    size_t N = A.size();
    int cnt=0;
    unordered_set<int> us;
    us.insert(A[0]);
    for(int i=1; i<N;i++)
    {
        int t= B^A[i];
        if(us.find(t)!=us.end())
        {
            cnt++;
        }
        us.insert(A[i]);
    }
    return cnt;
}

int solve(vector<int> &A, int B) {
    size_t N = A.size();
    int cnt=0;
    for(int i=0; i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if((A[i]^A[j])==B) cnt+=1;
        }
    }
    return cnt;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, pair XOR!\n";
    vector<int> A{78,68,37,63,72,12,54,82,19,3,59,50,74,86,89,101,52,13,97,10,61,11,7,83,8,14,70,75,60,93,34,31,35,16,47,46,69,49,20,29,23,44,71,56,24,25,87,18,33,27,58,80,21,84,99,4,41,57,73,94,48,28,79,36,98,17,38,42,22,45,5,81,62,96,65,85,32,100,39,67,66,15,9,55,90,102,76,64,51,91,77,40,88,30,53,95,6,92,26,43};
    cout<<"Pair XOR : "<<solve_opt(A, 1)<<endl;
    return 0;
}
