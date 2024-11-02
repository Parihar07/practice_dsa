//
//  main.cpp
//  EvenSubArrays
//
//  Created by CodeBreaker on 11/08/1946 Saka.
//

#include <iostream>
#include<vector>

using namespace std;

string solve(vector<int> &A) {
    string ans="NO";
    int N=A.size();
    int s=0,e=0;
    for(int i=0;i<N;i+=2)
    {
        s=i;
        if(s+2<=N-1)
        {
            e =s+2;
            if(A[s]%2==0 && A[e]
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Even SubbArrays!\n";
    return 0;
}
