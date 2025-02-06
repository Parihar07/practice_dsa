//
//  treeNode.hpp
//  tree_inorder_iterative
//
//  Created by CodeBreaker on 25/01/25.
//
using namespace std;

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int v):val(v),left(NULL),right(NULL){}
    
};

class bTree{
    treeNode *root;
    void printInorder(treeNode *root)
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
        auto nwNode0 = new treeNode(2);
        auto nwNode1 = new treeNode(3);
        auto nwNode2 = new treeNode(4);
        auto nwNode3 = new treeNode(5);
        auto nwNode4 = new treeNode(6);
        auto nwNode5 = new treeNode(7);
        auto nwNode6 = new treeNode(8);
        auto nwNode7 = new treeNode(9);
        auto nwNode8 = new treeNode(10);
        if(root == NULL){
            root = new treeNode(1);
        }
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
    auto get_root(){ return root;};
    friend ostream& operator<<(ostream &os, bTree &bt)
    {
        bt.printInorder(bt.root);
        return os;
    }
};


