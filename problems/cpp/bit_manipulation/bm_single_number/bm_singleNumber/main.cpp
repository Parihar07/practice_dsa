//
//  main.cpp
//  bm_singleNumber
//
//  Created by CodeBreaker on 23/08/1946 Saka.
//

#include <iostream>
using namespace std;

int singleNumber(const vector<int> &A) {
    int ans=0;
    size_t N=A.size();
    for(int i=0;i<N;i++)
    {
        ans^=A[i];
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Bit amnipulation finding single number!\n";
    vector<int> A{1,2,3,4,5,1,2,3,4};
    cout<<"Single Number : "<<singleNumber(A)<<endl;
    return 0;
}
