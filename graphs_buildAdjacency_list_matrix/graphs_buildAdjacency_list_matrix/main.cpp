//
//  main.cpp
//  graphs_buildAdjacency_list_matrix
//
//  Created by CodeBreaker on 18/02/25.
//

#include <iostream>
#include <vector>
using namespace std;

void createAdjacencyMatrix(int N, int E, vector<int> &U, vector<int> &V)
{
    vector<vector<int>> adjmatrix(N+1,vector<int>(N+1, 0));
    for(int i =0;i<E;i++)
    {
        adjmatrix[U[i]][V[i]] = 1;
        adjmatrix[V[i]][U[i]] = 1;
    }
    
    for(auto i:adjmatrix)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void createAdjacencyList(int N, int E, vector<int> &U, vector<int> &V)
{
    vector<int> adjList[N+1];
    for(int i=0;i<E;i++)
    {
        adjList[U[i]].push_back(V[i]);
        adjList[V[i]].push_back(U[i]);
    }
    int c=0;
    for(auto i:adjList)
    {
        cout<<c++<<"-";
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Creating adjacency list and matrix !\n";
    vector<int> U{1,2,3,4,2,3,1};
    vector<int> V{4,5,2,3,4,5,2};
    createAdjacencyList(5, 7, U, V);
    createAdjacencyMatrix(5, 7, U, V);
    return 0;
}
