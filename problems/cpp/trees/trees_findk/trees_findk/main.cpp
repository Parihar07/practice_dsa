//
//  main.cpp
//  trees_findk
//
//  Created by CodeBreaker on 28/01/25.
//

#include <iostream>
#include "treeNode.hpp"

bool findk(treeNode *root, int k)
{
    if(root==NULL) return false;
    if(root->val == k) return true;
    bool l = findk(root->left,k);
    bool r = findk(root->right, k);
    if(l||r){
        return true;
    } else
        return false;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, find path to source node!\n";
    bTree bt;
    bt.createDummyTree();
    cout<<bt<<endl;
    cout<< " Value found " << findk(bt.get_root(),12)<< endl;
    return 0;
    
}
