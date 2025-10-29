//
//  main.cpp
//  array_christmastree
//
//  Created by CodeBreaker on 19/08/1946 Saka.
//
/*
 Christmas Trees
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an array A consisting of heights of Christmas trees and an array B of the same size consisting of the cost of each of the trees (Bi is the cost of tree Ai, where 1 ≤ i ≤ size(A)), and you are supposed to choose 3 trees (let's say, indices p, q, and r), such that Ap < Aq < Ar, where p < q < r.
 The cost of these trees is Bp + Bq + Br.
 You are to choose 3 trees such that their total cost is minimum. Return that cost.
 If it is not possible to choose 3 such trees return -1.


 Problem Constraints
 1 <= A[i], B[i] <= 109
 3 <= size(A) = size(B) <= 3000


 Input Format
 First argument is an integer array A.
 Second argument is an integer array B.


 Output Format
 Return an integer denoting the minimum cost of choosing 3 trees whose heights are strictly in increasing order, if not possible, -1.


 Example Input
 Input 1:
  A = [1, 3, 5]
  B = [1, 2, 3]
 Input 2:
  A = [1, 6, 4, 2, 6, 9]
  B = [2, 5, 7, 3, 2, 7]


 Example Output
 Output 1:
  6
 Output 2:
  7


 Example Explanation
 Explanation 1:
  We can choose the trees with indices 1, 2 and 3, and the cost is 1 + 2 + 3 = 6.
 Explanation 2:
  We can choose the trees with indices 1, 4 and 5, and the cost is 2 + 3 + 2 = 7.
  This is the minimum cost that we can get.
 */
#include <iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A, vector<int> &B) {
    int ans=INT_MAX;
    size_t N=A.size();
    for(int q=1;q<N-1;q++)
    {
        int L=INT_MAX;
        for(int p=0;p<q;p++)
        {
            if(A[p]<A[q])
            {
                L=min(L,B[p]);
            }
        }
        int R=INT_MAX;
        for(int r=q+1;r<N;r++)
        {
            if(A[r]>A[q])
            {
                R=min(R,B[r]);
            }
        }
        
        if(L!=INT_MAX && R!=INT_MAX)
        {
            ans=min(ans,(L+B[q]+R));
        }
        
    }
    
    return ans==INT_MAX ? -1 : ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Christmas Tree!\n";
    cout<<"-------------------\n";
    vector<int> A{802030518,598196518,640274071,983359971,71550121,96204862,799843967,446173607,796619138,402690754};
    vector<int> B{23219513,68171337,12183499,5549873,73542337,66661387,79397647,34495917,31413076,50918417};
    cout<<"Min Count : "<<solve(A, B)<<endl;
    return 0;
}
