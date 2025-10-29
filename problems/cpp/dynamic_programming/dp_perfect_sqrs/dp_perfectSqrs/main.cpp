//
//  main.cpp
//  dp_perfectSqrs
//
//  Created by CodeBreaker on 03/06/25.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 Find minimum number of perfect squares sum required to sum =N,
 
 */
// Greedy approach
int perfectSqrSum(int n)
{
    int ans = INT_MAX, firstHit = 0, N=n, i=n, count =0;;
    while(i>0)
    {
        while(N>0)
        {
            if(i*i<=N)
            {
                count++;
                N-=i*i;
                if(firstHit==0) firstHit=i;
            } else {
                i--;
            }
        }
        ans=min(ans,count); // getting minimum count of squares
        i=firstHit-1; // its next Square to chcek with
        firstHit=0;
        count =0;
        N=n;
    }
    return ans;
}

// Naother approach
int perfectSqrSm(int n)
{
    int ans = INT_MAX, count =0, tmpN=n;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j*j<=tmpN;)
        {
            if(j*j<=tmpN)
            {
                count++;
                tmpN-=j*j;
            } else {
                j--;
            }
        }
        ans=min(ans,count);
        count=0; tmpN=n;
    }
    return ans;
}

int perfectSqrRecursive(int n)
{
    if(n==0) return 0;
    int ans = INT_MAX;
    for(int i=1;i*i<=n;i++)
    {
        ans = 1+min(ans,perfectSqrRecursive(n-i*i));
    }
    return ans;
}

int dpApproach(int n)
{
    vector<int> dp(n+1, -1);
    function<int(int)> lambda_fun;
    lambda_fun = [&dp,&lambda_fun](int k){
        if(k==0) return 0;
       
        if(dp[k]==-1){
            int local_ans = INT_MAX;
            for(int i=1;i*i<=k;i++){
                local_ans = 1+min(local_ans, lambda_fun(k-i*i));
            }
            dp[k]=local_ans;
        }
        return dp[k];
    }; //lambda_fun
    lambda_fun(n);
    return dp[n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, perfecct square sum of given number !\n";
    
    cout<<"perfect square : "<<dpApproach(27)<<endl;
    return 0;
}
