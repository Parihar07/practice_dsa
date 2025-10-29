//
//  main.cpp
//  trees_binarylifting_ancestork
//
//  Created by CodeBreaker on 15/05/25.
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
    cout<<root->data<< " ";
    preOrder(root->left);
    preOrder(root->right);
}

//getting depth or number of levels of tree
int getDepth(TreeNode *root)
{
    if(root == NULL) return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);
    return 1 + max(l,r);
}
//get count of trees in tree
int getVertexCount(TreeNode *root)
{
    if(root == NULL) return 0;
    int l = getVertexCount(root->left);
    int r = getVertexCount(root->right);
    return 1+l+r;
}
// Preprocessing for binary lifting that is creating 2D jump array
// par is parent, dep is depth of tree or total levels and n is number of nodes of the tree
void preprocessJumpArray(TreeNode *root, vector<vector<int>> &pa, int par, int dep)
{
    if(root == NULL) return;
    
    pa[root->data][0]=par;
    
    for(int i=1; i<dep; i++)
    {
        int parent = pa[root->data][i-1];
        if(parent != -1){
            pa[root->data][i] = pa[parent][i-1];
        } else {
            pa[root->data][i]=-1;
        }
    }
    
    preprocessJumpArray(root->left, pa, root->data, dep);
    preprocessJumpArray(root->right, pa, root->data, dep);
}
//Node for which we need ancestor k and dep is number levels or depth of the tree
int getAncestor(TreeNode *root, int node, int k)
{
    int nodeCount = getVertexCount(root);
    int MAX_LOG = ceil(log2(nodeCount));  // Instead of dep
    vector<vector<int>> pa(nodeCount+1, vector<int>(MAX_LOG, -1));
    preprocessJumpArray(root, pa, -1, MAX_LOG);
    int ans = node;
    for(int i=0;i<MAX_LOG;i++)
    {
        if((k>>i)&1)
        {
            ans = pa[ans][i];
        }
        if(ans == -1) return -1;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Getting ancestor using binary lifting technique !\n";
    Tree tree;
    tree.createRandomTree();
    TreeNode *rt = tree.getRoot();
    cout<< "Preorder : "; preOrder(rt); cout<<endl;
    
    /********************************************************************/
    
    cout<<"Ancestor of node 14 at 2 is "<< getAncestor(rt, 12, 0)<<endl;
       
    return 0;
}
