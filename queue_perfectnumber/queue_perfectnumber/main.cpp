//
//  main.cpp
//  queue_perfectnumber
//
//  Created by CodeBreaker on 20/01/25.
//

#include <iostream>
<<<<<<< HEAD

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
=======
#include <queue>
using namespace std;
class Solution
{
public:
    static string solve(int A);
};
string Solution::solve(int A) {
    queue<string> q;
    q.push("11"); q.push("22");
    string ans;
    for(int i=0;i<A;i++)
    {
        string s = q.front(); ans = s;
        int len = s.length()/2;
        string s1 = s.substr(0,len) + "11" + s.substr(len);
        string s2 = s.substr(0,len) + "22" + s.substr(len);
        q.push(s1);q.push(s2);
        q.pop();
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Perfect numbers!\n";
    cout<<"perfect number : "<<Solution::solve(4)<<endl;
//    string s = "11";
//    int len = s.length()/2;
//    string s1 = s.substr(0,len) + "11" + s.substr(len);
//    cout<<s1<<endl;
    
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
