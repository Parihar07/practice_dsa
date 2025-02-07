//
//  main.cpp
//  tree_rightview
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
 Right View of Binary tree
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a binary tree of integers denoted by root A. Return an array of integers representing the right view of the Binary tree.
 Right view of a Binary Tree is a set of nodes visible when the tree is visited from Right side.


 Problem Constraints
 1 <= Number of nodes in binary tree <= 100000
 0 <= node values <= 10^9


 Input Format
 First and only argument is head of the binary tree A.


 Output Format
 Return an array, representing the right view of the binary tree.


 Example Input
 Input 1:
  
             1
           /   \
          2    3
         / \  / \
        4   5 6  7
       /
      8
 Input 2:
  
             1
            /  \
           2    3
            \
             4
              \
               5


 Example Output
 Output 1:
  [1, 3, 7, 8]
 Output 2:
  [1, 3, 4, 5]


 Example Explanation
 Explanation 1:
 Right view is described.
 Explanation 2:
 Right view is described.
 */
#include <iostream>
#include <vector>
using namespace std;
struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int v):val(v),left(NULL),right(NULL){}
};

class bTree{
    treeNode *root;
    void rightView(treeNode *root, vector<int> &v);
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
    auto ans = vector<int>();
    rightView(root, ans);
    return ans;
}

void bTree::rightView(treeNode *root, vector<int> &v)
{
    if(root==NULL) return;
    auto q = queue<treeNode *>();
    q.push(root);
    while(!q.empty())
    {
        size_t N=q.size();
        for(int i=0;i<N;i++)
        {
            treeNode *t = q.front();
            if(i==N-1) v.push_back(t->val);
            if(t->left!=NULL) q.push(t->left);
            if(t->right!=NULL) q.push(t->right);
            q.pop();
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, right view treee!\n";
    bTree bt;
    bt.createDummyTree();
    auto ans = bt.solve();
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
