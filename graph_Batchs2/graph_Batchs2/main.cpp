//
//  main.cpp
//  graph_Batchs2
//
//  Created by CodeBreaker on 29/03/25.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solve(int A, vector<int> &B, vector<vector<int> > &C, int D) {
    //step creating adjacency list
    int ans =0;
    vector<int> G[A+1];
    auto E = C.size();
    for(int i=0;i<E;i++)
    {
        G[C[i][0]].push_back(C[i][1]);
        G[C[i][1]].push_back(C[i][0]); //Undirected graph
    }
    
    //step Create visiting array
    auto vis = vector<int>(A+1,0);
    
    //create que and push node 1 here
    auto q=queue<int>();
    q.push(1); vis[1]=1; // marking node 1 as visited
    
    int strength = B[0]; // just sum batch strength
    //iterate over the graph get the batch strength ig q.epmty then add same by iterating over the vis array
    while(!q.empty())
    {
        auto t = q.front(); q.pop();
        for(auto i: G[t])
        {
            if(vis[i]==0)
            {
                q.push(i);
                vis[i]=1;
                strength += B[i-1];
            }
        }
        
        if(q.empty()==true)
        {
            if(strength>=D) ans++;
            strength=0;
            for(int j=1;j<=A;j++)
            {
                if(vis[j]==0) {
                    q.push(j);
                    vis[j]=1;
                    strength = B[j-1];
                    break;
                }
            }
           
        }
    }
    
    return ans;
}

int solve2(int A, vector<int> &B, vector<vector<int> > &C, int D) {
    //step creating adjacency list
    int ans =0;
    vector<int> G[A+1];
    auto E = C.size();
    for(int i=0;i<E;i++)
    {
        G[C[i][0]].push_back(C[i][1]);
        G[C[i][1]].push_back(C[i][0]); //Undirected graph
    }
    
    //step Create visiting array
    auto vis = vector<int>(A+1,0);
    
    //create que and push node 1 here
    auto q=queue<int>();

    //iterate over the graph get the batch strength ig q.epmty then add same by iterating over the vis arra
    for(int j = 1; j <= A; j++) {
        if(vis[j] == 0) {
            q.push(j);
            vis[j] = 1;
            int strength = B[j-1]; // Initialize strength for the new component
            
            while(!q.empty()) {
                auto t = q.front(); q.pop();
                for(auto i: G[t]) {
                    if(vis[i] == 0) {
                        q.push(i);
                        vis[i] = 1;
                        strength += B[i-1];
                    }
                }
            }
            
            if(strength >= D) ans++;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Student strength!\n";
    vector<int> B{1,6,7,2,9,4,5};
    vector<vector<int>> C{{1,2},{2,3},{5,6},{5,7}};
    cout<<"totoal qualified batchs : "<<solve(7, B, C, 12)<<endl;
    return 0;
}
