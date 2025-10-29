
#ifndef _H_TRIE_H_
#define _H_TRIE_H_
//
//  trie.h
//  tires_maxXOR
//
//  Created by CodeBreaker on 15/02/25.
//
#include<iostream>
#include<vector>
using namespace std;

struct tNode
{
    tNode *b[2];
    tNode(){
        b[0]=nullptr;
        b[1]=nullptr;
    }
};

class Trie {
    tNode *root;
    int len;
    void printUtility(tNode *root, string str);
public:
    Trie(){
        root = new tNode();
        len=0;
    }
    Trie(int msb){
        root = new tNode();
        len=msb;
    }
    void insert(int val);
    bool search(int val);
    void make_trie(vector<int> &A);
    void parseTrie();
    tNode *getRoot(){return root;};
};

#endif //_H_TRIE_H_
