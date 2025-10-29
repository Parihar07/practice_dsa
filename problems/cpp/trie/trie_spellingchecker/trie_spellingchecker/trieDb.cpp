//
//  trieDb.cpp
//  trie_spellingchecker
//
//  Created by CodeBreaker on 31/01/25.
//

#include "trieDb.h"

void TrieDb::insert(string str)
{
    auto tmp = root;
    auto ind = 0;
    auto len = str.length();
    while (ind<len) {
        if(tmp->um.find(str[ind]) == tmp->um.end())
        {
            auto nn = new Trie();
            tmp->um[str[ind]] = nn;
            tmp = nn;
        } else {
            tmp = tmp->um[str[ind]];
        }
        ind++;
    }
    tmp->isEnd=true;
}

bool TrieDb::search(string str)
{
    auto tmp = root;
    auto i=0;
    auto len = str.length();
    while(i<len) {
        if(tmp->um.find(str[i]) == tmp->um.end())
        {
            return false;
        } else {
            tmp = tmp->um[str[i]];
        }
        i++;
    }
    return tmp->isEnd;
}


//void TrieDb::parseUtility(Trie *root)
//{
//    auto t = root->um;
//    if(t.size()==0) return;
//    for(auto it : t)
//    {
//        cout<<it.first;
//        parseUtility(it.second);
//    }
//}

void TrieDb::parseUtility(Trie* node, string prefix) {
    if (node->isEnd) {
        cout << prefix << endl;
    }
    for (auto it : node->um) {
        parseUtility(it.second, prefix + it.first);
    }
}

void TrieDb::parseDb() {
    parseUtility(root, "");
}
