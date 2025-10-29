//
//  main.cpp
//  trees_binarylifting_lca
//
//  Created by CodeBreaker on 16/05/25.
//

#include <iostream>
#include <vector>
#include <queue>
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

vector<int> getDepthArray(TreeNode *root);

/*
 Steps to get LCA of given node1 and node2
 1) We need to preprocess the tree and create jump array which consists of parent of each node 2 to the ith place
 2) Using jump array, Firstly get depth or levels of two nodes
 3) if any of the nde is at deeper level bring node to same level or at equal depth
 4) keep jumping untill two nodes are not equal at last node will at pint where they are below the lca
 5) return the parent for the point node is present
 */

int getVertexCount(TreeNode *root)
{
    if(root == NULL) return 0;
    int l = getVertexCount(root->left);
    int r = getVertexCount(root->right);
    return 1+l+r;
}

void preprocessHelper(TreeNode *root, vector<vector<int>> &pa,  int logN, int par)
{
    if(root==NULL) return;
    int node = root->data;
    
    pa[node][0] = par;
    
    //Filling the jump  array of 2^i of  node
    for(int i=1; i<logN; i++)
    {
        int parent = pa[node][i-1];
        if(parent != -1)
        {
            pa[node][i] = pa[parent][i-1];
        }
    }
    
    //DFS calls
    preprocessHelper(root->left, pa, logN, node);
    preprocessHelper(root->right, pa, logN, node);
}
//Root of the tree and number of vertex in  tree
vector<vector<int>> preprocess(TreeNode *root, int n)
{
    vector<vector<int>> pa(n+1, vector<int>((log2(n)+1), -1));
    int logN = floor(log2(n))+1;
    preprocessHelper(root, pa, logN, -1);
    return pa;
}

//depth or levels of the tree

int nodeDepth(vector<int> &da, int node)
{
    return da[node];
}

vector<int> getDepthArray(TreeNode *root)
{
    if(root == NULL) return vector<int>();
    int n = getVertexCount(root);
    vector<int> da(n+1, 0);
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while(!q.empty())
    {
        auto size = q.size();
        for(auto i=0;i<size;i++)
        {
            TreeNode *t = q.front(); q.pop();
            da[t->data] = depth;
            if(t->left!=NULL) q.push(t->left);
            if(t->right!=NULL) q.push(t->right);
        }
        depth++;
    }
    return da;
}

//Getting LCA
int getLCA(vector<vector<int>> &pa, vector<int> &da, int node1, int node2)
{
    int diff=0;
    int d1 = nodeDepth(da, node1), d2 = nodeDepth(da, node2);
    if(d1>d2)
    {
        diff = d1-d2;
        for (int i = 0; i < pa[0].size(); i++) {
            if ((diff >> i) & 1) {
                node1 = pa[node1][i];
            }
        }
    } else {
        diff = d2-d1;
        for (int i = 0; i < pa[0].size(); i++) {
            if ((diff >> i) & 1) {
                node2 = pa[node2][i];
            }
        }
    }
    if(node1 == node2) return node1;
    
    int logN = pa[0].size();
    for(int i = logN-1 ;i>=0;i--)
    {
        if(pa[node1][i] != pa[node2][i])
        {
            node1 = pa[node1][i];
            node2 = pa[node2][i];
        }
    }
    return pa[node1][0];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, finding LCA using binary lifting !\n";
    Tree tree;
    tree.createRandomTree();
    TreeNode *rt = tree.getRoot();
    auto da =  getDepthArray(rt);
    int n  = getVertexCount(rt);
    auto pa = preprocess(rt, n);
    
    cout<<"LCA of node 11 and node 14 : " << getLCA(pa, da, 11, 14)<<endl;
    
    for(int i=0;i<da.size();i++)
    {
        cout<<i<<"-"<<da[i]<<" ";
    }
    cout<<endl;
    return 0;
}
