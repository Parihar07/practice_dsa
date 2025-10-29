#include<iostream>
#include<vector>
using namespace std;

int validPos(const vector<vector<int>> A, int R, int C)
{
    int r=R,c=C;
    int ac = A.size();
    int ar = A[0].size();

    //check col upwards
    while(r>=0)
    {
        if(A[r][c]==1) return 0;
        --r;
    }
    r=R;c=C;

    //check righ diagnolly
    while(r>=0 && c>=0)
    {
        if(A[r][c]==1) return 0;
        --r;--c;
    }
    r=R;c=C;

    //chcek right diagnolly
    while(r>=0 && c<ac)
    {
        if(A[r][c]==1) return 0;
        --r,++c;
    }

    return 1;
}

void solve(vector<vector<int>> &A, int Nq, int r)
{
    int C = A[0].size();
    if(Nq==r)
    {
        for(auto r:A)
        {
            for(auto c:r)
            {
                cout<<c<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int c=0;c<C;c++)
    {
        if(validPos(A,r,c))
        {
            A[r][c]=1;
            solve(A,Nq,r+1);
            A[r][c]=0;
        }
    }
}

int main()
{
    cout<<"Hello backracking n queens\n";
    vector<vector<int>> A(4,vector<int>(4));
    // int c=0;
    // for(int i=0;i<A.size();i++)
    // {
    //     for(int j=0;j<A[0].size();j++)
    //     {
    //         A[i][j]=++c;
    //     }
    // }
    // for(auto r:A)
    // {
    //     for(auto c:r)
    //     {
    //         cout<<c<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<endl;
    return 0;
}