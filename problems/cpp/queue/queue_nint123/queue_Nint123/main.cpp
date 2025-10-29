//
//  main.cpp
//  queue_Nint123
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
#include <stack>
using namespace std;

class Solution{
public:
    static vector<int> solve(int A);
};

vector<int> Solution::solve(int A) {
    auto ans = vector<int>();
    auto q = queue<int>();
    q.push(1);q.push(2);q.push(3);
    while(A>0)
    {
        int t = q.front();
        ans.push_back(t);
        q.push((t*10)+1);
        q.push((t*10)+2);
        q.push((t*10)+3);
        q.pop();
        A-=1;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, N intergaers containg 123!\n";
    auto ans = Solution::solve(7);
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
