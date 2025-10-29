//
//  main.cpp
//  hashing_DistinctinWindw
//
//  Created by CodeBreaker on 30/11/24.
//

/*
 Distinct Numbers in Window
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.
 Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.
 NOTE: if B > N, return an empty array.


 Problem Constraints
 1 <= N <= 106

 1 <= A[i] <= 109


 Input Format
 First argument is an integer array A
 Second argument is an integer B.


 Output Format
 Return an integer array.


 Example Input
 Input 1:
  A = [1, 2, 1, 3, 4, 3]
  B = 3
 Input 2:
  A = [1, 1, 2, 2]
  B = 1


 Example Output
 Output 1:
  [2, 3, 3, 2]
 Output 2:
  [1, 1, 1, 1]


 Example Explanation
 Explanation 1:
  A=[1, 2, 1, 3, 4, 3] and B = 3
  All windows of size B are
  [1, 2, 1]
  [2, 1, 3]
  [1, 3, 4]
  [3, 4, 3]
  So, we return an array [2, 3, 3, 2].
 Explanation 2:
  Window size is 1, so the output array is [1, 1, 1, 1].
 */

#include <iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

vector<int> dNumsOpt(vector<int> &A, int B) {
    vector<int> ans(0);
    size_t N = A.size();
    unordered_map<int,int> UM;// Elemetn and count
    if(B>N) return vector<int>(); // given in question if B>N return empty array
    for(int i=0;i<B;i++)
    {
        UM[A[i]]+=1;
    }
    for(int k=1;k<=(N-B);k++)
    {
        ans.push_back((int)UM.size());
        int i=k-1;
        if(UM.find(A[i]) != UM.end())
        {
            UM[A[i]]-=1;
            if(UM[A[i]]==0)
            {
                UM.erase(A[i]);
            }
        } else {
            UM.erase(A[i]);
        }
        int j = (B+k-1);
        UM[A[j]]+=1;
    }
    ans.push_back((int)UM.size());
    return ans;
}

vector<int> dNums(vector<int> &A, int B) {
    vector<int> ans(0);
    size_t N = A.size();
    unordered_set<int> US; // tp store windows elements
    for(int i=0;i<=(N-B);i++)
    {
        for(int j=i;j<=(i+B-1);j++)
        {
            US.insert(A[j]);
        }
        ans.push_back(US.size());
        US.erase(A[i]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Distinct elemens in windows!\n";
    vector<int> A{1,1,2,2};
    vector<int> ans = dNumsOpt(A, 1);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
