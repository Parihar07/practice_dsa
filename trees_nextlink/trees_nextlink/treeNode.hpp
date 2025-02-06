//
//  TreeLinkNode.hpp
//  tree_inorder_iterative
//
//  Created by CodeBreaker on 25/01/25.
//
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *nxt;
    TreeLinkNode(int v):val(v),left(NULL),right(NULL),nxt(NULL){}
    
};

class bTree{
    TreeLinkNode *root;
    void printInorder(TreeLinkNode *root)
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
        auto nwNode2 = new TreeLinkNode(2);
        auto nwNode3 = new TreeLinkNode(3);
        auto nwNode4 = new TreeLinkNode(4);
        auto nwNode5 = new TreeLinkNode(5);
        auto nwNode6 = new TreeLinkNode(6);
        auto nwNode7 = new TreeLinkNode(7);
        auto nwNode8 = new TreeLinkNode(8);
        auto nwNode9 = new TreeLinkNode(9);
        auto nwNode10 = new TreeLinkNode(10);
        auto nwNode11 = new TreeLinkNode(11);
        auto nwNode12 = new TreeLinkNode(12);
        auto nwNode13 = new TreeLinkNode(13);
        auto nwNode14 = new TreeLinkNode(14);
        auto nwNode15 = new TreeLinkNode(15);
        
        if(root == NULL){
            root = new TreeLinkNode(1);
        }
        root->left = nwNode2;
        root->right = nwNode3;
        
        nwNode2->left = nwNode4;
        nwNode2->right = nwNode5;
        nwNode3->left = nwNode6;
        nwNode3->right = nwNode7;
        
        nwNode4->left = nwNode8;
        nwNode4->right = nwNode9;
        nwNode5->left = nwNode10;
        nwNode5->right = nwNode11;
        
        nwNode6->left = nwNode12;
        nwNode6->right = nwNode13;
        nwNode7->left = nwNode14;
        nwNode7->right = nwNode15;
    }
    auto get_root(){ return root;};
    friend ostream& operator<<(ostream &os, bTree &bt)
    {
        bt.printInorder(bt.root);
        return os;
    }
};


