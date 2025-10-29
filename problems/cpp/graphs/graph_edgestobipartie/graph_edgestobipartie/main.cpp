//
//  main.cpp
//  graph_edgestobipartie
//
//  Created by CodeBreaker on 05/03/25.
//
/*
 given tree - as all trees are biparte how many, how many edges can be added to
 keep tree biparte
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int edgesForBiparte(vector<int> &U, vector<int> &V, int N, int E) {
    vector<int> G[N + 1];
    auto q = queue<int>();
    auto cv = vector<int>(N + 1, 0);
    int c1 = 0, c2 = 0;
    for (int i = 0; i < E; i++) {
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }
    q.push(1); cv[1]=1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (auto i : G[t]) {
            if (cv[i] == 0) {
                cv[i] = 3 - cv[t];
                q.push(i);
            }
        }
    }
    // count the color1 color2
    for (int i = 0; i < cv.size(); i++) {
        if (cv[i] == 1)
            c1++;
        else if (cv[i] == 2)
            c2++;
    }
    return (c1 * c2) - E;
}

int main(int argc, const char *argv[]) {
    // insert code here...
    std::cout << "Hello, biparte for tree by adding edges !\n";
    vector<int> U = {1, 1, 2, 2, 3, 4, 5, 5, 6, 6};
    vector<int> V = {2, 3, 4, 5, 6, 9, 7, 8, 10, 11};
    int N = 11; // Number of nodes
    int E = 10; // Number of edges

    int result = edgesForBiparte(U, V, N, E);
    cout << "Number of edges that can be added to keep the tree bipartite: "
         << result << endl;
    return 0;
}
