//
//  main.cpp
//  sorting_mergesubarray
//
//  Created by CodeBreaker on 09/01/25.
//

#include <iostream>
#include <vector>
using namespace std;
/*
 Given array of N eleements and indices start S, end E, between M, Subarray[S, M] and subarrray[M+1, E] is sorted, sort the subarray from[S,E]
 */

void mergeSubArray(vector<int> &A, int S, int M, int E)
{
    int p1 = S, p2 = M+1;
    int len = E-S+1;
    vector<int> tV(len); int i=0;
    while(p1<=M &&
          p2 <=E)
    {
        if(A[p1]<A[p2])
        {
            tV[i]=A[p1];p1++;i++;
        } else {
            tV[i]=A[p2];p2++;i++;
        }
    }
    while(p1<=M)
    {
        tV[i]=A[p1];p1++;i++;
    }
    while(p2<=E)
    {
        tV[i]=A[p2];p2++;i++;
    }
    i=0;
    while(S<=E)
    {
        A[S++]=tV[i++];
    }
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, sory subarray!\n";
    
    vector<int> A{4,8,-1,2,6,9,11,3,4,7,13,0};
    mergeSubArray(A,1,1,2);
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
