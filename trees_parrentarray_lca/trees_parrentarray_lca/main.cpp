//
//  main.cpp
//  trees_parrentarray_lca
//
//  Created by CodeBreaker on 13/05/25.
//

#include <iostream>
#include <vector>
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
    root->left = nw2; root->right = nw3;
    nw2->left = nw4; nw2->right = nw5;
    nw3->left = nw6; nw3->right = nw7;
    nw4->left = nw11; nw4->right = nw14;
    nw6->left = nw8; nw6->right = nw9;
    nw11->left = nw13; nw11->right = nw12;
    nw7->right = nw10;
    return;
}

//Preorder traversal
void preOrder(TreeNode *root)
{
    if(root == NULL) return;
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}

//Getting number of nodes in tree
int getTreeCount(TreeNode  *root)
{
    if(root==NULL) return 0;
    int l = getTreeCount(root->left);
    int r = getTreeCount(root->right);
    return 1+l+r; //root+ leftnode + rightNode
}

//DFS for getting parent array
void createParentArray(vector<int> &pa, TreeNode *root, int parent)
{
    if(root==NULL) return;
    pa[root->data] = parent; //asign parent to child node
    createParentArray(pa, root->left, root->data);
    createParentArray(pa, root->right, root->data);
}

/*
 * Parameter: node is the node for which we are seeking ancestor, lvl is on which level we are looking over the given node
 */
int getParent(TreeNode *root, int node, int lvl)
{
    int treeCount = getTreeCount(root);
    vector<int> pa(treeCount+1, -1);
    
    //Create Parent array for the tree
    createParentArray(pa, root, -1);
    int anc = node;
    while(lvl>0)
    {
        anc = pa[anc];
        lvl--;
    }
    return anc;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, create parent array to find parent or ancestor!\n";
    Tree T;
    T.createRandomTree();
    TreeNode *rt = T.getRoot();
    cout<<"Number of nodes in tree : " <<getTreeCount(rt)<<endl;
    cout<<"Ancestor of node 9 at 2 lvel up is : " <<getParent(rt, 12, 4)<<endl;
     
    return 0;
}
