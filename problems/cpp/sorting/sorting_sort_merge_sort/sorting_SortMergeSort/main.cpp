//
//  main.cpp
//  sorting_SortMergeSort
//
//  Created by CodeBreaker on 09/01/25.
//
/*
 Merge Sort
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer array A, sort the array using Merge Sort.


 Problem Constraints
 1 <= |A| <= 105
 1 <= A[i] <= 109


 Input Format
 First argument is an integer array A.


 Output Format
 Return the sorted array.


 Example Input
 Input 1:-
 A = [1, 4, 10, 2, 1, 5]
 Input 2:-
 A = [3, 7, 1]


 Example Output
 Output 1:-
 [1, 1, 2, 4, 5, 10]
 Output 2:-
 [1, 3, 7]


 Example Explanation
 Explanation 1 and 2:
 Return the sorted array.
 */
#include <iostream>
#include <vector>
using namespace std;

void mergeSubArray(vector<int> &A, int S, int M, int E)
{
    int p1 = S, p2 = M+1;
    int len = E-S+1;
    vector<int> tV(len); int i=0;
    while(p1<=M &&
          p2 <=E)
    {
        if(A[p1]<A[p2])
        {
            tV[i]=A[p1];p1++;i++;
        } else {
            tV[i]=A[p2];p2++;i++;
        }
    }
    while(p1<=M)
    {
        tV[i]=A[p1];p1++;i++;
    }
    while(p2<=E)
    {
        tV[i]=A[p2];p2++;i++;
    }
    i=0;
    while(S<=E)
    {
        A[S++]=tV[i++];
    }
    return;
}

void merge(vector<int> &A, int S, int E)
{
    if(S==E) return;
    int M = (S+E)/2;
    merge(A,S,M);
    merge(A,M+1,E);
    mergeSubArray(A, S, M, E);
}
vector<int> solve(vector<int> &A) {
    vector<int> T=A;
    merge(T,0,(A.size()-1));
    return T;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Merge Sort!\n";
    vector<int> A{1,4,10,2, 1, 5};
    vector<int> ans = solve(A);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
