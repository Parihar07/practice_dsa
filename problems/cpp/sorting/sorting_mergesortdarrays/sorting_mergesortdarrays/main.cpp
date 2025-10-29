//
//  main.cpp
//  sorting_mergesortdarrays
//
//  Created by CodeBreaker on 07/01/25.
//
/*
 Merge Two Sorted Arrays
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given two sorted integer arrays A and B, merge B and A as one sorted array and return it as an output.

 Note: A linear time complexity is expected and you should avoid use of any library function.


 Problem Constraints
 -2×109 <= A[i], B[i] <= 2×109
 1 <= |A|, |B| <= 5×104


 Input Format
 First Argument is a 1-D array representing  A.
 Second Argument is also a 1-D array representing B.


 Output Format
 Return a 1-D vector which you got after merging A and B.


 Example Input
 Input 1:
 A = [4, 7, 9]
 B = [2, 11, 19]
 Input 2:
 A = [1]
 B = [2]


 Example Output
 Output 1:
 [2, 4, 7, 9, 11, 19]
 Output 2:
 [1, 2]


 Example Explanation
 Explanation 1:
 Merging A and B produces the output as described above.
 Explanation 2:
  Merging A and B produces the output as described above.
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(const vector<int> &A, const vector<int> &B) {
    
    size_t M = A.size();
    size_t N = B.size();
    vector<int> ans;
    int p1=0,p2=0;
    while(p1<M && p2<N)
    {
        if(A[p1]<B[p2])
        {
            ans.push_back(A[p1]); p1++;
        } else {
            ans.push_back(B[p2]); p2++;
        }
    }
    while(p1<M)
    {
        ans.push_back(A[p1]); p1++;
    }
    while(p2<N)
    {
        ans.push_back(B[p2]); p2++;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Merge sorted arrays!\n";
    vector<int> A{4,7,9}, B{2,11,19};
    vector<int> ans = solve(A, B);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
