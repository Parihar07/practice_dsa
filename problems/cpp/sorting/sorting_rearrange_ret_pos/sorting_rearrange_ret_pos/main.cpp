//
//  main.cpp
//  sorting_rearrange_ret_pos
//
//  Created by CodeBreaker on 12/01/25.
//

#include <iostream>
#include<vector>
using namespace std;

int rearrange(vector<int> &A, int s, int e)
{
    size_t N = A.size();
    int p1=s+1,p2=e;
    while(p1<=p2)
    {
        if(A[p1]<A[s])
        {
            p1+=1;
        } else if(A[p2]>A[s])
        {
            p2-=1;
        } else {
            int t = A[p1];
            A[p1]=A[p2];
            A[p2]=t;
            p1++;p2--;
        }
    }
    int t = A[s];
    A[s]=A[p2];
    A[p2]=t;
    return p2;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Rearrange and return pos!\n";
    vector<int> A{4,6,8,18,1,14,17,11,20,10,33,29};
    cout<<"Position : "<<rearrange(A, 3, 10)<<endl;
    for(auto it:A)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}
