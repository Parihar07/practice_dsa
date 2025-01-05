//
//  main.cpp
//  PN_DistinctPrimes
//
//  Created by CodeBreaker on 05/01/25.
//
/*
 Distinct Primes
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
You have given an array A having N integers. Let say G is the product of all elements of A.
You have to find the number of distinct prime divisors of G.

Input Format
The first argument given is an Array A, having N integers.
Output Format
Return an Integer, i.e number of distinct prime divisors of G.
Constraints
1 <= N <= 1e5
1 <= A[i] <= 1e5
For Example
Input:
    A = [1, 2, 3, 4]
Output:
     2

Explanation:
    here G = 1 * 2 * 3 * 4 = 24
    and distinct prime divisors of G are [2, 3]
 */
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int isPrime(int A)
{
    int ans=0;
    for(int i=1;i*i<=A;i++)
    {
        if(A%i==0){
            if(i*i==A)
            {
                ans+=1;
            } else {
                ans+=2;
            }
        }
    }
    return (ans==2)?1:0;
}

int cntPrimeFactors(long long A)
{
    long long N=A+1;
    long long primes[N];
    fill_n(primes, N, 1);
    primes[0]=0;
    primes[1]=0;
    for(long long i=2;i<N;i++)
    {
        if(primes[i])
        {
            for(long long j=2*i;j<N;j++)
            {
                primes[j]=0;
            }
        }
    }
    int ans=0;
    for(int i=2;i<N;i++)
    {
        ans+=primes[i];
    }
    return ans;
}



int solve(vector<int> &A) {
    long long G=1;
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        G*=A[i];
    }
    
    return cntPrimeFactors(G);
}

int solveOpt(vector<int> &A) {
    unordered_set<int> US;
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        for(int j=2;j<=A[i];j++)
        {
            if(A[i]%j==0 &&
               isPrime(j))
            {
                US.insert(j);
            }
        }
    }
    return (int)US.size();
}

int solveOpt2(vector<int> &A) //time complexity N * square root of max value in array * log M
{
    unordered_set<int> US;
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        int t = A[i];
        for(int j=2;j*j<=t;j++)
        {
            while(t % j == 0) {
                t = t/j;
                US.insert(j);
            }
            
        }
        if(t > 1) { // as for suppose 15 5 is not added because 4*4 is 16 and it wont enter the loop
            US.insert(t);
        }
    }

    return (int)US.size();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, DistinctPrimes!\n";
    vector<int> A{1,2,3,4, 30, 24};
    
    cout<<isPrime(5)<<endl;
    cout<<"Prime factors : "<<solveOpt2(A)<<endl;
    return 0;
}
