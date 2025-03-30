//
//  main.cpp
//  graph_damagedroadMST
//
//  Created by CodeBreaker on 27/03/25.
//

/*
 Damaged Roads
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are the Prime Minister of a country and once you went for a world tour.
 After 5 years, when you returned to your country, you were shocked to see the condition of the roads between the cities. So, you plan to repair them, but you cannot afford to spend a lot of money.
 The country can be represented as a (N+1) x (M+1) grid, where Country(i, j) is a city.
 The cost of repairing a road between (i, j) and (i + 1, j) is A[i]. The cost of repairing a road between (i, j) and (i, j + 1) is B[j].
 Return the minimum cost of repairing the roads such that all cities can be visited from city indexed (0, 0).
 As the cost can be large, return the cost modulo 109+7.


 Problem Constraints

 1 <= N, M <= 105
 1 <= A[i], B[i] <= 103


 Input Format

 The first argument will be an integer array, A, of size N.
 The second argument will be an integer array, B, of size M.


 Output Format

 Return an integer representing the minimum possible cost.


 Example Input

 Input 1:
  A = [1, 1, 1]
  B = [1, 1, 2]
 Input 2:
  A = [1, 2, 3]
  B = [4, 5, 6]


 Example Output

 Output 1:
  16
 Output 2:
  39


 Example Explanation

 Explanation 1:
  The minimum cost will be 16 if we repair the roads in the following way:
  Repair the roads from the all cities in row 0 to row 1 i.e. (0, j) to (1, j) (0 <= j <= 3), so that the cost will be 4 (A[0] * 4).
  Repair the roads from the all cities in row 1 to row 2 i.e. (1, j) to (2, j) (0 <= j <= 3), so that the cost will be 4 (A[1] * 4).
  Repair the roads from the all cities in row 2 to row 3 i.e. (2, j) to (3, j) (0 <= j <= 3), so that the cost will be 4 (A[2] * 4).
  Repair the roads (0, 0) to (0, 1), (0, 1) to (0, 2), (0, 2) to (0, 3), so that the cost will be B[0] + B[1] + B[2] = 4.
  Total cost will be 16.
  
 Explanation 2:
  The minimum possible cost will be 39.
 */

#include <iostream>
#include <vector>
using namespace std;
int findComp(int v, vector<int> &c)
{
    if(c[v]==v) return v;
    c[v]=findComp(c[v], c);
    return c[v];
}
int solve(vector<int> &A, vector<int> &B) {
    long ans=0;
    auto R = A.size(), C=B.size(); // country is depicted as grid or matrix form hence taking rows and columns
    auto row = R+1, col = C+1;// total number of cities to be connected with minimum cost;
    auto roads = vector<pair<int, pair<int, int>>>();
    int node = 0;
    //creating edge list so we can sort based the cost of road
    for(int r=0;r<=R;r++)
    {
        for(int c=0;c<=C;c++)
        {
            if (c < C) {
                int next_node = node + 1;
                if (next_node < row * col) {
                    roads.push_back({B[c], {node, next_node}});
                }
            }
            if (r < R) {
                int next_node = node + col;
                if (next_node < row * col) {
                    roads.push_back({A[r], {node, next_node}});
                }
            }
            node++;
        }
    }
    sort(roads.begin(), roads.end()); // sorting based on cost of road
    
    //creating comp list as of now all are independant cities(like nodes)
    auto comp = vector<int>(row*col); //this are number of cities like row x column of grid or matrix
    for(int i=0;i<(row*col); i++) comp[i]=i; //filling there root node as of now all are independant
    
    // Create one ran list t create union-find technique
    auto rank = vector<int>(row*col, 0); // all have there own roots so the rank is zero
    
    //itreate over sorted roads(edges)
    auto E = roads.size(); //number of edges
    for(int i=0;i<E;i++)
    {
        auto u = roads[i].second.first, cu = findComp(u, comp);
        auto v = roads[i].second.second, cv = findComp(v, comp);
        auto w = roads[i].first;
        if(cu!=cv)
        {
            ans=(ans + w)%1000000007;
            if(rank[cu] < rank[cv])
            {
                comp[cv]=cu;
            } else if(rank[cu] > rank[cv]){
                comp[cu]=cv;
            } else {
                comp[cv]=cu;
                rank[cu]++;
            }
            //      comp[max(cu,cv)]=comp[min(cu,cv)];
        }
    }
    
    
    
    return (int)ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, damaged road using MST!\n";
    vector<int> A{819,871,396,795,13,18,943,1,81,502,578,958,975,944,662,620,889,169,821,242,646,976,753,997,164,763,21,659,551,236,891,409,486,273,511,750,113,186,150,836,240,990,741,224,824,7,443,259,536,859,915,36,38,865,70,599,613,877,409,554,826,294,941,305,831,525,793,724,970,525,546,895,825,314,9,75,880,861,248,941,390,51,991,21,572,316,727,943,613,19,304,265,407,213,833,649,70,509,472,256,651,444,967,451,436,697,170,683,39,285,748,405,547,738,410,404,921,374,969,254,46,129,78,973,687,481,822,613,598,598,435,845,440,62,560,242,406,37,845,250,92,435,674,520,62,493,28,908,982,897,661,820,748,157,248,202,895,998,550,567,608,134,972,143,268,930,491,814,943,260,830,110,509,231,850,388,496,852,611,758,13,972,73,260,343,620,855,740,43,177,984,839,412,762,370,501,358,700,830,822,491,451,557,209,774,50,759,196,509,839,544,319,156,958,261,261,439,46,994,846,91,826,467,494,690,188,123,5,745,6,417,725,125,204,299,670,294,826,512,433,694,980,722,580,896,118,307,895,511,359,836,920,305,601,517,192,420,498,983,260,335,270,283,576,574,570,257,642,9,236,144,26,532,914,876,822,813,164,144,85,859,703,151,951}, B{166,497,953,946,283,867,474,942,296,702,796,278};
    cout<<"Minimum cost need is "<<solve(A, B)<<endl;
    return 0;
}
