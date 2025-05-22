//
//  main.cpp
//  trees_createtreeInorderPostorder
//
//  Created by CodeBreaker on 12/05/25.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode():data(0),right(NULL),left(NULL){}
    TreeNode(int v):data(v),right(NULL),left(NULL){}
};

TreeNode *treeCreateHelper(vector<int> &postorder, vector<int> &inorder, unordered_map<int, int> um_inorder,
                           int ps, int pe, int is, int ie)
{
    if(ps>pe || is>ie) return NULL;
    TreeNode *root = new TreeNode(postorder[pe]);
    
    int i = um_inorder[postorder[pe]]; //seraching index of root in inorder array so left of it is leftmost tree and right is right most tree
    int leftcount = 	i-is;  // number of elements in left most tree and getting its index
    
    root->left = treeCreateHelper(postorder, inorder, um_inorder, ps, ps+leftcount-1, is, i-1);
    root->right = treeCreateHelper(postorder, inorder, um_inorder, ps+leftcount, pe-1, i+1, ie);
    return root;
}

TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> um_inorder;
    for(int i =0; i<A.size(); i++)
    {
        um_inorder[A[i]]=i;//building map using inorder array
    }
    return treeCreateHelper(B, A, um_inorder, 0, B.size()-1, 0, A.size()-1);
}

void inOrder(TreeNode *root)
{
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, creating tree from inorder and postorder !\n";
    vector<int> A{1}, B{1};
    TreeNode *rt  = buildTree(A, B);
    inOrder(rt);
    cout<<endl;
    return 0;
}
