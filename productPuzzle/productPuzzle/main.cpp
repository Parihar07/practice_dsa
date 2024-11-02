//
//  main.cpp
//  productPuzzle
//
//  Created by CodeBreaker on 10/08/1946 Saka.
//
/*Product array puzzle
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Given an array of integers A, find and return the product array of the same size where the ith element of the product array will be equal to the product of all the elements divided by the ith element of the array.
 Note: It is always possible to form the product array with integer (32 bit) values. Solve it without using the division operator.

 Input Format
 The only argument given is the integer array A.
 Output Format
 Return the product array.
 Constraints
 2 <= length of the array <= 1000
 1 <= A[i] <= 10
 For Example
 Input 1:
     A = [1, 2, 3, 4, 5]
 Output 1:
     [120, 60, 40, 30, 24]

 Input 2:
     A = [5, 1, 10, 1]
 Output 2:sfds
     [10, 50, 5, 50]
 */
#include <iostream>
#include<vector>
using namespace::std;
int divideLol(long long N, int d)
{
    int c=0;
    while(N>=d)
    {
        N-=d;
        c+=1;
    }
    return c;
}
vector<int> solve(vector<int> &A) {
    vector<int> ans(A.size());
    long long p=A[0]; int N=A.size();
    for(int i=0;i<N;i++)
    {
        p*=A[i];
    }
    for(int i=0;i<N;i++)
    {
        ans[i]= divideLol(p, A[i]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Product Puzzle!\n";
    vector<int> v{9,3,5,2,7,8,4,9,3,7,1,10,5,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    vector<int> ans = solve(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
