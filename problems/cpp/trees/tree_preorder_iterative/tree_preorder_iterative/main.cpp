//
//  main.cpp
//  tree_preorder_iterative
//
//  Created by CodeBreaker on 25/01/25.
//
<<<<<<< HEAD

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
=======
/*
 Preorder Traversal
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a binary tree, return the preorder traversal of its nodes values.


 Problem Constraints
 1 <= number of nodes <= 105


 Input Format
 First and only argument is root node of the binary tree, A.


 Output Format
 Return an integer array denoting the preorder traversal of the given binary tree.


 Example Input
 Input 1:
    1
     \
      2
     /
    3
 Input 2:
    1
   / \
  6   2
     /
    3


 Example Output
 Output 1:
  [1, 2, 3]
 Output 2:
  [1, 6, 2, 3]


 Example Explanation
 Explanation 1:
  The Preoder Traversal of the given tree is [1, 2, 3].
 Explanation 2:
  The Preoder Traversal of the given tree is [1, 6, 2, 3].
 */
#include <iostream>
#include <stack>
using namespace std;

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int v):val(v),left(NULL),right(NULL){}
};

class bTree{
    treeNode *root;
    void preorderIterative(treeNode *root, vector<int> &v);
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
    vector<int> preorderTraversal();
};

vector<int> bTree::preorderTraversal()
{
    auto ans = vector<int>();
    preorderIterative(root, ans);
    return ans;
}

void bTree::preorderIterative(treeNode *root, vector<int> &v)
{
    if(root==NULL) return;
    auto stk = stack<treeNode *>();
    stk.push(root);
    while(!stk.empty())
    {
        auto t = stk.top();
        stk.pop();
        v.push_back(t->val);
        if(t->right!=NULL) stk.push(t->right);
        if(t->left!=NULL) stk.push(t->left);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, tree order iteratively!\n";
    bTree bt;
    bt.createDummyTree();
    auto ans = bt.preorderTraversal();
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
