//
//  main.cpp
//  hash_firstRepeating
//
//  Created by CodeBreaker on 29/11/24.
//

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int solve(vector<int> &A) {
    size_t N = A.size();
    unordered_map<int, int> um;
    
    for(int i=0;i<N;i++)
    {
        um[A[i]]+=1;
    }
    for(int i=0;i<N;i++)
    {
        if(um.find(A[i]) != um.end() && (um[A[i]]>1) )
        {
            return A[i];
        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, hash first repeated eleemtn!\n";
    cout<<"------------------------\n";
    vector<int> ans{10, 5, 3, 4, 6};
    cout<<"repeated first element : "<< solve(ans)<<endl;
    return 0;
}
