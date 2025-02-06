//
//  main.cpp
//  tree_diameter
//
//  Created by CodeBreaker on 30/01/25.
//
/*
 Diameter of binary tree
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a Binary Tree A consisting of N integer nodes, you need to find the diameter of the tree.
 The diameter of a tree is the number of edges on the longest path between two nodes in the tree.


 Problem Constraints
 0 <= N <= 105


 Input Format
 First and only Argument represents the root of binary tree A.


 Output Format
 Return an single integer denoting the diameter of the tree.


 Example Input
 Input 1:
            1
          /   \
         2     3
        / \
       4   5
 Input 2:
             1
           /   \
          2     3
         / \     \
        4   5     6


 Example Output
 Output 1:
  3
 Output 2:
  4


 Example Explanation
 Explanation 1:
  Longest Path in the tree is 4 -> 2 -> 1 -> 3 and the number of edges in this path is 3 so diameter is 3.
 Explanation 2:
  Longest Path in the tree is 4 -> 2 -> 1 -> 3 -> 6 and the number of edges in this path is 4 so diameter is 4.
 */
#include <iostream>
#include "treeNode.hpp"

int diameter(TreeNode *root, int &maxPath)
{
    if(root==NULL) return 0;
    int l = diameter(root->left, maxPath);
    int r = diameter(root->right, maxPath);
    maxPath = max(l+r+1, maxPath);
    return max(l,r)+1;
}

int solve(TreeNode* A) {
    
    int maxPath=0;
    diameter(A, maxPath);
    return maxPath-1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Get diameter of tree!\n";
    auto bt = bTree();
    bt.createDummyTree();
    cout<<"diameter : "<<solve(bt.get_root())<<endl;
    cout<<bt<<endl;
    return 0;
}
