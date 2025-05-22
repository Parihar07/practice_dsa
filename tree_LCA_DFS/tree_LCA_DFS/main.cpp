//
//  main.cpp
//  tree_LCA_DFS
//
//  Created by CodeBreaker on 03/05/25.
//

/*
 Least Common Ancestor
 Attempted
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Find the lowest common ancestor in an unordered binary tree A, given two values, B and C, in the tree.
 Lowest common ancestor: the lowest common ancestor (LCA) of two nodes and w in a tree or directed acyclic graph (DAG) is the lowest (i.e., deepest) node that has both v and w as descendants.


 Problem Constraints
 1 <= size of tree <= 100000
 1 <= B, C <= 109


 Input Format
 First argument is head of tree A.
 Second argument is integer B.
 Third argument is integer C.


 Output Format
 Return the LCA.


 Example Input
 Input 1:
  
       1
      /  \
     2    3
 B = 2
 C = 3
 Input 2:
       1
      /  \
     2    3
    / \
   4   5
 B = 4
 C = 5


 Example Output
 Output 1:
  1
 Output 2:
  2


 Example Explanation
 Explanation 1:
  LCA is 1.
 Explanation 2:
  LCA is 2.
 */

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

// LCA: LCA(Least Common Ancestor) of children is said to LCA when two children diverged from the parent and closest one is said to be LCA
TreeNode *getLCA_DFS(TreeNode *root, int B, int C)
{
    if(root==NULL) return NULL; // return NULL if nothing is found
    if(root->data == B || root->data == C) return root; //this is will return if it find any  of the node has the answer
    TreeNode *leftNode = getLCA_DFS(root->left, B, C); // search left
    TreeNode *rightNode = getLCA_DFS(root->right, B, C); //check right
    if(leftNode!=NULL && rightNode!=NULL) return root; // either of side parent falls the childs then the root is the answer
    if(leftNode==NULL) return rightNode; // if any one is not null then that is answer
    else return leftNode;
}

bool find(TreeNode *root, int v)
{
    if(root==NULL) return false;
    if(root->data==v) return true;
    bool bl = find(root->left,v);
    bool br = find(root->right,v);
    if(bl==true || br==true) return true; //if value is found in any of the side then return true
    else return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Geting LCA !\n";
    Tree tree;
    tree.createRandomTree();
    TreeNode *rt = tree.getRoot();
    TreeNode *ans=NULL;
    cout<<"find B: " <<find(rt, 3)<<endl;
    cout<<"find C: " <<find(rt, 7)<<endl;
    if(find(rt, 3)&&find(rt, 7)){
        ans = getLCA_DFS(rt, 3, 7);
    } else {
        cout<<"anyone of the node is not present\n";
    }
   
    if(ans!=NULL)  cout<<"LCA : "<<ans->data<<endl;
    else return -1;
    return 0;
}

