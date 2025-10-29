//
//  main.cpp
//  gcd_deleteone
//
//  Created by CodeBreaker on 03/01/25.
//
/*
 Delete one
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer array A of size N. You have to delete one element such that the GCD(Greatest common divisor) of the remaining array is maximum.

 Find the maximum value of GCD.


 Problem Constraints
 2 <= N <= 105
 1 <= A[i] <= 109


 Input Format
 First argument is an integer array A.


 Output Format
 Return an integer denoting the maximum value of GCD.


 Example Input
 Input 1:
  A = [12, 15, 18]
 Input 2:
  A = [5, 15, 30]


 Example Output
 Output 1:
  6
 Output 2:
  15


 Example Explanation
 Explanation 1:
  If you delete 12, gcd will be 3.
  If you delete 15, gcd will be 6.
  If you delete 18, gcd will 3.
  Maximum value of gcd is 6.
 Explanation 2:
  If you delete 5, gcd will be 15.
  If you delete 15, gcd will be 5.
  If you delete 30, gcd will be 5.
  Maximum value of gcd is 15.
 */
#include <iostream>
#include<vector>
using namespace std;

int gcd(int A, int B)
{
    if(B==0) return A;
    return gcd(B,A%B);
}

int solve(vector<int> &A) {
    size_t N = A.size();
    int ans = 0;
    vector<int> PFGCD(N), SFGCD(N);
    for(int i=0;i<N;i++)
    {
        ans=gcd(ans,A[i]);
        PFGCD[i]=ans;
    }
    ans=0;
    for(int i=N-1;i>=0;i--)
    {
        ans=gcd(ans,A[i]);
        SFGCD[i]=ans;
    }
    
    ans = SFGCD[1];
    ans = max(ans, PFGCD[N-2]);
    
    for(int i=1;i<N-1;i++)
    {
        ans = max(ans, gcd(PFGCD[i-1], SFGCD[i+1]));
    }
//    for(int i=0,j=0;i<N,j<N;i++,j++)
//    {
//        cout<<PFGCD[i] <<" : "<<SFGCD[j]<<endl;
//    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, delete gcd problem!\n";
    vector<int> A{5,15,30};
    cout<<"max GCD : \n"<<solve(A)<<endl;
    return 0;
}
