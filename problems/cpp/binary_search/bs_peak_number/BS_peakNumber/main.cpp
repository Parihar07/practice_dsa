//
//  main.cpp
//  BS_peakNumber
//
//  Created by CodeBreaker on 12/01/25.
//

#include <iostream>
#include<vector>
using namespace std;
/*
 Find a peak element
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A, find and return the peak element in it.
 An array element is considered a peak if it is not smaller than its neighbors. For corner elements, we need to consider only one neighbor.

 NOTE:
 It is guaranteed that the array contains only a single peak element.
 Users are expected to solve this in O(log(N)) time. The array may contain duplicate elements.


 Problem Constraints
 1 <= |A| <= 100000
 1 <= A[i] <= 109


 Input Format
 The only argument given is the integer array A.


 Output Format
 Return the peak element.


 Example Input
 Input 1:
 A = [1, 2, 3, 4, 5]
 Input 2:
 A = [5, 17, 100, 11]


 Example Output
 Output 1:
  5
 Output 2:
  100


 Example Explanation
 Explanation 1:
  5 is the peak.
 Explanation 2:
  100 is the peak.
 */
int solve(vector<int> &A) {
    size_t N = A.size();
    sort(A.begin(), A.end());
    return A[N-1];
}

int solveOpt(vector<int> &A)
{
    size_t N = A.size();
    int m=N/2;
    int l=0, h=N-1;
    while(l<=h)
    {
        m=(l+h)/2;
        if(m==0 && A[m]>A[m+1]) return A[m];
        if(m==N-1 && A[m]>A[m-1]) return A[m];
        if(A[m-1]>A[m]){
            h=m-1;
        }else if(A[m+1]>A[m]){
            l=m+1;
        }
        else
            return A[m];
    }
    return A[m];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Peak Number, World!\n";
    vector<int> A{1,2,3,4,5,6};
    cout<<"peak number : "<<solveOpt(A)<<endl;
    return 0;
}
