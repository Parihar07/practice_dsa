//
//  main.cpp
//  hash_kOccurances
//
//  Created by CodeBreaker on 29/11/24.
//
/*
 K Occurrences
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Groot has N trees lined up in front of him where the height of the i'th tree is denoted by H[i].
He wants to select some trees to replace his broken branches.
But he wants uniformity in his selection of trees.
So he picks only those trees whose heights have frequency B.
He then sums up the heights that occur B times. (He adds the height only once to the sum and not B times).
But the sum he ended up getting was huge so he prints it modulo 10^9+7.
In case no such cluster exists, Groot becomes sad and prints -1.
Constraints:
1.   1<=N<=100000
2.   1<=B<=N
3.   0<=H[i]<=10^9
Input: Integers N and B and an array C of size N
Output: Sum of all numbers in the array that occur exactly B times.
Example:
Input:
N=5 ,B=2 ,C=[1 2 2 3 3]
Output:
5
Explanation:
There are 3 distinct numbers in the array which are 1,2,3.
Out of these, only 2 and 3 occur twice. Therefore the answer is sum of 2 and 3 which is 5.
 */
#include <iostream>
#include<unordered_map>
using namespace std;
int mod=1000000007;
int getSum(int A, int B, vector<int> &C) {
    size_t N = C.size();
    unordered_map<int, int> um;
    int ans=0;
    int flag=0;
    for(int i=0;i<N;i++)
    {
        um[C[i]]+=1;
    }
    
    for(auto it:um)
    {
        if(it.second==B)
        {
            flag=1;
            ans+=it.first;
        }
    }
    
    return (ans==0 && flag!=1)?-1:(ans%mod);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, hash K occurances!\n";
    cout<<"---------------------\n";
    vector<int> A = {1000000000,1000000000,999999999,999999999,999999998,1};
    cout<<"Answer : "<<getSum(6, 2, A)<<endl;
    return 0;
}
