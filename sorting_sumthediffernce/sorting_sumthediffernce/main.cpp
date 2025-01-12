//
//  main.cpp
//  sorting_sumthediffernce
//
//  Created by CodeBreaker on 11/01/25.
//
/*
 Sum the Difference
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer array, A of size N.
 You have to find all possible non-empty subsequences of the array of numbers and then,
 for each subsequence, find the difference between the largest and smallest number in that subsequence.
 Then add up all the differences to get the number.
 As the number may be large, output the number modulo 1e9 + 7 (1000000007).
 NOTE: Subsequence can be non-contiguous.


 Problem Constraints
 1 <= N <= 10000
 1<= A[i] <=1000


 Input Format
 First argument is an integer array A.


 Output Format
 Return an integer denoting the output.


 Example Input
 Input 1:
 A = [1, 2]
 Input 2:
 A = [3, 5, 10]


 Example Output
 Output 1:
  1
 Output 2:
  21


 Example Explanation
 Explanation 1:
 All possible non-empty subsets are:
 [1]     largest-smallest = 1 - 1 = 0
 [2]     largest-smallest = 2 - 2 = 0
 [1, 2]  largest-smallest = 2 - 1 = 1
 Sum of the differences = 0 + 0 + 1 = 1
 So, the resultant number is 1
 Explanation 2:
 All possible non-empty subsets are:
 [3]         largest-smallest = 3 - 3 = 0
 [5]         largest-smallest = 5 - 5 = 0
 [10]        largest-smallest = 10 - 10 = 0
 [3, 5]      largest-smallest = 5 - 3 = 2
 [3, 10]     largest-smallest = 10 - 3 = 7
 [5, 10]     largest-smallest = 10 - 5 = 5
 [3, 5, 10]  largest-smallest = 10 - 3 = 7
 Sum of the differences = 0 + 0 + 0 + 2 + 7 + 5 + 7 = 21
 So, the resultant number is 21 
 */
#include <iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A) {
    size_t N = A.size();
    long long maxi = 0, mini = 0;
    long long mod = 1000000007;
    sort(A.begin(), A.end());
    for(int i=0; i<N; i++)
    {
        maxi = (A[i] * ((1LL << i) - 1)) % mod;; //1000000007
       
    }
    int k=0;
    for(int i=N-1;i>=0;i--)
    {
        mini = (A[i] * ((1LL << (N-i-1)) - 1)) % mod; k++;
    }
    return maxi-mini;
}

int solveOpt(vector<int> &A) {
    long long mod = 1000000007;
    int N = A.size();
    long long result = 0;
    sort(A.begin(), A.end());

    for(int i = 0; i < N; i++) {
        // Calculate powers using multiplication instead of bit shift
        long long max_power = 1;
        for(int j = 0; j < i; j++) {
            max_power = (max_power * 2) % mod;
        }

        long long min_power = 1;
        for(int j = 0; j < (N-i-1); j++) {
            min_power = (min_power * 2) % mod;
        }

        // Calculate contributions
        long long max_contribution = (1LL * A[i] * (max_power - 1)) % mod;
        long long min_contribution = (1LL * A[i] * (min_power - 1)) % mod;

        result = (result + max_contribution - min_contribution + mod) % mod;
    }
    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> A{3,5,10};
    cout<< "Sum of differnce : "<<solve(A)<<endl;
    return 0;
}
