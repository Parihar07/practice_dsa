//
//  main.cpp
//  trees_countNodes
//
//  Created by CodeBreaker on 27/01/25.
//

#include <iostream>
#include "bst.h"

int countNode(TreeNode *root)
{
    if(root==NULL) return 0;
    int L = countNode(root->left);
    int R = countNode(root->right);
    return 1+L+R;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, couting node in tree!\n";
    auto bst = new BST();
    //bst->autoCreateBST();
    cout<<"totoal Node : " << countNode(bst->getRoot())<<endl;
    vector<int> A{3,5,1,15,7,11,85,34,82,26,14,28,10,19,17};
    bst->createBST(A);
    cout<<"totoal Node : " << countNode(bst->getRoot())<<endl;
    return 0;
}
