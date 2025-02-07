//
//  main.cpp
//  trees_design
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
using namespace std;

struct treeNode{
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int v):val(v),left(NULL),right(NULL){ }
};

class BTree{
    treeNode *root;
public:
    BTree(){
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
    void preOrder(){preOrderTraversal(root);}
    void inOrder(){inOrderTraversal(root);}
    void postOrder(){postOrderTraversal(root);}
    
    void inOrderTraversal(treeNode *root);
    void preOrderTraversal(treeNode *root);
    void postOrderTraversal(treeNode *root);
};

void BTree::preOrderTraversal(treeNode *root)
{
    if(root==NULL) return;
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void BTree::inOrderTraversal(treeNode *root)
{
    if(root==NULL) return;
    
    inOrderTraversal(root->left);
    cout<<root->val<<" ";
    inOrderTraversal(root->right);
}

void BTree::postOrderTraversal(treeNode *root)
{
    if(root==NULL) return;
        
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->val<<" ";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, tree world !\n";
    BTree tree;
    tree.createDummyTree();
    tree.preOrder();
    cout<<endl;
    tree.postOrder();
    cout<<endl;
    tree.inOrder();
    cout<<endl;
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
