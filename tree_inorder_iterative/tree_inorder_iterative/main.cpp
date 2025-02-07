//
//  main.cpp
//  tree_inorder_iterative
//
//  Created by CodeBreaker on 25/01/25.
//
<<<<<<< HEAD

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
=======
/*
 Q1. Inorder Traversal
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a binary tree, return the inorder traversal of its nodes' values.


 Problem Constraints
 1 <= number of nodes <= 105


 Input Format
 First and only argument is root node of the binary tree, A.


 Output Format
 Return an integer array denoting the inorder traversal of the given binary tree.


 Example Input
 Input 1:
    1
     \
      2
     /
    3
 Input 2:
    1
   / \
  6   2
     /
    3


 Example Output
 Output 1:
  [1, 3, 2]
 Output 2:
  [6, 1, 3, 2]


 Example Explanation
 Explanation 1:
  The Inorder Traversal of the given tree is [1, 3, 2].
 Explanation 2:
  The Inorder Traversal of the given tree is [6, 1, 3, 2].
 */
#include <iostream>
#include <stack>
#include "treeNode.hpp"

void bTree::inOrderIterative(treeNode *root, vector<int> &v)
{
    auto stk = stack<treeNode *>();
    auto curr = root;
    while(!stk.empty() || curr!=NULL)
    {
        while(curr!=NULL)
        {
            stk.push(curr);
            curr=curr->left;
        }
        curr = stk.top();
        v.push_back(curr->val);
        curr=curr->right;
        stk.pop();
    }
}

vector<int> bTree::inOrderTraversal()
{
    auto ans = vector<int>();
    inOrderIterative(root, ans);
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, In order traversal World!\n";
    bTree bt;
    bt.createDummyTree();
    auto ans = bt.inOrderTraversal();
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
