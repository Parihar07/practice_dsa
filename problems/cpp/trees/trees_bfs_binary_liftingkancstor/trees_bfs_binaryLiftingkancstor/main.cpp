//
//  main.cpp
//  trees_bfs_binaryLiftingkancstor
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

int getVertexCount(TreeNode *root)
{
    if(root == NULL) return 0;
    int l = getVertexCount(root->left);
    int r = getVertexCount(root->right);
    return 1+l+r; //root + left + right
}

int getDepth(TreeNode *root)
{
    if(root == NULL) return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);
    return 1 + max(l,r);
}

vector<vector<int>>preprocess(TreeNode *root, int n)
{
    queue<TreeNode *> q; q.push(root);
    //int n = getVertexCount(root); //assuming all the nodes sequential and not having arbitrary values
    int MAX_LOG = ceil(log2(n)) + 1;
    vector<vector<int>> pa(n+1, vector<int>(MAX_LOG, -1));
    
    
    while(!q.empty())
    {
        TreeNode *tmpNode = q.front(); q.pop();
        
        if(tmpNode->left != NULL) {
            q.push(tmpNode->left);
            pa[tmpNode->left->data][0] = tmpNode->data;
        }
        if(tmpNode->right != NULL) {
            q.push(tmpNode->right);
            pa[tmpNode->right->data][0] = tmpNode->data;
        }
        
        for(int i=1;i<MAX_LOG;i++)
        {
            int parent = pa[tmpNode->data][i-1];
            if(parent != -1)
            {
                pa[tmpNode->data][i] = pa[parent][i-1];
            }
        }
    }
    
    return pa;
}

int getAncestor(vector<vector<int>> &pa, int node, int k)
{
    int MAX_LOG = pa[0].size();
    int ans = node;
    for(int i =0; i<MAX_LOG;i++)
    {
        if((k>>i)&1)
        {
            ans = pa[ans][i];
            if(ans==-1) return -1;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Creating parent array in the form of Binary lifting to achieve traversal in Log N!\n";
    Tree tree;
        tree.createRandomTree();
        TreeNode *rt = tree.getRoot();

        int n = getVertexCount(rt);
        auto pa = preprocess(rt, n);

        int node = 12, k = 5;
        int ancestor = getAncestor(pa, node, k);
        if (ancestor != -1)
            cout << "Ancestor of node " << node << " at " << k << " is " << ancestor << endl;
        else
            cout << "Ancestor not found or invalid input.\n";

        return 0;
}
