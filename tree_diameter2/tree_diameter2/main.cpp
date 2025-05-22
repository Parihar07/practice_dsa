//
//  main.cpp
//  tree_diameter2
//
//  Created by CodeBreaker on 04/05/25.
//

#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *right;
    TreeNode *left;
    TreeNode():data(0),right(NULL),left(NULL){}
    TreeNode(int v):data(v),right(NULL),left(NULL){}
};

class Tree{
private:
    TreeNode *root;
    void deleteTree(TreeNode *node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
public:
    Tree():root(NULL){}
    ~Tree() { deleteTree(root); }
    
    void createRandomTree();
    TreeNode *getRoot(){return root;}
};
void Tree::createRandomTree() //Creating random tree naive way but felt okay
{
    root = new TreeNode(1);
    TreeNode *nw2 = new TreeNode(2);
    TreeNode *nw3 = new TreeNode(3);
    TreeNode *nw4 = new TreeNode(4);
    TreeNode *nw5 = new TreeNode(5);
    TreeNode *nw6 = new TreeNode(6);
    TreeNode *nw7 = new TreeNode(7);
    TreeNode *nw8 = new TreeNode(8);
    TreeNode *nw9 = new TreeNode(9);
    TreeNode *nw10 = new TreeNode(10);
    TreeNode *nw11 = new TreeNode(11);
    TreeNode *nw12 = new TreeNode(12);
    TreeNode *nw13 = new TreeNode(13);
    TreeNode *nw14 = new TreeNode(14);
    //Node *nw15 = new Node(15);
    root->left = nw2; root->right = nw3;
    nw2->left = nw4; nw2->right = nw5;
    nw3->left = nw6; nw3->right = nw7;
    nw4->left = nw11; nw4->right = nw14;
    nw6->left = nw8; nw6->right = nw9;
    nw11->left = nw13; nw11->right = nw12;
    nw7->right = nw10;
    return;
}

int getheight(TreeNode *root)
{
    if(root==NULL) return -1;
    int lh = getheight(root->left);
    int rh = getheight(root->right);
    return 1+max(lh,rh);
}

void diameter(TreeNode *root, int &dia)
{
    if(root==NULL) return;
    int lh = getheight(root->left);
    int rh = getheight(root->right);
    
    int d = 2+ lh + rh;
    dia = max(dia,d);
    diameter(root->left, dia);
    diameter(root->right, dia);
    return;
}

//optimized version or approach

int diameterOpt(TreeNode *root, int &dia)
{
    if(root==NULL) return -1;
    int lh = diameterOpt(root->left, dia);
    int rh = diameterOpt(root->right, dia);
    int d = 2+ lh + rh;
    dia = max(dia,d);
    return 1+ max(rh,lh);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Diameter of tree!\n";
    Tree tree;
    tree.createRandomTree();
    TreeNode *rt = tree.getRoot();
    int dia=0;
    diameterOpt(rt, dia);
    cout<<"Diameter of tree : " << dia<<endl;
    return 0;
}
