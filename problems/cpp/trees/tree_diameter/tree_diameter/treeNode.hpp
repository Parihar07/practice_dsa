//
//  TreeNode.hpp
//  tree_inorder_iterative
//
//  Created by CodeBreaker on 25/01/25.
//
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
    
};

class bTree{
    TreeNode *root;
    void printInorder(TreeNode *root)
    {
        if(root==NULL) return;
        printInorder(root->left);
        cout<<root->val<<" ";
        printInorder(root->right);
    }
public:
    //default constructor
    bTree():root(NULL){}
    void createDummyTree(){
        auto nwNode1 = new TreeNode(1);
        auto nwNode2 = new TreeNode(2);
        auto nwNode3 = new TreeNode(3);
        auto nwNode4 = new TreeNode(4);
        auto nwNode5 = new TreeNode(5);
        auto nwNode6 = new TreeNode(6);
        auto nwNode7 = new TreeNode(7);
        auto nwNode8 = new TreeNode(8);
        auto nwNode9 = new TreeNode(9);
        auto nwNode10 = new TreeNode(10);
        auto nwNode11 = new TreeNode(11);
    
        nwNode1->left = nwNode2;
        nwNode2->left = nwNode4;
        nwNode4->right = nwNode7;
        nwNode7->left = nwNode11;
        
        nwNode1->right = nwNode3;
        nwNode3->left=nwNode5;
        nwNode5->right=nwNode8;
        nwNode3->right=nwNode6;
        nwNode6->left=nwNode9;
        nwNode6->right=nwNode10;
        
        root = nwNode1;
        
    }
    auto get_root(){ return root;};
    friend ostream& operator<<(ostream &os, bTree &bt)
    {
        bt.printInorder(bt.root);
        return os;
    }
};


