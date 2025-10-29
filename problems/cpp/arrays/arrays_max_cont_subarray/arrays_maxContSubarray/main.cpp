//
//  main.cpp
//  arrays_maxContSubarray
//
//  Created by CodeBreaker on 19/12/24.
//

#include <iostream>
#include<vector>
using namespace std;

int maxSubArray(const vector<int> &A) {
    int maxi = A[0];
    size_t N = A.size();
    int carry=0;
    for(int i =0;i<N;i++)
    {
        carry+=A[i];
        maxi=max(maxi,carry);
        if(carry<0) carry=0;
    }
    return maxi;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Max Continuos subarray!\n";
    vector<int> A{1, 2, 3, 4, -10};
    cout<<"max continous subarray : "<<maxSubArray(A)<<endl;
    return 0;
}
