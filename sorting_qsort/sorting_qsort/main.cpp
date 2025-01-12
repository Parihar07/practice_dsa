//
//  main.cpp
//  sorting_qsort
//
//  Created by CodeBreaker on 11/01/25.
//

#include <iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int> &A) {
    size_t N = A.size();
    int p1=0,p2=N-1;
    for(int i=0;i<N;i++)
    {
        p1=i+1;p2=N-1;
        while(p1<=p2)
        {
            if(A[p1]<=A[i])
            {
                //element is in right place
                p1++;
            } else if(A[p2]>A[i])
            {
                //element is in right place
                p2--;
            } else {
                int t=A[p1];
                A[p1]=A[p2];
                A[p2]=t;
                p1++;p2--;
            }
        }
        int t = A[i];
        A[i]=A[p2];
        A[p2]=t;
    }
    return A;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Quick sort lolly!\n";
    vector<int> A{1,4,10,2,1,5};
    vector<int> ans = solve(A);
    for(auto it : ans)
    {
        cout<<it<< " ";
    }
    cout<<endl;
    return 0;
}
