//
//  main.cpp
//  timetoEquality
//
//  Created by CodeBreaker on 10/08/1946 Saka.
//
/* Time to equality
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer array A of size N. In one second, you can increase the value of one element by 1.

 Find the minimum time in seconds to make all elements of the array equal.


 Problem Constraints
 1 <= N <= 1000000
 1 <= A[i] <= 1000


 Input Format
 First argument is an integer array A.


 Output Format
 Return an integer denoting the minimum time to make all elements equal.


 Example Input
 A = [2, 4, 1, 3, 2]


 Example Output
 8


 Example Explanation
 We can change the array A = [4, 4, 4, 4, 4]. The time required will be 8 seconds.
 */
#include <iostream>
#include<iostream>
using namespace std;

int solve(vector<int> &A) {
    int maxi = A[0]; int N=A.size();
    for(int i=0;i<N;i++)
    {
        maxi=max(maxi,A[i]);
    }
    int ans=0;
    for(int i=0;i<N;i++)
    {
        ans+=(maxi-A[i]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v{2, 4, 1, 3, 2};
    std::cout << "Hello, time of equality!\n";
    cout<<"Time of equality : " <<solve(v)<<endl;
    return 0;
}
