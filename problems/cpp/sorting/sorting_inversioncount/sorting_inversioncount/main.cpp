//
//  main.cpp
//  sorting_inversioncount
//
//  Created by CodeBreaker on 09/01/25.
//

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &A) { //time complexity O(N^2)
    size_t N = A.size();
    int ans=0;
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            if(A[i]>A[j])
            {
                ans++;
            }
        }
    }
    return ans;
}

void mergeCount(vector<int> &A, int &c, int s, int m, int e)
{
    size_t N = e-s+1;
    vector<int> t(N);
    int p1 = s;
    int p2 = m+1;
    int i=0;
    while(p1<=m && p2 <=e)
    {
        if(A[p1]<=A[p2])
        {
            t[i++]=A[p1++];
        } else {
            c =(c+(m-p1+1)) % 1000000007;
            t[i++] = A[p2++];
        }
    }
    while(p1<=m)
    {
        t[i++]=A[p1++];
    }
    while(p2<=e)
    {
        t[i++]=A[p2++];
    }
    i=0;
    while(s<=e)
    {
        A[s++]=t[i++];
    }
}

void inverseCount(vector<int> &A, int &c, int s, int e)
{
    if(s==e) return;
    int m = (s+e)/2;
    inverseCount(A, c,s, m);
    inverseCount(A, c,m+1, e);
    mergeCount(A, c, s, m, e);
}
int solveOpt(vector<int> &A)
{
    int c=0;
    inverseCount(A,c, 0, A.size()-1);
    return c;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Inverse count !\n";
    vector<int> A{3,4,1,2};
    cout<<"Inversion Count : " << solveOpt(A)<<endl;
    return 0;
}
