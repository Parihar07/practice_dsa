#ifndef H_TRIE_DB
#define H_TRIE_DB
//
//  trieDb.h
//  trie_spellingchecker
//
//  Created by CodeBreaker on 31/01/25.
//
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Trie{
    bool isEnd;
    unordered_map<char, Trie*> um;
    Trie():isEnd(false){}
};

class TrieDb{
private:
    Trie *root;
public:
    TrieDb():root(new Trie()){}
    void insert(string str);
    bool search(string str);
    void parseDb();
    void parseUtility(Trie *root, string prefix);
    Trie *get_root(){ return root;}
};
#endif //H_TRIE_DB

