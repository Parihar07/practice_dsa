//
//  main.cpp
//  arrays_plusone
//
//  Created by CodeBreaker on 18/12/24.
//
/*
 Add One To Number
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).
 The digits are stored such that the most significant digit is at the head of the list.
 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: for this problem, the following are some good questions to ask :
 Q: Can the input have 0's before the most significant digit. Or, in other words, is 0 1 2 3 a valid input?
 A: For the purpose of this question, YES
 Q: Can the output have 0's before the most significant digit? Or, in other words, is 0 1 2 4 a valid output?
 A: For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.


 Problem Constraints
 1 <= size of the array <= 1000000


 Input Format
 First argument is an array of digits.


 Output Format
 Return the array of digits after adding one.


 Example Input
 Input 1:
 [1, 2, 3]


 Example Output
 Output 1:
 [1, 2, 4]


 Example Explanation
 Explanation 1:
 Given vector is [1, 2, 3].
 The returned vector should be [1, 2, 4] as 123 + 1 = 124.
 */
#include <iostream>
#include<vector>

using namespace std;

vector<int> plusOneOpt(vector<int> &A)
{
    size_t N = A.size();
    int nines=1;
    for(int i=0;i<N;i++)
    {
        if(A[i]!=9){
            nines=0;
        }
    }
    vector<int> ans(N);
    if(nines)
    {
        ans.resize(N+1,0);
        ans[0]=1;
        return ans;
    }
    if(A[N-1]<9)
    {
        A[N-1]+=1;
    } else {
        A[N-1]=0;
        int i = N-2;
        int carry = 1;
        while(carry && i>=0)
        {
            if(A[i]<9)
            {
                A[i]+=1;
                carry = 0;
            } else {
                A[i]=0;
            }
            i--;
        }
    }
    if(A[0]==0)
    {
        int flag = 0;
        int cnt=0,i=0;
        for(auto it=A.begin();it!=A.end();it++)
        {
            if(*it!=flag)
            {
                if(flag==0)
                {
                    ans.resize(N-cnt);
                    flag=-1;
                }
                ans[i++]=*it;
            } else {
                cnt+=1;
            }
        }
        return ans;
    }
    return A;
}

vector<int> plusOne(vector<int> &A) {
    size_t N = A.size();
    vector<int> ans(0);
    long digits=0;
    long tens=1;
    
    for(int i=N-1;i>=0;i--)
    {
        digits+=A[i]*tens;
        tens*=10;
    }
    digits+=1;
    while(digits)
    {
        int rem=digits%10;
        ans.push_back(rem);
        digits/=10;
    }
    size_t j=ans.size()-1;
    for(int i=0;i<j;i++)
    {
        int t = ans[i];
        ans[i]=ans[j];
        ans[j]=t;
        j--;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, plus one!\n";
    vector<int> A{0,0,4,4,6,0,9,6,5,1};
    vector<int> ans = plusOneOpt(A);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
