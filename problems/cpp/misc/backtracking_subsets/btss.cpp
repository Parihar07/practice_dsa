#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &aA, int k, int i, int sum)
{
 if(i==aA.size()) 
 {
    if(k==sum) return 1;
    else return 0;
 }
 
 sum += aA[i];
 int c1 = solve(aA,k,i+1,sum);
 sum -= aA[i];
 int c2 = solve(aA,k,i+1,sum);
 return c1+c2;
}

int main()
{
    cout<<"Hello backtracking subsets\n";
    vector<int> V{5,7,2};
    cout<<"count of subset with 7 : "<<solve(V,7,0,0)<<endl;
    return 0;
}