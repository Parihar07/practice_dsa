//
//  main.cpp
//  sorting_factorsSort
//
//  Created by CodeBreaker on 25/11/24.
//

#include <iostream>
#include<vector>
using namespace std;
int facto(int x)
{
    int ans=0;
    for(int i=1;i*i<=x;i++)
    {
        if((x%i)==0)
        {
            if(x/i==i)
            {
                ans+=1;
            } else {
                ans+=2;
            }
        }
    }
    return ans;
}
int comp_factor(int a, int b)
{
    return facto(a)>facto(b);
}
vector<int> solve(vector<int> &A) {
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            if(comp_factor(A[j],A[j+1]))
            {
                int t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
    }
    return A;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Factors Sort!\n";
    cout<<"---------------------\n";
    cout<<"Facto : "<<facto(24)<<endl;
    return 0;
}
