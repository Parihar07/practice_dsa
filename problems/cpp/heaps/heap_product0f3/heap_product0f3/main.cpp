//
//  main.cpp
//  heap_product0f3
//
//  Created by CodeBreaker on 21/02/25.
//

#include <iostream>
#include <queue>
using namespace std;

vector<int> solve(vector<int> &A) {
    vector<int> ans(A.size());
    priority_queue<int, vector<int>, greater<>> MinPq;
    ans[0]=-1;ans[1]=-1;ans[2]=A[0]*A[1]*A[2];
    for(int i=0;i<3;i++)
    {
        MinPq.push(A[i]);
    }
    int product =ans[2];
    for(int i=3;i<A.size();i++)
    {
        int mh = MinPq.top();
        if(A[i]>mh)
        {
            product/=mh;
            product*=A[i];
            MinPq.pop(); MinPq.push(A[i]);
        }
        ans[i]=product;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Prodict of top higest 3 numbers !\n";
    vector<int> A{2,3,12,7,5,1,11,18,6};
    auto ans = solve(A);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
