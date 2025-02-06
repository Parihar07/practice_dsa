//
//  main.cpp
//  trees_zigzagtraversal
//
//  Created by CodeBreaker on 26/01/25.
//

#include <iostream>
#include <queue>
#include "treeNode.hpp"
using namespace std;

class ZzTraversal : public bTree
{
    bTree bt;
    treeNode *root;
    void zigzag(treeNode *root, vector<vector<int>> &v);
public:
    vector<vector<int>> zigzagTaversal();
    ZzTraversal():bt(bTree(1)){
       bt.createDummyTree();
        root = bt.get_root();
    }
};

vector<vector<int>> ZzTraversal::zigzagTaversal()
{
    auto ans = vector<vector<int>>();
    zigzag(root, ans);
    return ans;
}

void ZzTraversal::zigzag(treeNode *root, vector<vector<int>> &v)
{
    auto q = queue<treeNode *>();
    q.push(root);
    int lev=0;
    while(!q.empty())
    {
        size_t N = q.size();
        auto tv = vector<int>();
        lev+=1;
        for(int i=0;i<N;i++)
        {
            auto qt = q.front();
            tv.push_back(qt->val);
            if(qt->left!=NULL) q.push(qt->left);
            if(qt->right!=NULL) q.push(qt->right);
            q.pop();
        }
        if(lev%2==0)
            reverse(tv.begin(), tv.end());
        v.push_back(tv);
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Zig Zag tree taversal!\n";
    auto bt = ZzTraversal();
    auto ans = bt.zigzagTaversal();
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
