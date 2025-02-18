//
//  main.cpp
//  heap_heapQuery
//
//  Created by CodeBreaker on 16/02/25.
//

/*
 Heap Queries
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You have an empty min heap. You are given an array A consisting of N queries. Let P denote A[i][0] and Q denote A[i][1]. There are two types of queries:

 P = 1, Q = -1 : Pop the minimum element from the heap.
 P = 2, 1 <= Q <= 109 : Insert Q into the heap.
 Return an integer array containing the answer for all the extract min operation. If the size of heap is 0, then extract min should return -1.


 Problem Constraints
 1 <= N <= 105
 1 <= A[i][0] <= 2
 1 <= A[i][1] <= 109 or A[i][1] = -1


 Input Format
 The only argument A is a 2D integer array


 Output Format
 Return an integer array


 Example Input
 Input 1:
 A = [[1, -1], [2, 2], [2, 1], [1, -1]]
 Input 2:
 A = [[2, 5], [2, 3], [2, 1], [1, -1], [1, -1]]


 Example Output
 Output 1:
 [-1, 1]
 Output 2:
 [1, 3]


 Example Explanation
 Explanation 1:
 For the first extract operation the heap is empty so it gives -1. For the second extract operation the heap contains the elements 2 and 1. Extract min returns the element 1.
 Explanation 2:
 The heap contains the elements 5, 3 and 1. The first extract min operation gets the element 1 and the second operation gets the element 3.
 */

#include <iostream>
#include <queue>

#include "heap.h"

vector<int> solve(vector<vector<int> > &A) {
    auto ans = vector<int>();
    auto minHeap = priority_queue<int, vector<int>, greater<>>();
    
    for(auto i : A)
    {
        if(i[0]==1){
            if(!minHeap.empty())
            {
                ans.push_back(minHeap.top());
                minHeap.pop();
            } else {
                ans.push_back(-1);
            }
        } else {
            minHeap.push(i[1]);
        }
    }
    return ans;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, implementstion of MinHeap!\n";
    vector<vector<int>> A{{2,7},{2,9},{2,1},{2,5},{2,2},{1,-1},{1,-1},{1,-1}};
    auto ans = solve(A);
    for(auto a:ans)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}

