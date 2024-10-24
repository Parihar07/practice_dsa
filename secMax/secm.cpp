#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int secMax(vector<int> &v)
{
    int N=v.size();
    int maxi=INT_MIN;
    int secmaxi=INT_MIN;
    for(int i=0;i<N;i++)
    {
        maxi=max(maxi,v[i]);
    }
    for(int i=0;i<N;i++)
    {
        if(v[i]<maxi && v[i]>secmaxi)
        {
            secmaxi=max(secmaxi,v[i]);
        }
    }
    return secmaxi;
}

int main()
{
    vector<int> v{9,8,7,6,5,4};
    cout<<secMax(v)<<endl;
    return 0;
}