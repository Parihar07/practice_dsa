//
//  main.cpp
//  backtracking_ndigiNum
//
//  Created by CodeBreaker on 06/02/25.
//
/*
 Given N Digits print all the N digit number having 1 and 2 in increasing order of numbers
 N=2
 1 1
 1 2
 2 1
 2 2
 N=3
 1 1 1
 1 1 2
 1 2 1
 1 2 2
 2 2 2
 2 2 1
 2 1 2
 2 1 1
 
    
 */
#include <iostream>
#include <vector>
using namespace std;

void ndigit(vector<int> &A, int ind, int N)
{
    if(ind==N)
    {
        for(auto i : A) cout<<i<<" ";
        cout<<endl;
        return;
    }
    A[ind]=1;
    ndigit(A, ind+1, N);
    A[ind]=2;
    ndigit(A, ind+1, N);
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, backtracking ndigits number!\n";
    int N =4;
    vector<int> v(N);
    ndigit(v, 0, N);
    return 0;
}
