//
//  bst.h
//  trees_validBinSearch
//
//  Created by CodeBreaker on 27/01/25.
//
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

class BST{
private:
    TreeNode *root;
    vector<int> v;
    void convert(TreeNode *root)
    {
        if(root==NULL) return;
        convert(root->left);
        v.push_back(root->val);
        convert(root->right);
    }
public:
    BST():root(NULL){}
    void autoCreateBST()
    {
        if(root==NULL) root=new TreeNode(15);
        TreeNode *node13 = new TreeNode(13);
        TreeNode *node18 = new TreeNode(18);
        TreeNode *node10 = new TreeNode(10);
        TreeNode *node14 = new TreeNode(14);
        TreeNode *node17 = new TreeNode(17);
        TreeNode *node19 = new TreeNode(19);
        TreeNode *node5 = new TreeNode(5);
        TreeNode *node11 = new TreeNode(11);
        TreeNode *node16 = new TreeNode(16);
        TreeNode *node20 = new TreeNode(20);
        
        root->left = node13;
        root->right = node18;
        
        node13->left = node10;
        node13->right = node14;
        
        node18->left = node17;
        node18->right = node19;
        
        node10->left = node5;
        node10->right = node11;
        
        node17->left = node16;
                
        node19->right = node20;
    }
    void createBST(vector<int> &v)
    {
        size_t N = v.size();
        for(int i=0;i<N;i++)
        {
            TreeNode *nn = new TreeNode(v[i]);
            if(root==NULL)
            {
                root = nn; continue;
            }
            TreeNode *prev = NULL, *tmp = root;
            while(tmp!=NULL)
            {
                prev=tmp;
                if(tmp->val < v[i])
                {
                    tmp=tmp->right;
                } else {
                    tmp=tmp->left;
                }
            }
            if(prev->val < v[i])
            {
                prev->right = nn;
            } else {
                prev->left = nn;
            }
        }
    }
    TreeNode *getRoot(){ return root;}
    
    friend ostream& operator<<(ostream &os, BST &bst)
    {
        bst.convert(bst.root);
        for(auto i:bst.v)
        {
            os<<i<<" ";
        }
        return os;
    }
};
