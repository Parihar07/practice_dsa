//
//  main.cpp
//  tires_maxXORsubarray
//
//  Created by CodeBreaker on 15/02/25.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int> &A) {
    vector<int> ans(2);
    for(auto i=0;i<A.size();i++){
        int tmp =A[i];
        for(auto j=i;j<A.size();j++)
        {
            if(tmp < (tmp^A[j]))
            {
                ans[0]=i+1;ans[1]=j+1;
            }
            if(i!=j) tmp = tmp^A[j];
        }
    }
    return ans;
}

vector<int> solveOpt(vector<int> &A) {
    vector<int> ans(2);
    int maxXor = 0;
    for(auto i = 0; i < A.size(); i++) {
        int tmp = A[i];
        for(auto j = i; j < A.size(); j++) {
            int currXor = (i == j) ? tmp : tmp^A[j];
            if(maxXor < currXor ||
               (maxXor == currXor && (j-i < ans[1]-ans[0] ||
                (j-i == ans[1]-ans[0] && i+1 < ans[0])))) {
                maxXor = currXor;
                ans[0] = i+1;
                ans[1] = j+1;
            }
            if(i != j) tmp = tmp^A[j];
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Max XOR sub array !\n";
    vector<int> A{1,4,3};
    auto ans = solveOpt(A);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}
