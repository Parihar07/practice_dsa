//
//  main.cpp
//  trees_createTreeInorderPreorder
//
//  Created by CodeBreaker on 06/05/25.
//
/*
 Binary Tree From Inorder And Postorder
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given the inorder and postorder traversal of a tree, construct the binary tree.
 NOTE: You may assume that duplicates do not exist in the tree.


 Problem Constraints
 1 <= number of nodes <= 105


 Input Format
 First argument is an integer array A denoting the inorder traversal of the tree.
 Second argument is an integer array B denoting the postorder traversal of the tree.


 Output Format
 Return the root node of the binary tree.


 Example Input
 Input 1:
  A = [2, 1, 3]
  B = [2, 3, 1]
 Input 2:
  A = [6, 1, 3, 2]
  B = [6, 3, 2, 1]


 Example Output
 Output 1:
    1
   / \
  2   3
 Output 2:
    1
   / \
  6   2
     /
    3


 Example Explanation
 Explanation 1:
  Create the binary tree and return the root node of the tree.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode():data(0),right(NULL),left(NULL){}
    TreeNode(int v):data(v),right(NULL),left(NULL){}
};

TreeNode *buildTreehelper(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> um_inorder,
                          int ps, int pe, int is, int ie)
{
    if(ps>pe || is>ie) return NULL;
    TreeNode *root = NULL;
    root = new TreeNode(preorder[ps]);
    int idx = um_inorder[preorder[ps]];
    int x = idx-is; //number od elements in LST of inorder
    
    root->left = buildTreehelper(preorder, inorder, um_inorder, ps+1, ps+x, is, idx-1);
    root->right = buildTreehelper(preorder, inorder, um_inorder, ps+x+1, pe, idx+1, ie);
    
    return root;
}

TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    
    unordered_map<int,int> um_inorder;
    for(int i=0;i<B.size();i++)
    {
        um_inorder[B[i]]=i;
    }
    return buildTreehelper(A, B, um_inorder, 0, (A.size()-1), 0, (B.size()-1));
}

void preorder(TreeNode *root)
{
    if(root==NULL) return;
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A{4,2,1,5,3,6}, B{1,2,4,3,5,6};  //A-Inorder tree B-Postorder
    TreeNode *rt = buildTree(B, A);
    preorder(rt);
    std::cout << "Hello, Creteing tree form inorder to preorder!\n";
    return 0;
}
