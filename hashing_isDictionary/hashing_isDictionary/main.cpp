//
//  main.cpp
//  hashing_isDictionary
//
//  Created by CodeBreaker on 01/12/24.
//

#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(vector<string> &A, string B) {
    size_t N = A.size();
    unordered_map<char,int> UM;//Char and its sequence;
    int t=0;
    while(B[t]!='\0')
    {
        UM[B[t]]=t;
        t++;
    }
    for(int i=0;i<N-1;i++)
    {
        if(UM[A[i][0]]>UM[A[i+1][0]])
            return 0;
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Is Dictionary!\n";
    vector<string> A{"fine", "none", "bush"};
    string B = "qwertyuiopasdfghjklzxcvbnm";
    cout<<"Is Palindrome : "<<solve(A, B)<<endl;
    return 0;
}
