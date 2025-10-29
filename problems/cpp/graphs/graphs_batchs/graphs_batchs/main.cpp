//
//  main.cpp
//  graphs_batchs
//
//  Created by CodeBreaker on 21/03/25.
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
#include <vector>
#include <unordered_set>
using namespace std;

//{
//
//    // After the union operations, pre-compute all root components
//    vector<int> root(A + 1);
//    for(int i = 1; i <= A; i++) {
//        root[i] = findComponent(i, comp);
//    }
//
//    // Use root array instead of calling findComponent repeatedly
//    auto us = unordered_set<int>();
//    for(int i = 1; i <= A; i++) us.insert(root[i]);
//
//    for(auto const &k : us) {
//        int sum = 0;
//        for(int i = 1; i <= A; i++) {
//            if(root[i] == k) {
//                sum += B[i-1];
//            }
//        }
//        if(sum >= D) ans++;
//    }
//}

//int findComponent2(int n, vector<int> &c) {
//    if (c[n] != n) {
//        c[n] = findComponent(c[n], c); // path compression
//    }
//    return c[n];
//}

//void unionComponents(int u, int v, vector<int> &c, vector<int> &rank) {
//    int rootU = findComponent(u, c);
//    int rootV = findComponent(v, c);
//    if (rootU != rootV) {
//        if (rank[rootU] > rank[rootV]) {
//            c[rootV] = rootU;
//        } else if (rank[rootU] < rank[rootV]) {
//            c[rootU] = rootV;
//        } else {
//            c[rootV] = rootU;
//            rank[rootU]++;
//        }
//    }
//}

//int solve2(int A, vector<int> &B, vector<vector<int>> &C, int D) {
//    int ans = 0;
//    auto E = C.size(); // number of edges to iterate
//    // Creating component list and rank list
//    auto comp = vector<int>(A + 1);
//    auto rank = vector<int>(A + 1, 0);
//    for (int i = 1; i <= A; i++) comp[i] = i; // initialize components
//
//    // Iterating over edges to update the component list
//    for (int i = 0; i < E; i++) {
//        int u = C[i][0], v = C[i][1];
//        unionComponents(u, v, comp, rank);
//    }
//
//    // Calculate the sum of strengths for each component
//    auto componentSum = vector<int>(A + 1, 0);
//    for (int i = 1; i <= A; i++) {
//        int root = findComponent(i, comp);
//        componentSum[root] += B[i - 1];
//    }
//
//    // Count the number of components with strength at least D
//    for (int i = 1; i <= A; i++) {
//        if (comp[i] == i && componentSum[i] >= D) {
//            ans++;
//        }
//    }
//
//    return ans;
//}


int findComponent(int n, vector<int> &c)
{
    if(c[n]==n) return n;
    c[n]=findComponent(c[n], c);
    return c[n];
}

int solve(int A, vector<int> &B, vector<vector<int> > &C, int D) {
    int ans=0;
    auto E = C.size(); //no of edges to iterate
    
    //Creating component list
    auto comp = vector<int>(A+1);
    for(int i=0;i<=A;i++) comp[i]=i; // as of not all the components are independant hence assigning there components as them selves
    
    //Iterating over edges to update the component list
    for(int i=0;i<E;i++)
    {
        int u = C[i][0], v = C[i][1];
        int cu = findComponent(u, comp), cv = findComponent(v, comp);
        if(cu!=cv)
        {
            comp[max(cu,cv)] = comp[min(cu,cv)]; //to maintain the uniformity accross the root component
        }
    }
    
//    //push all components of student to unordered set will get total batchs here;
//    auto us = unordered_set<int>();
//    for (int i = 1; i <= A; i++) us.insert(findComponent(i, comp));
//    
//    //chcek the components of each node if same they belong to same batch hence add there strength
//    for(auto const &k:us)
//    {
//        int sum=0;
//        for(int i=1;i<=A;i++)
//        {
//            if (findComponent(i, comp) == k) {
//                sum += B[i - 1];
//            }
//        }
//        if(sum>=D) ans++; //count if strength atlest D
//    }
//
    
    //Optimizing above line code
    // Perform path compression for all nodes after Union-Find
    for (int i = 1; i <= A; i++) {
        findComponent(i, comp); // Ensure comp[i] contains the correct root
    }
    
    //creating component strength list it will hold the sum of each batch based on there root nodes/cpompnents
    auto compStrength = vector<int>(A+1, 0);
    for(int i=1; i<=A; i++)
    {
        compStrength[comp[i]]+=B[i-1];
    }
    
    //calculates batchs having qualifying strength
    for(auto i:compStrength)
    {
        if(i>=D) ans++;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Student for IB Admission!\n";
    vector<int> B {37,53,46,66,66,31,51,52,62,55,58,66,52,36,42,52,35,59,63,55,52,39,61,41,45,50,52,39,69,41,30,65,54,51,45,63,52,42,69,58,55,56,56,32,42,63,35,36,37,62,37,40,67,52,31,35,68,60,50}; // {1,6,7,2,9,4,5};
    vector<vector<int>> C{{2,16},{2,50},{3,56},{7,45},{8,13},{8,14},{8,54},{9,58},{11,44},{12,36},{15,22},{15,53},{15,56},{16,40},{16,41},{17,20},{20,30},{22,58},{23,31},{25,45},{26,34},{27,42},{29,45},{34,45},{35,41},{36,57},{37,38},{44,58},{47,51},{50,57}}; //{{1,2},{2,3},{5,6},{5,7}};
    cout<<"Batchs selected : "<<solve(59, B, C, 260)<<endl;
    return 0;
}
