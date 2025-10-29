//
//  main.cpp
//  hash_chkPalindrome
//
//  Created by CodeBreaker on 29/11/24.
//

#include <iostream>
#include<string>
using namespace std;

int solve(string A) {
    int cnt=0;
    size_t N = A.length();
    unordered_map<char,int> um; // character of string and count;
    for(int i=0;i<N;i++)
    {
        um[A[i]]+=1;
    }
    for(auto it : um)
    {
        if(it.second%2!=0)
            cnt+=1;
    }
    if(cnt==1 || cnt==0)
        return 1;
    
    return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Chceking Palindrome!\n";
    cout<<"---------------------------\n";
    string A = "abbaee";
    cout<<"Checking if palindrome : "<<solve(A)<<endl;
    return 0;
}
