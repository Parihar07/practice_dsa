#ifndef H_XORTRIE_H
#define H_XORTRIE_H
//
//  xortrie.h
//  tree_maxXor
//
//  Created by CodeBreaker on 04/02/25.
//
#include<iostream>
#include<vector>

using namespace std;
struct TrieNode{
    TrieNode *bx[2];
    TrieNode(){
        bx[0]=nullptr;
        bx[1]=nullptr;
    }
};

class MaxXorTrie{
    TrieNode *root;
public:
    MaxXorTrie(){
        root = new TrieNode();
    }
    void insert(vector<int> &A);
    void search(TrieNode *root);
    int checkBit(int A, int pos){ return ((A>>pos)&1); }
    void parseTrie(TrieNode *rt, vector<int> &v);
    void parseTrie();
};


#endif //H_XORTRIE_H
