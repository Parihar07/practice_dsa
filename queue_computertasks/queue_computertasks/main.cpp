//
//  main.cpp
//  queue_computertasks
//
//  Created by CodeBreaker on 21/01/25.
//

#include <iostream>
<<<<<<< HEAD

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
=======
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    static int solve(vector<int> &A, vector<int> &B);
};

int Solution::solve(vector<int> &A, vector<int> &B) {
    int ans=0,k=0;
    auto US = unordered_set<int>();
    for(auto i: A) US.insert(i);
    
    for(auto i: B){
        if(US.find(i)==US.end()) return -1;
    }
    auto q = queue<int>();
    for(auto i : A)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        int t = q.front();
        if(t!=B[k])
        {
            q.push(t);
        } else {
            k++;
        }
        q.pop();ans+=1;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Computer tasks!\n";
    vector<int> A{2, 3, 1, 5, 4}, B{1, 3, 5, 4, 2};
    cout<<"total cycles : "<<Solution::solve(A, B)<<endl;
    
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
