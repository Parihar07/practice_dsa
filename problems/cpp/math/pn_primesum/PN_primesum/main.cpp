//
//  main.cpp
//  PN_primesum
//
//  Created by CodeBreaker on 04/01/25.
//
/*
 Prime Sum
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an even number A ( greater than 2 ), return two prime numbers whose sum will be equal to the given number.
 If there is more than one solution possible, return the lexicographically smaller solution.
 If [a, b] is one solution with a <= b, and [c,d] is another solution with c <= d, then
 [a, b] < [c, d], If a < c OR a==c AND b < d.
 NOTE: A solution will always exist. Read Goldbach's conjecture.


 Problem Constraints
 4 <= A <= 2*107


 Input Format
 First and only argument of input is an even number A.


 Output Format
 Return a integer array of size 2 containing primes whose sum will be equal to given number.


 Example Input
  4


 Example Output
  [2, 2]


 Example Explanation
  There is only 1 solution for A = 4.
 */
#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

vector<int> primesum(int A) {
    vector<int> primes(A+1,0);
    int N =A+1;
    primes[0]=1;primes[1]=1; //as we already know 0,1 are not primes
    for(int p=2;p<N;p++)
    {
        if(primes[p]==0)
        {
            for(int m=2*p;m<=N;m+=p)
            {
                primes[m]=1;
            }
        }
    }
    vector<int> ans(2,0);
//    unordered_set<int> US;
//    for(int i=2;i<N;i++)
//    {
//        if(primes[i]==0){
//            US.insert(i);
//        }
//    }
//    for(auto it:US)
//    {
//        int a = it;
//        if(US.find(A-a)!=US.end())
//        {
//            ans[0]=a;
//            ans[1]=A-a;
//            break;
//        }
//    }
    for(int i=2;i<N;i++)
    {
        if(primes[i]==0)
        {
            int a = i;
            if(primes[A-a]==0)
            {
                ans[0]=a;
                ans[1]=A-a;
                break;
            }
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Prime sum!\n";
    vector<int> ans = primesum(36);
    cout<<"sum prime : "<< " - "<<ans[0]<<":"<<ans[1]<<endl;
    return 0;
}
