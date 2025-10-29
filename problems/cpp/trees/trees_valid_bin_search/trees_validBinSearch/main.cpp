//
//  main.cpp
//  trees_validBinSearch
//
//  Created by CodeBreaker on 27/01/25.
//
/*
 Largest BST Subtree
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
You are given a Binary Tree A with N nodes.
Write a function that returns the size of the largest subtree, which is also a Binary Search Tree (BST).
If the complete Binary Tree is BST, then return the size of the whole tree.
NOTE:
The largest subtree is the subtree with the most number of nodes.


Problem Constraints
1 <= N <= 105


Input Format
First and only argument is an pointer to root of the binary tree A.


Output Format
Return an single integer denoting the size of the largest subtree which is also a BST.


Example Input
Input 1:
     10
    / \
   5  15
  / \   \
 1   8   7
Input 2:
     5
    / \
   3   8
  / \ / \
 1  4 7  9


Example Output
Output 1:
 3
Output 2:
 7


Example Explanation
Explanation 1:
 Largest BST subtree is
                            5
                           / \
                          1   8
Explanation 2:
 Given binary tree itself is BST.
 */
#include <iostream>
#include <stack>
#include "bst.h"

using namespace std;

class ValidBST{
private:
    TreeNode *root;
public:
    int isValidBST(TreeNode* A);
    void convert(TreeNode *root, vector<int> &v);
};

void ValidBST::convert(TreeNode *root, vector<int> &v)
{
    if(root==NULL) return;
    convert(root->left, v);
    v.push_back(root->val);
    convert(root->right, v);
}

int ValidBST::isValidBST(TreeNode* A) {
    if(A==NULL) return 1;
    vector<int> v;
    convert(A, v);
    size_t N = v.size();
//    for(int i=0;i<N-1;i++)
//    {
//        cout<<v[i]<<" ";
//    }
//    cout<<endl;
    for(int i=0;i<N-1;i++)
    {
        if(v[i]>v[i+1]) return 0;
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, valid BST!\n";
    
    auto bst = BST();
    bst.autoCreateBST();
    TreeNode *root = bst.getRoot();
    
    ValidBST vbst;
    cout << "if valid : "<< vbst.isValidBST(root) <<endl;
    
    return 0;
}
