//
//  main.cpp
//  rangeSum
//
//  Created by CodeBreaker on 07/08/1946 Saka.
//

/*
 Range Sum Query
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an integer array A of length N.
 You are also given a 2D integer array B with dimensions M x 2, where each row denotes a [L, R] query.
 For each query, you have to find the sum of all elements from L to R indices in A (0 - indexed).
 More formally, find A[L] + A[L + 1] + A[L + 2] +... + A[R - 1] + A[R] for each query.


 Problem Constraints
 1 <= N, M <= 105
 1 <= A[i] <= 109
 0 <= L <= R < N


 Input Format
 The first argument is the integer array A.
 The second argument is the 2D integer array B.


 Output Format
 Return an integer array of length M where ith element is the answer for ith query in B.


 Example Input
 Input 1:
 A = [1, 2, 3, 4, 5]
 B = [[0, 3], [1, 2]]
 Input 2:
 A = [2, 2, 2]
 B = [[0, 0], [1, 2]]


 Example Output
 Output 1:
 [10, 5]
 Output 2:
 [2, 4]


 Example Explanation
 Explanation 1:
 The sum of all elements of A[0 ... 3] = 1 + 2 + 3 + 4 = 10.
 The sum of all elements of A[1 ... 2] = 2 + 3 = 5.
 Explanation 2:
 The sum of all elements of A[0 ... 0] = 2 = 2.
 The sum of all elements of A[1 ... 2] = 2 + 2 = 4.
 */

#include <iostream>
#include<vector>
using namespace std;

vector<long long> rangeSum(vector<int> &A, vector<vector<int> > &B) {
    vector<long long> ans(B.size());
    
    size_t N=B.size();
    long long sum=0;
    for(int i=0;i<N;i++)
    {
        int L=B[i][0];
        int R=B[i][1];
        for(int j=L;j<=R;j++)
        {
            sum+=A[j];
        }
        ans[i]=sum;
        
        sum=0;
    }
    return ans;
}

vector<long long> rangeSumOptimal(vector<int> &A, vector<vector<int> > &B) {
    vector<long long> ans(B.size());
    vector<long long> PFS(A.size());
    PFS[0]=A[0];
    for(int i=1;i<A.size();i++)
    {
        PFS[i]=PFS[i-1]+A[i];
    }
    size_t N=B.size();
    long long sum=0;
    for(int i=0;i<N;i++)
    {
        int L=B[i][0];
        int R=B[i][1];
        if(L==0)
        {
            ans[i]=PFS[R];
        } else {
            ans[i]=PFS[R]-PFS[L-1];
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A{720,79473,40625,68587,35751,5635,86295,522,96613,81173,67463,90371,78911,8415,90539,7434,22848,78504,42592,78437,47656,31353,28830,95539,35937,51021,90271,1033,74361,25764,64718,58167,93537,17975,13742,2634,45537,91654,86884,56650,34901,49740,66242,53124,65641,23508,51824,55362,4588,58149,74521,87189,68404,90425,81135,71093,878,24107,21212,92863,38175,27983,89671,91069,860,94171,97407,26212,75331,73347,15815,9495,82165,58371,66174,88296,55024};
    vector<vector<int> > B{{45,53},{6,75},{17,76},{10,43},{60,61},{35,62},{3,73},{33,70},{21,65},{46,47},{23,26},{45,48},{22,52},{44,56},{5,58},{35,57},{63,75},{8,31},{19,23},{38,40},{16,26},{56,73},{32,67},{46,50},{30,70},{5,42},{0,37},{14,51},{49,64},{11,49},{46,71},{14,33},{7,60},{15,64},{6,74},{17,68},{38,51},{37,43},{25,62},{7,59},{52,57}};
    vector<long long> rt = rangeSum(A, B);
    
    for(int i=0;i<B.size();i++)
    {
        cout<<rt[i]<<" ";
    }
    cout<<endl;
    std::cout << "Hello, Range Sum!\n";
    return 0;
}
