//
//  main.cpp
//  sorting_reversepair
//
//  Created by CodeBreaker on 11/01/25.
//
/*
 Reverse pairs
 Attempted
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A, we call (i, j) an important reverse pair if i < j and A[i] > 2*A[j].
 Return the number of important reverse pairs in the given array A.


 Problem Constraints
 1 <= length of the array <= 105
 -2 * 109 <= A[i] <= 2 * 109


 Input Format
 The only argument given is the integer array A.


 Output Format
 Return the number of important reverse pairs in the given array A.


 Example Input
 Input 1:
  A = [1, 3, 2, 3, 1]
 Input 2:
  A = [4, 1, 2]


 Example Output
 Output 1:
  2
 Output 2:
  1


 Example Explanation
 Explanation 1:
  There are two pairs which are important reverse pair
  i.e  (1, 4) => A[1] > 2 * A[4] => 3 > 2 * 1 => 3 > 2 and
       (3, 4) => A[3] > 2 * A[4] => 3 > 2 * 1 => 3 > 2.
 Explanation 2:
  There is only one pair
  i.e (0, 1) => A[0] > 2 * A[1] => 4 > 2 * 1 => 4 > 1
 */
#include <iostream>
#include <vector>
using namespace std;

void mergeArray2(vector<int> &A, int &rc, int s, int m, int e) {
    // First count pairs
    int j = m + 1;
    for(int i = s; i <= m; i++) {
        while(j <= e && A[i] > 2LL * A[j]) {
            j++;
        }
        rc += (j - (m + 1));
    }

    // Then do normal merge
    vector<int> temp(e-s+1);
    int i = s, k = 0;
    j = m+1;
    while(i <= m && j <= e) {
        if(A[i] <= A[j]) temp[k++] = A[i++];
        else temp[k++] = A[j++];
    }
    while(i <= m) temp[k++] = A[i++];
    while(j <= e) temp[k++] = A[j++];

    for(int i = 0; i < k; i++) {
        A[s+i] = temp[i];
    }
}

void mergeArray(vector<int> &A, int &rc, int s, int m, int e)
{
    int len = (e-s+1); vector<int> t(len); int ind=0;
    int p1 = s, p2 = m+1;
    while(p1<=m && p2<=e)
    {
        if(A[p1]<A[p2])
        {
            if(A[p1]>(2*A[p2])) rc+=1;
            t[ind++]=A[p1++];
        } else {
            t[ind++]=A[p2++];
        }
    }
    while(p1<=m)
    {
        t[ind++]=A[p1++];
    }
    while(p2<=e)
    {
        t[ind++]=A[p2++];
    }
    ind=0;
    while(s<=e)
    {
        A[s++]=t[ind++];
    }
}

void merge(vector<int> &A, int &rc, int s, int e)
{
    if(s==e) return;
    int m = (s+e)/2;
    merge(A,rc,s,m);
    merge(A,rc,m+1,e);
    mergeArray2(A, rc,s, m, e);
}

int solveOpt(vector<int> &A) {
    int rc=0;
    merge(A,rc,0,A.size()-1);
    return rc;
}

int solve(vector<int> &A) {
    size_t N = A.size();
    int ans=0;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(A[i]>2*A[j])
            {
                ans+=1;
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, reverse pairs !\n";
    vector<int> A{1,3,2,3,1};
    cout<<"Reverse pairs : "<<solveOpt(A)<<endl;
    return 0;
}
