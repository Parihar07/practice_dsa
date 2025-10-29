//
//  main.cpp
//  specialIndex
//sdf
//  Created by CodeBreaker on 08/08/1946 Saka.
//
/*
 Special Index
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array, arr[] of size N, the task is to find the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.


 Problem Constraints
 1 <= N <= 105
 -105 <= A[i] <= 105
 Sum of all elements of A <= 109


 Input Format
 First argument contains an array A of integers of size N


 Output Format
 Return the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.


 Example Input
 Input 1:
 A = [2, 1, 6, 4]
 Input 2:
 A = [1, 1, 1]


 Example Output
 Output 1:
 1
 Output 2:
 3


 Example Explanation
 Explanation 1:
 Removing arr[1] from the array modifies arr[] to { 2, 6, 4 } such that, arr[0] + arr[2] = arr[1].
 Therefore, the required output is 1.
 Explanation 2:
 Removing arr[0] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1]
 Removing arr[1] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1]
 Removing arr[2] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1]
 Therefore, the required output is 3.
 */

#include <iostream>
#include<vector>
using namespace std;

int specialIndexOptim(vector<int> &A)
{
    int si=0;
    size_t N=A.size();
    vector<int> PFSO(A.size());
    vector<int> PFSE(A.size());
    PFSO[0]=0;
    PFSE[0]=(A[0]);
    for(int i=1;i<N;i++)
    {
        if(i%2==0)
        {
            PFSE[i]=PFSE[i-1]+(A[i]);
            PFSO[i]=PFSO[i-1];
        } else {
            PFSE[i]=PFSE[i-1];
            PFSO[i]=PFSO[i-1]+(A[i]);
        }
    }
    
    for(int id=0;id<N;id++)
    {
        int oddSum=0, evenSum=0;
        oddSum=PFSE[N-1]-PFSE[id];
        if(id!=0)
        {
            oddSum+=PFSO[id-1];
        }
        evenSum=PFSO[N-1]-PFSO[id];
        if(id!=0)
        {
            evenSum+=PFSE[id-1];
        }
        
        if(evenSum==oddSum) si++;
    }
    
    return si;
}

int specialIndex(vector<int> &A)
{
    int si=0;
    size_t N=A.size();  int skp=0;
    vector<int> tmp;
    int t=N;
    while(t)
    {
        for(int i=0;i<N;i++)
        {
            if(i==skp)
            {
                continue;
            } else {
                tmp.push_back(A[i]);
            }
           
        }
        skp++;
        int oddSum=0, evenSum=0;
        for(int j=0;j<tmp.size();j++)
        {
            if(j%2==0)
            {
                evenSum+=tmp[j];
            } else {
                oddSum+=tmp[j];
            }
        }
        if(evenSum==oddSum) si++;
        tmp.clear();
        t--;
    }
    
    return si;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v{2, 1, 6, 4}; /*v{-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20,-21,-22,-23,-24,-25,-26,-27,-28,-29,-30,-31,-32,-33,-34,69,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34};*/
    cout<<specialIndexOptim(v)<<endl;
    std::cout << "Hello, Special Index!\n";
    return 0;
}
