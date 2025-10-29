//
//  main.cpp
//  dp_maxSubSeqSum
//
//  Created by CodeBreaker on 14/06/25.
//

#include <iostream>
#include <vector>
using namespace std;
//get maximum sum of subsequence formed by given array
int getMaxSubSeqSum(vector<int> &A, vector<int> &dp, int i)
{
    if(i<0) return 0;
    if(i==0) return A[0];
    if(dp[i]==-1){
        dp[i]= max(getMaxSubSeqSum(A, dp, i-1), getMaxSubSeqSum(A, dp, i-2)+A[i]); //here one is for pick condition and other one for not picking and also question says about not picking adjacent element hence removing same adding A[i]
    }
    return dp[i];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, get max sum of sub sequence formed buy given array!\n";;
    vector<int> A{1,2,3};
    vector<int> dp(A.size(),-1);
    cout<<"Max sub seq sum is : "<<getMaxSubSeqSum(A, dp, A.size()-1)<<endl;

    return 0;
}
