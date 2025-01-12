//
//  main.cpp
//  sorting_rearrange_qsort
//
//  Created by CodeBreaker on 12/01/25.
//

#include <iostream>
#include<iostream>
using namespace std;

/*
 Given array A of N eleemtns such that A[0] should go to its correct position ,
 1) all eleents less than A[0] should be left and
 2) greater should be right
 3) in BigO O(1) TC
 */

void rightPos(vector<int> &A)
{
    size_t N = A.size();
    int p1=1, p2=N-1;
    while(p1<=p2)
    {
        if(A[p1]<A[0])
        {
            p1++;
        } else if(A[p2]>A[0]) {
            p2--;
        } else {
            int t = A[p1];
            A[p1]=A[p2];
            A[p2]=t;
            p1++;p2--;
        }
    }
    int t = A[0];
    A[0]=A[p2];
    A[p2]=t;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Right position !\n";
    vector<int> A{10,3,8,15,6,12,2,18,7,15,14};
    rightPos(A);
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<< " ";
    }
    cout<<endl;
    return 0;
}
