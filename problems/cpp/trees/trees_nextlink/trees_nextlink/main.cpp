//
//  main.cpp
//  trees_nextlink
//
//  Created by CodeBreaker on 29/01/25.
//
/*
 Next Pointer Binary Tree
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a binary tree,
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 Initially, all next pointers are set to NULL.
 Assume perfect binary tree.


 Problem Constraints
 1 <= Number of nodes in binary tree <= 100000
 0 <= node values <= 10^9


 Input Format
 First and only argument is head of the binary tree A.


 Output Format
 Return the head of the binary tree after the changes are made.


 Example Input
 Input 1:
  
      1
     /  \
    2    3
 Input 2:
  
         1
        /  \
       2    5
      / \  / \
     3  4  6  7


 Example Output
 Output 1:
  
         1 -> NULL
        /  \
       2 -> 3 -> NULL
 Output 2:
  
          1 -> NULL
        /  \
       2 -> 5 -> NULL
      / \  / \
     3->4->6->7 -> NULL


 Example Explanation
 Explanation 1:
 Next pointers are set as given in the output.
 Explanation 2:
 Next pointers are set as given in the output.
 */
#include <iostream>
#include "treeNode.hpp"

void connect(TreeLinkNode* A) {
    TreeLinkNode *curr = A,*t=NULL;
    while(curr->left!=NULL)
    {
        t=curr;
        while(curr!=NULL)
        {
            curr->left->nxt = curr->right;
            if(curr->nxt!=NULL)
            {
                curr->right->nxt = curr->nxt->left;
            }
            curr=curr->nxt;
        }
        curr=t->left;
    }
}

void parseTree(TreeLinkNode *rt)
{
    TreeLinkNode *curr = rt;
    while(curr != NULL)
    {
        TreeLinkNode *tmp = curr;
        while(curr!=NULL)
        {
            cout<<curr->val<<" ";
            curr=curr->nxt;
        }
        cout<<endl;
        if(tmp->left!=NULL)
            curr=tmp->left;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, L0ooink the nodes in bst!\n";
    bTree bt;
    bt.createDummyTree();
    TreeLinkNode *root = bt.get_root();
    cout<<bt<<endl;
    connect(root);
    parseTree(root);
    return 0;
}
