//
//  main.cpp
//  trees_verticalOrderTraversal
//
//  Created by CodeBreaker on 26/01/25.
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include "treeNode.hpp"

class VLT : public bTree{ //Vertical level traversal
    treeNode *root;
    bTree bt;
    void verticalOrder(treeNode* A, vector<vector<int>> &v);
public:
    VLT(int val): bt(bTree(val)){
        bt.createDummyTree();
        this->root = bt.get_root();
    }
    vector<vector<int>> verticalOrderTraversal();
};

vector<vector<int> > VLT::verticalOrderTraversal() {
    auto ans = vector<vector<int>>();
    verticalOrder(root, ans);
    return ans;
}

void VLT::verticalOrder(treeNode *A, vector<vector<int>> &v)
{
    auto q = queue<pair<treeNode *, int>>();
    auto UM = unordered_map<int, vector<int>>();
    auto pr = make_pair(A, 0);
    
    q.push(pr);
    while(!q.empty())
    {
        auto tp = q.front();
        UM[tp.second].push_back(tp.first->val);
        if(tp.first->left!=NULL) q.push(make_pair(tp.first->left, tp.second-1));
        if(tp.first->right!=NULL) q.push(make_pair(tp.first->right, tp.second+1));
        q.pop();
    }
    int mini=INT_MAX, maxi=INT_MIN;
    for(auto p : UM)
    {
        mini=min(mini,p.first);
        maxi=max(maxi,p.first);
    }
    
    for(int i=mini;i<=maxi;i++)
    {
        v.push_back(UM[i]);
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Vertical level order traversal..!\n";
    VLT vt(1);
    auto ans = vt.verticalOrderTraversal();
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
