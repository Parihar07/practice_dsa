//
//  main.cpp
//  equilibium
//
//  Created by CodeBreaker on 06/08/1946 Saka.
//
/*
 Equilibrium index of an array

 Problem Description
 You are given an array A of integers of size N.
 Your task is to find the equilibrium index of the given array
 The equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
 If there are no elements that are at lower indexes or at higher indexes, then the corresponding sum of elements is considered as 0.
 Note:
 Array indexing starts from 0.
 If there is no equilibrium index then return -1.
 If there are more than one equilibrium indexes then return the minimum index.


 Problem Constraints
 1 <= N <= 105
 -105 <= A[i] <= 105


 Input Format
 First arugment is an array A .


 Output Format
 Return the equilibrium index of the given array. If no such index is found then return -1.


 Example Input
 Input 1:
 A = [-7, 1, 5, 2, -4, 3, 0]
 Input 2:
 A = [1, 2, 3]


 Example Output
 Output 1:
 3
 Output 2:
 -1


 Example Explanation
 Explanation 1:
 i   Sum of elements at lower indexes    Sum of elements at higher indexes
 0                   0                                   7
 1                  -7                                   6
 2                  -6                                   1
 3                  -1                                  -1
 4                   1                                   3
 5                  -3                                   0
 6                   0                                   0

 3 is an equilibrium index, because:
 A[0] + A[1] + A[2] = A[4] + A[5] + A[6]
 Explanation 1:
 i   Sum of elements at lower indexes    Sum of elements at higher indexes
 0                   0                                   5
 1                   1                                   3
 2                   3                                   0
 Thus, there is no such index.
 */

#include <iostream>
#include<vector>

using namespace std;

class Solution{
public:
    
};

int equillibiumIndexOptimal(vector<int> &A)
{
    int ind=-1;
    int lSum=0,RSum=0;
    int N=A.size();
    vector<int> PFS(A.size());
    PFS[0]=A[0];
    for(int i=1;i<A.size();i++)
    {
        PFS[i]+=PFS[i-1]+A[i];
    }
    
    for(int i=0;i<N;i++)
    {
        if(i==0)
        {
            lSum=0;
        } else {
            lSum=PFS[i-1];
        }
        
        if(i==N-1)
        {
            RSum=0;
        } else {
            RSum=PFS[N-1]-PFS[i];
        }
        if(lSum==RSum)
        {
            if(ind<0)
            {
                ind = i;
            } else {
                ind=min(ind,i);
            }
            
        }
    }
    return ind;
}

int equillibiumIndexBruteForce(vector<int> &A)
{
    int ind=-1;
    int lSum=0,RSum=0;
    int N=A.size();
    for(int i=0;i<N;i++)
    {
        if(i==0)
        {
            lSum=0;
        } else {
        for(int k=0;k<i;k++)
        {
           lSum+=A[k];
        }}
        
        if(i==N-1)
        {
            RSum=0;
        } else {
        for(int j=i+1;j<N;j++)
        {
            RSum+=A[j];
        }}
        
        if(lSum==RSum)
        {
            if(ind<0)
            {
                ind = i;
            } else {
                ind=min(ind,i);
            }
            
        }
        lSum=RSum=0;
    }
    
    return ind;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Equillibium!\n";
    vector<int> arr{-7, 1, 5, 2, -4, 3, 0};
    cout<<"Equilibium Index is "<<equillibiumIndexOptimal(arr)<<endl;
    return 0;
}
