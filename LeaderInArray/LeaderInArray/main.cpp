//
//  main.cpp
//  LeaderInArray
//
//  Created by CodeBreaker on 11/08/1946 Saka.
//
/*
 Leaders in an array
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer array A containing N distinct integers, you have to find all the leaders in array A. An element is a leader if it is strictly greater than all the elements to its right side.

 NOTE: The rightmost element is always a leader.


 Problem Constraints
 1 <= N <= 105
 1 <= A[i] <= 108


 Input Format
 There is a single input argument which a integer array A


 Output Format
 Return an integer array denoting all the leader elements of the array.


 Example Input
 Input 1:
  A = [16, 17, 4, 3, 5, 2]
 Input 2:
  A = [5, 4]


 Example Output
 Output 1:
 [17, 2, 5]
 Output 2:
 [5, 4]


 Example Explanation
 Explanation 1:
  Element 17 is strictly greater than all the elements on the right side to it.
  Element 2 is strictly greater than all the elements on the right side to it.
  Element 5 is strictly greater than all the elements on the right side to it.
  So we will return these three elements i.e [17, 2, 5], we can also return [2, 5, 17] or [5, 2, 17] or any other ordering.
 Explanation 2:
  Element 5 is strictly greater than all the elements on the right side to it.
  Element 4 is strictly greater than all the elements on the right side to it.
  So we will return these two elements i.e [5, 4], we can also any other ordering.
 */
#include <iostream>
#include<vector>

using namespace std;

vector<int> solveOpt(vector<int> &A)
{
    int N=A.size();
    int maxi=A[N-1];
    vector<int> ans;
    ans.push_back(maxi);
    
    for(int i=N-2;i>=0;i--)
    {
        if(A[i]>maxi)
        {
            maxi=A[i];
            ans.push_back(maxi);
        }
    }
    
    return ans;
}
vector<int> solve(vector<int> &A) {
    vector<int> ans;
    int N=A.size();
    int i=0,j=0;
    for( i=0;i<N-1;i++)
    {
        if(A[i]>A[i+1])
        {
            for(j=i+1;j<N;j++)
            {
                if(A[i]>A[j])
                {
                    continue;
                } else {
                    break;
                }
            }
            if(j==N)
            {
                ans.push_back(A[i]);
            }
        }
    }
    if(i==N-1)
    {
        ans.push_back(A[i]);
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Leader in Array!\n";
    vector<int> v{16, 17, 4, 3, 5, 2};
    vector<int> ans = solveOpt(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
