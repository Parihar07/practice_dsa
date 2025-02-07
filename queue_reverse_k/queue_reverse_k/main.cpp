//
//  main.cpp
//  queue_reverse_k
//
//  Created by CodeBreaker on 22/01/25.
//
/*
 Reversing Elements Of Queue
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A and an integer B, we need to reverse the order of the first B elements of the array,
 leaving the other elements in the same relative order.

 NOTE: You are required to the first insert elements into an auxiliary queue then perform Reversal of first B elements.


 Problem Constraints
 1 <= B <= length of the array <= 500000
 1 <= A[i] <= 100000


 Input Format
 The argument given is the integer array A and an integer B.


 Output Format
 Return an array of integer after reversing the first B elements of A using queue.


 Example Input
 Input 1:
  A = [1, 2, 3, 4, 5]
  B = 3
 Input 2:
  A = [5, 17, 100, 11]
  B = 2


 Example Output
 Output 1:
  [3, 2, 1, 4, 5]
 Output 2:
  [17, 5, 100, 11]


 Example Explanation
 Explanation 1:
  Reverse first 3 elements so the array becomes [3, 2, 1, 4, 5]
 Explanation 2:
  Reverse first 2 elements so the array becomes [17, 5, 100, 11]
 */
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
class Solution{
public:
public:
    static vector<int> solve(vector<int> &A, int B);
    static vector<int> solve2(vector<int> &A, int B);
};

vector<int> Solution::solve(vector<int> &A, int B) {
    size_t N = A.size();
    auto stk = stack<int>();
    auto q = queue<int>();
    auto ans = vector<int>();
    
    for(auto i:A)
    {
        q.push(i);
    }
    
    for(int i=0;i<B;i++)
    {
        int t=q.front();
        stk.push(t);
        q.pop();
    }
    int i=0;
    while(!stk.empty())
    {
        q.push(stk.top()); stk.pop();
    }
    while(!q.empty())
    {
        if(i<(N-B))
        {
            q.push(q.front());i++;
        } else {
            ans.push_back(q.front());
        }
        q.pop();
    }
    
    return ans;
}

vector<int> Solution::solve2(vector<int> &A, int B) {
    int N = A.size();
    queue<int> q;

    // Initialize queue
    for (int num : A) {
        q.push(num);
    }

    // Reverse first B elements
    for (int i = 0; i < B; i++) {
        int front = q.front();
        q.pop();

        // Move N-1 elements to back
        for (int j = 0; j < N - 1; j++) {
            q.push(q.front());
            q.pop();
        }

        q.push(front);
    }

    // Convert queue to vector
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    return result;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, reverse k elements !\n";
    vector<int> A={443,66,7,355,243,126,272,271,465,425,138,358,39,351,101};
    auto ans = Solution::solve2(A, 15);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
