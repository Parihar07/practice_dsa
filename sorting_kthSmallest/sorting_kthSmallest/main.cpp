//
//  main.cpp
//  sorting_kthSmallest
//
//  Created by CodeBreaker on 07/01/25.
//
/*
 Kth Smallest Element
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Find the Bth smallest element in given array A .
 NOTE: Users should try to solve it in less than equal to B swaps.


 Problem Constraints
 1 <= |A| <= 100000
 1 <= B <= min(|A|, 500)
 1 <= A[i] <= 109


 Input Format
 The first argument is an integer array A.
 The second argument is integer B.


 Output Format
 Return the Bth smallest element in given array.


 Example Input
 Input 1:
 A = [2, 1, 4, 3, 2]
 B = 3
 Input 2:
 A = [1, 2]
 B = 2


 Example Output
 Output 1:
  2
 Output 2:
  2


 Example Explanation
 Explanation 1:
  3rd element after sorting is 2.
 Explanation 2:
  2nd element after sorting is 2.
 */
#include <iostream>
#include <vector>
using namespace std;
int kthsmallest(vector<int> &A, int B) {
    size_t N = A.size();
    int ind=0;
    for(int i=0;i<B;i++)
    {
        int mini = A[i];
        ind =i;
        for(int j=i+1;j<N;j++)
        {
            if(A[j]<mini)
            {
                mini=A[j];
                ind = j;
            }
        }
        int t = A[i];
        A[i] = A[ind];
        A[ind] = t;
    }
    return A[B-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, kth smallest eleemnt !\n";
    vector<int> A{94,87,100,11,23,98,17,35,43,66,34,53,72,80,5,34,64,71,9,16,41,66,96};
    cout<<"SMallest K the term : "<<kthsmallest(A, 19);
    return 0;
}
