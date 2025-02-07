//
//  main.cpp
//  tree_levelorder
//
//  Created by CodeBreaker on 23/01/25.
//

#include <iostream>
<<<<<<< HEAD

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
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
    void levelOrder(treeNode *root);
    void levelOrderRecord(treeNode *root, vector<vector<int>> &v);
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
    void levelOrderTraversal(){levelOrder(root);};
    vector<vector<int>> levelOrderRec();
    
};

vector<vector<int>> bTree::levelOrderRec()
{
    vector<vector<int>> ans;
    levelOrderRecord(root, ans);
    return ans;
}
void bTree::levelOrderRecord(treeNode *root, vector<vector<int>> &v)
{
    auto q = queue<treeNode *>();
    q.push(root);
    while(!q.empty())
    {
        size_t N = q.size();
        vector<int> vt;
        for(int i=0;i<N;i++)
        {
            treeNode *t = q.front();
            vt.push_back(t->val);
            if(t->left!=NULL) q.push(t->left);
            if(t->right!=NULL) q.push(t->right);
            q.pop();
        }
        v.push_back(vt);
    }
}
void bTree::levelOrder(treeNode *root)
{
    
    auto q = queue<treeNode *>();
    if(root!=NULL) q.push(root);
    else return;
    while(!q.empty())
    {
        treeNode *t = q.front();
        cout<<t->val<<" ";
        if(t->left!=NULL) q.push(t->left);
        if(t->right!=NULL) q.push(t->right);
        q.pop();
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...

    std::cout << "Hello, Level order!\n";
    auto bt = new bTree();
    bt->createDummyTree();
    bt->levelOrderTraversal();
    cout<<endl;
    auto ans = bt->levelOrderRec();
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
