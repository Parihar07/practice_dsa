//
//  main.cpp
//  sorting_arithmaticProgression
//
//  Created by CodeBreaker on 25/11/24.
//

#include <iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A) {
    size_t N = A.size();
    sort(A.begin(),A.end(),greater<>());
    int diff=A[0]-A[1];
    for(int i=0;i<N-1;i++)
    {
        if((A[i]-A[i+1])!=diff) return 0;
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    // insert code here...

    std::cout << "Hello, Checking arthimeatic progression..!\n";
    cout<<"----------------------\n";
    vector<int> A={1,3,7};
    cout<<"Chceking Arthimatic : "<<solve(A)<<endl;
    return 0;
}
