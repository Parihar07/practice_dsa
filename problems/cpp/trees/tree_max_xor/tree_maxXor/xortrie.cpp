//
//  xortrie.cpp
//  tree_maxXor
//
//  Created by CodeBreaker on 04/02/25.
//

#include "xortrie.h"

void MaxXorTrie::insert(vector<int> &A) {
    int maxi = 0;
    for (auto i : A)
        maxi = max(i, maxi);

    int msbl = 0;
    for (int i = 0; i < 32; i++)
        if (checkBit(maxi, i))
            msbl = i;

    for (auto a : A) {
        auto tmp = root;
        for (int i = msbl; i >= 0; i--) {
            int val = checkBit(a, i);
            if (tmp->bx[val] != NULL) {
                tmp = tmp->bx[val];
            } else {
                auto nn = new TrieNode();
                tmp->bx[val] = nn;
                tmp = nn;
            }
        }
    }
}

void MaxXorTrie::parseTrie(TrieNode *rt, vector<int> &v) {
    if (rt == NULL) {
        cout << endl;
        return;
    }
    if (rt->bx[0] != NULL) {
        cout << 0 << " ";
    }

    if (rt->bx[1] != NULL) {
        cout << 1 << " ";
    }
    parseTrie(rt->bx[0], v);
    parseTrie(rt->bx[1], v);
}

void MaxXorTrie::parseTrie() {
    vector<int> v;
    parseTrie(root, v);
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void MaxXorTrie::search(TrieNode *root) { ; }
