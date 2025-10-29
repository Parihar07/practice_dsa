//
//  main.cpp
//  sorting_consecutiveelements
//
//  Created by CodeBreaker on 07/01/25.
//
/*
 Array with consecutive elements
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of positive integers A, check and return whether the array elements are consecutive or not.

 NOTE: Try this with O(1) extra space.


 Problem Constraints
 1 <= length of the array <= 105
 1 <= A[i] <= 109


 Input Format
 The only argument given is the integer array A.


 Output Format
 Return 1 if the array elements are consecutive else return 0.


 Example Input
 Input 1:
  A = [3, 2, 6, 4, 5]
 Input 2:
  A = [1, 3, 2, 5]


 Example Output
 Output 1:
  1
 Output 2:
  0


 Example Explanation
 Explanation 1:
  As you can see all the elements are consecutive (i.e 2, 3, 4, 5, 6), so we return 1.
 Explanation 2:
  Element 4 is missing, so we return 0.
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int solve(vector<int> &A) {
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        int ind=i;
        int m = A[i];
        for(int j=i+1;j<N;j++)
        {
            if(A[j]<m)
            {
                m=A[j];
                ind = j;
            }
        }
        int t = A[i];
        A[i]=A[ind];
        A[ind]=t;
        if(i>=1)
        {
            t=A[i]-A[i-1];
            if(t!=1) return 0;
        }
    }
    return 1;
}

int solveOpt(vector<int> &A) //Extra space
{
    //idea consecutive number, number of element in between min and max should be equal to size of array.
    
    int mini=A[0];
    int maxi = A[0];
    unordered_set<int> US;
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        US.insert(A[i]);
        mini=min(mini,A[i]);
        maxi=max(maxi,A[i]);
    }
    return (((maxi-mini+1)==N)&&(US.size()==N)) ? 1 : 0;
}

int solveOpt2(vector<int> &A) { //No extra space
    sort(A.begin(), A.end());

  int p = A[0];

  for (int i = 1; i < A.size(); i++)
  {
    if (p+1 != A[i]) {
      return 0;
    }
    p = A[i];
  }
  return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, consecutive terms !\n";
    vector<int> A{1,1,3,4};
    cout<<solveOpt(A)<<endl;
    return 0;
}
