//
//  main.cpp
//  bulbs
//
//  Created by CodeBreaker on 10/08/1946 Saka.
//
/*
 Bulbs
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 A wire connects N light bulbs.
 Each bulb has a switch associated with it; however, due to faulty wiring, a switch also changes the state of all the bulbs to the right of the current bulb.
 Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.
 You can press the same switch multiple times.
 Note: 0 represents the bulb is off and 1 represents the bulb is on.


 Problem Constraints
 0 <= N <= 5×105
 0 <= A[i] <= 1


 Input Format
 The first and the only argument contains an integer array A, of size N.


 Output Format
 Return an integer representing the minimum number of switches required.


 Example Input
 Input 1:
  A = [0, 1, 0, 1]
 Input 2:
  A = [1, 1, 1, 1]


 Example Output
 Output 1:
  4
 Output 2:
  0


 Example Explanation
 Explanation 1:
  press switch 0 : [1 0 1 0]
  press switch 1 : [1 1 0 1]
  press switch 2 : [1 1 1 0]
  press switch 3 : [1 1 1 1]
 Explanation 2:
  There is no need to turn any switches as all the bulbs are already on.
 */
#include <iostream>
#include<vector>
using namespace std;

int bulbsOpt(vector<int> &A)
{
    int flag=0;
    int N=A.size();
    int ans=0;
    for(int i=0;i<N;i++)
    {
        if(A[i]==flag)
        {
            flag= (flag==0)?1:0;
            ans+=1;
        }
    }
    return ans;
}

int bulbs(vector<int> &A) {
    int ans=0;
    int N=A.size();
    vector<int> tmp(A);
    for(int i=0;i<N;i++)
    {
        tmp[i]=A[i];
    }
    
    for(int i=0;i<N;i++)
    {
        if(tmp[i]==0)
        {
            ans+=1;
            for(int j=i+1;j<N;j++)
            {
                if(tmp[j]==0)
                {
                    tmp[j]=1;
                } else {
                    tmp[j]=0;
                }
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, bulbs!\n";
    vector<int> v{0, 1, 0, 1};
    cout<<bulbsOpt(v)<<endl;
    return 0;
}
