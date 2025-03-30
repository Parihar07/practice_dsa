//
//  main.cpp
//  graph_kruskal
//
//  Created by CodeBreaker on 20/03/25.
//

/*
 Minimum spanning tree - > based out of krushkals algorithm
 You need create the tree out graph with minimum sum of wiehgts
 */

#include <iostream>
#include <vector>
using namespace std;

int findComponent(int n, vector<int> &c){
    if(c[n]==n) return n;
    c[n]=findComponent(c[n], c);
    return c[n];
}

int krushkal(vector<int> &U, vector<int> &V, vector<int> &W, int N)
{
    int ans =0;
    auto E = U.size(); // Edges of graph
    // creating edge array and will sort based on weights
    
    auto LE = vector<pair<int, pair<int, int>>>(E);
    for(int i=0;i<E;i++)
    {
        LE[i] = make_pair(W[i], make_pair(U[i], V[i]));
    }
    
    sort(LE.begin(), LE.end()); // sorting the edges based on weights
    
    // create component list
    auto CL = vector<int>(N+1);
    for(int i=0;i<=N;i++) CL[i]=i; // filling up the parent component as for now all are independant nodes
    
    // Trverse the edges with minimum edges picking first
    for(int i=0;i<E;i++)
    {
        auto u = LE[i].second.first, // node U to node V
        v = LE[i].second.second, // till node V
        w = LE[i].first; // weight from U to V
        
        auto cu = findComponent(u, CL); //find component of u
        auto cv = findComponent(v, CL);
        if(cu!=cv)
        {
            ans+=w;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Minimum spanning tree algorithm World!\n";
    vector<int> U{4,3,7,2,3,6,9,1,7,5,6}, V{6,4,8,7,2,8,6,5,9,10,10}, W{1,3,5,5,6,8,10,11,12,14,14,20};
    cout<<"Minimum spanning tree : "<<krushkal(U, V, W, 10)<<endl;
    return 0;
}
