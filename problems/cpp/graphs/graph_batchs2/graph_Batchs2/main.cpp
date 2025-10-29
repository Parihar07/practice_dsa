//
//  main.cpp
//  graph_Batchs2
//
//  Created by CodeBreaker on 29/03/25.
//
/*
 Batches
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 A students applied for admission in IB Academy. An array of integers B is given representing the strengths of A people i.e. B[i] represents the strength of ith student.
 Among the A students some of them knew each other. A matrix C of size M x 2 is given which represents relations where ith relations depicts that C[i][0] and C[i][1] knew each other.
 All students who know each other are placed in one batch.
 Strength of a batch is equal to sum of the strength of all the students in it.
 Now the number of batches are formed are very much, it is impossible for IB to handle them. So IB set criteria for selection: All those batches having strength at least D are selected.
 Find the number of batches selected.
 NOTE: If student x and student y know each other, student y and z know each other then student x and student z will also know each other.


 Problem Constraints

 1 <= A <= 105
 1 <= M <= 2*105
 1 <= B[i] <= 104
 1 <= C[i][0], C[i][1] <= A
 1 <= D <= 109


 Input Format

 The first argument given is an integer A.
 The second argument given is an integer array B.
 The third argument given is a matrix C.
 The fourth argument given is an integer D.


 Output Format

 Return the number of batches selected in IB.


 Example Input

 Input 1:
  A = 7
  B = [1, 6, 7, 2, 9, 4, 5]
  C = [  [1, 2]
         [2, 3]
        `[5, 6]
         [5, 7]  ]
  D = 12
 Input 2:
  A = 5
  B = [1, 2, 3, 4, 5]
  C = [  [1, 5]
         [2, 3]  ]
  D = 6


 Example Output

 Output 1:
  2
 Output 2:
  1


 Example Explanation

 Explanation 1:
  Initial Batches :
     Batch 1 = {1, 2, 3} Batch Strength = 1 + 6 + 7 = 14
     Batch 2 = {4} Batch Strength = 2
     Batch 3 = {5, 6, 7} Batch Strength = 9 + 4 + 5 = 18
     Selected Batches are Batch 1 and Batch 2.
 Explanation 2:
  Initial Batches :
     Batch 1 = {1, 5} Batch Strength = 1 + 5  = 6
     Batch 2 = {2, 3} Batch Strength = 5
     Batch 3 = {4} Batch Strength = 4
     Selected Batch is only Batch 1.
 */
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
