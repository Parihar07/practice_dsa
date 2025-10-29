//
//  main.cpp
//  arrays_missinginteger
//
//  Created by CodeBreaker on 30/12/24.
//

#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int firstMissingPositive(vector<int> &A) { // space complexity is O(n)
    size_t N=A.size();
    unordered_set<int> US;
    for(int i=0;i<N;i++)
    {
        US.insert(A[i]);
    }
    for(int i=0;i<N;i++)
    {
        if(US.find(i+1)==US.end())
            return i+1;
    }
    return (int)N+1;
}

int firstMissingPositiveOpt(vector<int> &A) {
    size_t N = A.size();
    for(int i =0;i<N;)
    {
        if(A[i]!=i+1 && A[i]<=N)
        {
            int ind = A[i]-1;
            int temp = A[ind];
            if(A[i]==A[ind]) {
                i++;
            } else {
                A[ind] = A[i];
                A[i]=temp;
            }
         
        } else {
            i+=1;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(A[i]!=i+1) return i+1;
    }
    return (int)N+1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, First Missing integer!\n";
    vector<int> A{2,3,1,2};
    cout<<"missing integer : "<<firstMissingPositiveOpt(A)<<endl;
    return 0;
}
