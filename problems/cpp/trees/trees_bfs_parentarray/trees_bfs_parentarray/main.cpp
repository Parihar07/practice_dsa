//
//  main.cpp
//  trees_bfs_parentarray
//
//  Created by CodeBreaker on 15/05/25.
//

#include <iostream>
#include<queue>
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
vector<int> creatParentArray(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int n =  getVertexCount(root);
    vector<int> pa(n+1,-1);// we need n nodes hence n+1 nad intializing all parents as -1;
    while(!q.empty())
    {
        TreeNode *t = q.front(); q.pop();
        
        if(t->left!=NULL){
            q.push(t->left);
            pa[t->left->data]=t->data; // parent of left child is the one calling the child
        }
        if(t->right!=NULL){
            q.push(t->right);
            pa[t->right->data] = t->data; // parent of left child is the one calling the child
        }
    }
    return pa;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, creating parent array with BFS traversal !\n";
    Tree tree;
    tree.createRandomTree();
    TreeNode *rt = tree.getRoot();
    vector<int> ans = creatParentArray(rt);
    
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
