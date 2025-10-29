//
//  main.cpp
//  dp_nstairs2
//
//  Created by CodeBreaker on 02/06/25.
//


/*
 * Given N-Steps how many ways we can gp from 0th -> Xth step
 */
#include <iostream>
#include <vector>
using namespace std;

int nstairs(int n)
{
    if(n<=1) return n;
    return nstairs(n-1)+nstairs(n-2);
}

int nstairsHelper(int n, vector<int> &dp)
{
    if(n<=1){
        dp[n]=n; return dp[n];
    }
    if(dp[n]==-1)
    {
        dp[n]=nstairsHelper(n-1, dp)+nstairsHelper(n-2, dp);
    }
    return dp[n];
}

//Memoization or tabulation way where TC is O(n)
int nstairs2(int n)
{
    vector<int> dp(n+1,-1); //defining the vector tp calculation and assigning values with invalid details;
    nstairsHelper(n, dp);
    return dp[n];
}

// memoisation and lambda

int nstairs3(int n)
{
    vector<int> dp(n+1, -1);
    function<int(int)> nstairsLambda;
    nstairsLambda = [&dp,&nstairsLambda](int k){
        if(k<=1){
            dp[k]=k;
            return dp[k];
        }
        if(dp[k]==-1){
            dp[k]=nstairsLambda(k-1)+nstairsLambda(k-2);
        }
        return dp[k];
    };
    nstairsLambda(n);
    return dp[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Nstairs problem!\n";
    
    cout<<" Number of seps need if you 5 stairs " <<nstairs3(6)<<endl;
    return 0;
}
