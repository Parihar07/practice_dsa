//
//  main.cpp
//  sorting_colorSort
//
//  Created by CodeBreaker on 24/11/24.
//

#include <iostream>
#include<vector>
using namespace std;
vector<int> sortColors(vector<int> &A) {
    size_t N=A.size();
    if(N<=1) return A;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int t = A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
    }
    
    return A;
}
/*optimize using the Dutch National Flag algorithm, which is perfect for this problem.*/

vector<int> sortColorsOpt(vector<int> &A) {
    int L=0,M=0,H=A.size()-1;
    if(H==0) return vector<int>(1,0);
    while (M<=H) {
        if(A[M]==0){
            int t = A[M];
            A[M]=A[L];
            A[L]=t;
            M++;L++;
        }
        if(A[M]==1)
        {
            M++;
        }
        if(A[M]==2)
        {
            int t = A[M];
            A[M]=A[H];
            A[H]=t;
            H--;
        }
    }
    return A;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Color Soritng !\n";
    cout<<"---------------\n";
    vector<int> A = {1,0,0,1,1,0,0,2,1,2,1,1,1,0,1,1,1,1,1,1,2,1,1,1,0,0,2,0,2,2,2,0,0,1,1,1,2,2,0,2,2,2,2,2,1,1,2,2,2,1,2,1,1,0,0,1,2,1,1,0,1,0,2,0,2,1,0,1,1,0,0,1,2,0,1,0,2,1,0,1,0,1,0,1,2,2,2,0,1,1,0,2,2,2,0,0,0,0,1,1,2,1,0,1,0,1,2,2,1,0,2,0,0,1,2,1,0,2,1,0,2,0,2,1,1,1,1,1,0,1,2,0,0,1,0,1,2,0,1,1,2,1,0,2,0,0,0,2,0,1,0,2,1,1,0,1,2,1,0,0};
    vector<int> ans = sortColorsOpt(A);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<< " ";
    }
    cout<<"\n";
    return 0;
}
