//
//  main.cpp
//  trie_spellingchecker
//
//  Created by CodeBreaker on 31/01/25.
//

#include <iostream>
#include "trieDb.h"

TrieDb tb;

vector<int> solve(vector<string> &A, vector<string> &B) {
    auto ans = vector<int>();
    for(auto i : A)
    {
        tb.insert(i);
    }
    for(auto b:B)
    {
        ans.push_back(tb.search(b));
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, spelling checker...!\n\n";
    vector<string> A = {"hat", "cat", "rat"};
    vector<string> B = {"cat", "ball" };
    vector<int> ans = solve(A, B);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
