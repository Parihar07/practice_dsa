//
//  main.cpp
//  tree_morristraversal
//
//  Created by CodeBreaker on 30/04/25.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;
    Node():data(0),right(NULL),left(NULL){}
    Node(int v):data(v),right(NULL),left(NULL){}
};

class Tree{
private:
    Node *root;
public:
    Tree():root(NULL){}
    void createRandomTree();
    Node *getRoot(){return root;}
};
void Tree::createRandomTree() //Creating random tree naive way but felt okay
{
    root = new Node(1);
    Node *nw2 = new Node(2);
    Node *nw3 = new Node(3);
    Node *nw4 = new Node(4);
    Node *nw5 = new Node(5);
    Node *nw6 = new Node(6);
    Node *nw7 = new Node(7);
    Node *nw8 = new Node(8);
    Node *nw9 = new Node(9);
    Node *nw10 = new Node(10);
    Node *nw11 = new Node(11);
    Node *nw12 = new Node(12);
    Node *nw13 = new Node(13);
    Node *nw14 = new Node(14);
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

void morrisInorderTrav(Node *root)
{
    Node *curr = root;
    Node *tmp = NULL;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        } else {
            tmp = curr->left;
            while(tmp->right!=NULL && tmp->right!=curr)
            {
                tmp=tmp->right;
            }
            
            if(tmp->right==NULL)
            {
                tmp->right=curr;
                curr=curr->left;
            }
            
            if(tmp->right==curr)
            {
                cout<<curr->data<<" ";
                curr = curr->right;
                tmp->right=NULL;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Morris inorder traversal !\n";
    
    Tree T;
    T.createRandomTree();
    Node *rt = T.getRoot();
    morrisInorderTrav(rt);cout<<endl;
    return 0;
}
