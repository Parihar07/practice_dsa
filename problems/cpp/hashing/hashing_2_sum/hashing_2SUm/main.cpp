//
//  main.cpp
//  hashing_2SUm
//
//  Created by CodeBreaker on 30/11/24.
//
/*
 2 Sum
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers, find two numbers such that they add up to a specific target number.
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.
 If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.
 Input: [2, 7, 11, 15], target=9
 Output: index1 = 1, index2 = 2
 
 // First, store ALL occurrences in a map
 unordered_map<int, vector<int>> UM;  // number -> vector of indices
 for(int i=0; i<N; i++) {
     UM[A[i]].push_back(i+1);
 }

 // Then for each number, look for its complement
 for(int i=0; i<N; i++) {
     int t = B-A[i];
     if(UM.find(t) != UM.end()) {
         // If same number needed twice, check if we have second occurrence
         if(t == A[i]) {
             if(UM[t].size() > 1) {
                 // Update ind1, ind2 if better pair found
             }
         } else {
             // Different numbers - use first occurrence of t
             // Update ind1, ind2 if better pair found
         }
     }
 }
 
 --------
 
 if(t == A[i]) {
     if(UM[t].size() > 1)
    {  // need at least 2 occurrences
         int curr_i = i+1;
         int curr_j = UM[t][1];  // second occurrence
         if(curr_j < ind2 || (curr_j == ind2 && curr_i < ind1))
         {
             ind1 = curr_i;
             ind2 = curr_j;
         }
     }
 }
 
 
 ------------------
 */
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twoSum(const vector<int> &A, int B) {
    size_t N = A.size();
    int ind1=INT_MAX, ind2=INT_MAX;
    vector<int> ans(2);
    unordered_map<int,vector<int>> UM;//store element and index of 1 ordered
    for(int i=0;i<N;i++)
    {
        UM[A[i]].push_back(i+1);
    }
    for(int i=0;i<N;i++)
    {
        int t = B-A[i];
        if(UM.find(t)!=UM.end())
        {
            if(t==A[i])
            {
                if(UM[t].size() > 1)
               {  // need at least 2 occurrences
                    int curr_i = i+1;
                    int curr_j = UM[t][1];  // second occurrence
                    if(curr_j < ind2 || (curr_j == ind2 && curr_i < ind1))
                    {
                        ind1 = curr_i;
                        ind2 = curr_j;
                    }
                }
            } else {
                for(int idx : UM[t])
                {  // try all indices of t
                    if(idx > i+1)
                    {     // make sure second index is larger
                        if(idx < ind2 || (idx == ind2 && i+1 < ind1))
                        {
                            ind1 = i+1;
                            ind2 = idx;
                        }
                    }
                }
            }
        }
    }
    if(ind1==-1 || ind2==-1)
    {
        return vector<int>();
    } else {
        ans[0]=ind1;
        ans[1]=ind2;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, 2 sum world!\n";
    vector<int> A{1,1,1,1/*-5,1,4,-7,10,-7,0,7,3,0,-2,-5,-3,-6,4,-7,-8,0,4,9,4,1,-8,-6,-6,0,-9,5,3,-9,-5,-9,6,3,8,-10,1,-2,2,1,-9,2,-3,9,9,-10,0,-9,-2,7,0,-4,-3,1,6,-3*/};
    vector<int> ans = twoSum(A, 2);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl; 
    return 0;
}
