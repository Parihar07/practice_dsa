//
//  main.cpp
//  graph_damagedroads_primsMST
//
//  Created by CodeBreaker on 27/03/25.
//

/*
 vector<pair<int,int>> horizontal[1001];  // cost -> positions
 vector<pair<int,int>> vertical[1001];    // cost -> positions

 // Store horizontal roads
 for(int r = 0; r < row; r++) {
     for(int c = 0; c < C; c++) {
         horizontal[B[c]].push_back({r * col + c, r * col + c + 1});
     }
 }

 // Store vertical roads
 for(int r = 0; r < R; r++) {
     for(int c = 0; c < col; c++) {
         vertical[A[r]].push_back({r * col + c, (r+1) * col + c});
     }
 }
 
 Damaged Roads
 Attempted
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
int solve6(vector<int> &A, vector<int> &B) {
    const int MOD = 1000000007;
       int n = A.size(), m = B.size();
       vector<bool> vis((n+1)*(m+1), false);  // 1D visited array

       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vis[0] = true;

       // Add initial edges
       if(m > 0) pq.push({B[0], 1});          // right neighbor
       if(n > 0) pq.push({A[0], m+1});        // down neighbor

       long long ans = 0;
       while(!pq.empty()) {
           auto t = pq.top();
           int cost = t.first, node = t.second;
           pq.pop();

           if(!vis[node]) {
               vis[node] = true;
               ans = (ans + cost) % MOD;

               int r = node/(m+1), c = node%(m+1);

               if(c < m && !vis[node+1]) pq.push({B[c], node+1});
               if(r < n && !vis[node+m+1]) pq.push({A[r], node+m+1});
           }
       }

       return ans;
}

int solve5(vector<int> &A, vector<int> &B) {
    long long ans = 0;
    int n = A.size(), m = B.size();
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    vis[0][0] = true;

    // Add initial edges
    if(m > 0) pq.push({B[0], {0, 1}}); // right edge
    if(n > 0) pq.push({A[0], {1, 0}}); // down edge

    while(!pq.empty()) {
        int cost = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if(!vis[r][c]) {
            vis[r][c] = true;
            ans = (ans + cost) % 1000000007;

            // Add all possible edges from current position
            if(c < m && !vis[r][c + 1])
                pq.push({B[c], {r, c + 1}});
            if(r < n && !vis[r + 1][c])
                pq.push({A[r], {r + 1, c}});
            if(c > 0 && !vis[r][c - 1])
                pq.push({B[c-1], {r, c - 1}});
            if(r > 0 && !vis[r - 1][c])
                pq.push({A[r-1], {r - 1, c}});
        }
    }

    return (int)ans;
}

int solve4(vector<int> &A, vector<int> &B) {
    long long ans = 0;
    int n = A.size(), m = B.size();
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    vis[0][0] = true;

    // Add only right and down edges from current position
    if(m > 0) pq.push({B[0], {0, 1}}); // right edge
    if(n > 0) pq.push({A[0], {1, 0}}); // down edge

    while(!pq.empty()) {
        int cost = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if(!vis[r][c]) {
            vis[r][c] = true;
            ans = (ans + cost) % 1000000007;

            // Add only right and down edges
            if(c + 1 <= m) pq.push({B[c], {r, c + 1}});
            if(r + 1 <= n) pq.push({A[r], {r + 1, c}});
        }
    }

    return (int)ans;
}

int solve3(vector<int> &A, vector<int> &B) {
    long long ans = 0;
    int n = A.size(), m = B.size();
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    vis[0][0] = true;

    // Add only right and down edges from current position
    if(m > 0) pq.push({B[0], {0, 1}}); // right edge
    if(n > 0) pq.push({A[0], {1, 0}}); // down edge

    while(!pq.empty()) {
        int cost = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if(!vis[r][c]) {
            vis[r][c] = true;
            ans = (ans + cost) % 1000000007;

            // Add only right and down edges
            if(c + 1 <= m) pq.push({B[c], {r, c + 1}});
            if(r + 1 <= n) pq.push({A[r], {r + 1, c}});
        }
    }

    return (int)ans;
}

int solve2(vector<int> &A, vector<int> &B) {
    long long ans = 0;
    int row = A.size(), col = B.size();
    vector<vector<bool>> vis(row+1, vector<bool>(col+1, false));

    // Min heap: {cost, {x, y}}
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    vis[0][0] = true;

    // Add initial edges
    if(col > 0) pq.push({B[0], {0, 1}});
    if(row > 0) pq.push({A[0], {1, 0}});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(!vis[x][y]) {
            vis[x][y] = true;
            ans = (ans + cost) % 1000000007;

            // Add neighbors
            if(y < col && !vis[x][y+1]) pq.push({B[y], {x, y+1}});
            if(x < row && !vis[x+1][y]) pq.push({A[x], {x+1, y}});
            if(y > 0 && !vis[x][y-1]) pq.push({B[y-1], {x, y-1}});
            if(x > 0 && !vis[x-1][y]) pq.push({A[x-1], {x-1, y}});
        }
    }

    return (int)ans;
}

int solve(vector<int> &A, vector<int> &B){
    int ans=0;
    //using Prims algorithm
    auto row = A.size(), col=B.size();
    int S=0; // this would starting citi to start the conecting rest of country
    
    //creating adjacency list
    vector<pair<int, int>> G[(row+1)*(col+1)];
    int node=0;
    for(int r=0;r<=row;r++)
    {
        for(int c=0;c<=col;c++)
        {
            if(c<col){
                auto nextNode = node+1;
                G[node].push_back(make_pair(nextNode,B[c]));
                G[nextNode].push_back(make_pair(node,B[c]));
            }
            if(r<row){
                auto nextNode = node+col+1;
                G[node].push_back(make_pair(nextNode, A[r]));
                G[nextNode].push_back(make_pair(node, A[r]));
            }
            node++;
        }
    }
    
    //creating visting list and marking 0 node as visited
    auto vis = vector<int>(((row+1)*(col+1)), 0);
    vis[S]=1;
    
    //creating min heap adding adjacent cities of source to it
    auto minHeap = priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>(); //pair<costofraod, {start node v, next node u}>
    for(auto i:G[S])
    {
        auto v = i.first, w=i.second;
        minHeap.push(make_pair(w, make_pair(S, v)));
    }
    
    //Creating country with min COST i,e MST
    while(!minHeap.empty())
    {
        auto [W, C] = minHeap.top(); minHeap.pop(); // W-weights C-Cities
        auto v=C.second;
        if(vis[v]==0)
        {
            vis[v]=1;
            ans=(ans+W)%1000000007;
        }
        for(auto [V, Wei] : G[v])
        {
            if(vis[V]==0)
            {
                minHeap.push(make_pair(Wei, make_pair(v, V)));
            }
        }
    }
    return ans;
}

int solve7(vector<int>& A, vector<int>& B) {
    int mod = 1000000007;
    int row = A.size(), col = B.size();
    long long ans = 0;

    // Priority queue (min-heap) for {cost, (current node)}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

    // Visited matrix to track cities in MST
    vector<vector<bool>> visited(row + 1, vector<bool>(col + 1, false));

    // Start with the first city (0, 0)
    minHeap.push({0, {0, 0}});

    while (!minHeap.empty()) {
        auto [cost, pos] = minHeap.top(); minHeap.pop();
        int i = pos.first, j = pos.second;

        if (visited[i][j]) continue; // Skip already visited cities
        visited[i][j] = true;
        ans = (ans + cost) % mod;

        // Add neighbors dynamically
        if (i < row) { // Add vertical edge to (i+1, j)
            minHeap.push({A[i], {i + 1, j}});
        }
        if (j < col) { // Add horizontal edge to (i, j+1)
            minHeap.push({B[j], {i, j + 1}});
        }
    }

    return ans;
}

int solve8(vector<int>& A, vector<int>& B) {
    long long ans=0;
    auto row = A.size(), col=B.size();
    auto v = vector<pair<int,int>>();
    for(int i=0;i<row;i++) v.push_back({A[i],1});
    for(int i=0;i<col;i++) v.push_back({B[i],0});
    sort(v.begin(),v.end()); row++, col++;
    for(auto i : v)
    {
        if(i.second==1){
            ans = (ans +(row*i.first))%1000000007;
            col--;
        } else {
            ans= (ans +(col*i.first))%1000000007; row--;
        }
    }
    return (int)ans;
}

const int MOD = 1e9 + 7;
int solve9(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    vector < pair < long long int, long long int > > v;
    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(A[i], 0));
    }
    for (int i = 0; i < m; i++)
        v.push_back(make_pair(B[i], 1));
    sort(v.begin(), v.end());
    n++;
    m++;
    long long int ans = 0;
    for (auto u: v) {
        if (u.second == 0) {
            ans = (ans + (m * u.first) % MOD) % MOD;
            ans %= MOD;
            n--;
        } else {
            ans = (ans + (n * u.first) % MOD) % MOD;
            ans %= MOD;
            m--;
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Damaged road coutry using prim algorithm!\n";
    vector<int> A{1,1,1}, B{1,1,2};
    cout<< "Min Cost : " << solve9(A, B) <<endl;
    return 0;
}
