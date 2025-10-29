//
//  main.cpp
//  sorting_elementremoval
//
//  Created by CodeBreaker on 29/11/24.
//

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &A) {
    size_t N = A.size();
    int sum=0;
    int ans=0;
    sort(A.begin(), A.end(), greater<>());
    
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
    }
    for(int i=0;i<N;i++)
    {
        ans+=sum;
        sum-=A[i];
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<"---------------------\n";
    vector<int> A={3,2,4,1};
    cout<<"Eelemt removal minimum cost : "<<solve(A)<<endl;
    return 0;
}
