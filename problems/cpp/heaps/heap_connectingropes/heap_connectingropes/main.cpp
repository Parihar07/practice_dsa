//
//  main.cpp
//  heap_connectingropes
//
//  Created by CodeBreaker on 19/02/25.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int connectRopes(vector<int> &A)
{
    auto pq = priority_queue<int, vector<int>, greater<>>();
    
    for(auto i : A) pq.push(i);
    int ans=0;
    while(pq.size()>1)
    {
        int b = pq.top(); pq.pop();
        int a = pq.top(); pq.pop();
        ans += (a+b);
        pq.push(a+b);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Connecting ropes and get minimum cost!\n";
    vector<int> A{1,2,3,4,5};
    cout<<"Minimum cost : "<<connectRopes(A)<<endl;
    return 0;
}
