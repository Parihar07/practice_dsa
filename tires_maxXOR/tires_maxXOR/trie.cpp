//
//  trie.cpp
//  tires_maxXOR
//
//  Created by CodeBreaker on 15/02/25.
//

#include "trie_h.h"

void Trie::insert(int val)
{
    tNode *tmp = root;
    for(auto i=len;i>=0;i--)
    {
        int bit = ((val>>i)&1);
        if(tmp->b[bit] == nullptr)
        {
            auto nn = new tNode();
            tmp->b[bit]=nn;
            tmp=nn;
        } else {
            tmp=tmp->b[bit];
        }
    }
}
void Trie::make_trie(vector<int> &A)
{
    for(auto i:A)
        for(auto b=0;b<32;b++)
            if((i>>b)&1) len=max(len,b);
    
    for(auto e:A)
    {
        insert(e);
    }
}

bool Trie::search(int val)
{
    auto tmp = root;
    int ret = true;
    for(auto b=len;b>=0;b--)
    {
        int bit=(val>>b)&1;
        if(tmp->b[bit]!=nullptr)
        {
            tmp=tmp->b[bit];
        } else {
            ret=false;
            break;
        }
    }
    return ret;
}

void Trie::parseTrie()
{
    printUtility(root, "");
}

void Trie::printUtility(tNode *root, string str)
{
    if(root==nullptr) return;
    if(root->b[0]==nullptr && root->b[1]==nullptr)
    {
        cout<<str<<endl;
        return;
    }
    if(root->b[0]!=nullptr) {
        //str+="0";
        printUtility(root->b[0], str+"0");
    }
    if(root->b[1]!=nullptr) {
        //str+="1";
        printUtility(root->b[1], str+"1");
    }
    
   
}
