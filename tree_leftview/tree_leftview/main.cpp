//
//  main.cpp
//  tree_leftview
//
//  Created by CodeBreaker on 24/01/25.
//

#include <iostream>
<<<<<<< HEAD

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
=======
#include <vector>
#include <queue>
using namespace std;

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int v):val(v),left(NULL),right(NULL){}
};

class bTree{
    treeNode *root;
    void leftView(treeNode *root, vector<int> &v);
public:
    bTree(){
        root = new treeNode(1);
    }
    void createDummyTree(){
        auto nwNode0 = new treeNode(2);
        auto nwNode1 = new treeNode(3);
        auto nwNode2 = new treeNode(4);
        auto nwNode3 = new treeNode(5);
        auto nwNode4 = new treeNode(6);
        auto nwNode5 = new treeNode(7);
        auto nwNode6 = new treeNode(8);
        auto nwNode7 = new treeNode(9);
        auto nwNode8 = new treeNode(10);
        
        root->left = nwNode0;
        root->right = nwNode1;
        
        nwNode0->left = nwNode2;
        nwNode0->right = nwNode3;
        nwNode1->left = nwNode4;
        nwNode1->right = nwNode5;
        
        nwNode2->left = nwNode6;
        nwNode2->right = nwNode7;
        
        nwNode3->left = nwNode8;
    }
    vector<int> solve();
};

vector<int> bTree::solve()
{
    vector<int> ans;
    leftView(root, ans);
    return ans;
}

void bTree::leftView(treeNode *root, vector<int> &v)
{
    if(root == NULL) return;
    auto q = queue<treeNode *>();
    q.push(root);
    while(!q.empty())
    {
        size_t N = q.size();
        for(int i=0;i<N;i++)
        {
            treeNode *t = q.front();
            if(i==0) v.push_back(t->val);
            if(t->left!=NULL) q.push(t->left);
            if(t->right!=NULL) q.push(t->right);
            q.pop();
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, tree left view!\n";
    bTree bt;
    bt.createDummyTree();
    
    auto ans = bt.solve();
    for(auto i:ans)
    {
        cout<<i<<" ";
    }

                return 0;
>>>>>>> d61fd74 (treetraversals)
}
