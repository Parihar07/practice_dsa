//
//  main.cpp
//  bm_subarray_or
//
//  Created by CodeBreaker on 25/08/1946 Saka.
//
/*
 Subarrays with Bitwise OR 1
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array B of length A with elements 1 or 0. Find the number of subarrays such that the bitwise OR of all the elements present in the subarray is 1.
 Note : The answer can be large. So, return type must be long.


 Problem Constraints
 1 <= A <= 105


 Input Format
 The first argument is a single integer A.
 The second argument is an integer array B.


 Output Format
 Return the number of subarrays with bitwise array 1.


 Example Input
 Input 1:
  A = 3
 B = [1, 0, 1]
 Input 2:
  A = 2
 B = [1, 0]


 Example Output
 Output 1:
 5
 Output2:
 2


 Example Explanation
 Explanation 1:
 The subarrays are :- [1], [0], [1], [1, 0], [0, 1], [1, 0, 1]
 Except the subarray [0] all the other subarrays has a Bitwise OR = 1
 Explanation 2:
 The subarrays are :- [1], [0], [1, 0]
 Except the subarray [0] all the other subarrays has a Bitwise OR = 1
 */
#include <iostream>
#include<vector>
using namespace std;
long solve(int A, vector<int> &B) {
    long ans = ((long)A*(A+1))/2;
    long cnt=0;
    for(int i=0;i<A;i++)
    {
        
        if(B[i]==0)
        {
            cnt=1;
            for(int j=i+1;j<A;j++)
            {
                if(B[j]==0)
                {
                    cnt+=1;
                } else {
                    break;
                }
            }
        }
        i+=cnt;
        cnt=(cnt*(cnt+1))/2;
        ans-=cnt;
        cnt=0;
    }
    return ans;
}

long solve2(int A, vector<int> &B) {
    long ans = (long)A * (A + 1) / 2;
    long zeros = 0;

    for(int i = 0; i < A; i++) {
        if(B[i] == 0)
            zeros++;
        else {
            if(zeros > 0) {
                ans -= (zeros * (zeros + 1)) / 2;
                zeros = 0;
            }
        }
    }
    // Don't forget to handle zeros at the end
    if(zeros > 0)
        ans -= (zeros * (zeros + 1)) / 2;
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<"--------------------\n";
    vector<int> B{1,0,0}/*{0,1,0,1,1,1,0,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,0,0,1,0,1,1,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,1,1,1,0,0,1,0,0,0,1}*/;
    cout<<"Total OR subarrays : "<<solve(3, B)<<endl;
    return 0;
}
