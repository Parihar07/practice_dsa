#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int knapsackHelper(vector<int>& A, vector<int>& B, vector<vector<int>>& dp, int ind, int w);
int knapsackHelperIT(vector<int>& A, vector<int>& B, int C);
int solve(vector<int>& A, vector<int>& B, int C);

int knapsackHelperIT(vector<int>& A, vector<int>& B, int C)
{
  int V = (int)A.size();
  vector<vector<int>> DP(2, vector<int>(C + 1,0));
  for (int i = 1; i < V; i++)
  {
	for (int j = 0; j <= C; j++)
	{
	  int a = DP[(i - 1)%2][j];
	  if (j >= B[i])
	  {
		a = max(a, (DP[(i - 1)%2][j - B[i]] + A[i]));
	  }
	  DP[i%2][j] = a;
	}
  }
  return DP[(V - 1)%2][C];
}
int knapsackHelper(vector<int>& A, vector<int>& B, vector<vector<int>>& dp,
  int ind, int w)
{
  if (ind == 0 || w == 0) return 0;
  if (dp[ind][w] == -1)
  {
	int a = knapsackHelper(A, B, dp, ind - 1, w);
	if (w >= B[ind])
	{
	  a = max(a, (knapsackHelper(A, B, dp, ind - 1, w - B[ind]) + A[ind]));
	}
	dp[ind][w] = a;
  }
  return dp[ind][w];
}
int solve(vector<int>& A, vector<int>& B, int C) {
  int ans = 0;
  int V = (int)A.size();
  //vector<vector<int>> DP(V + 1, vector<int>(C + 1, -1));
  ans = knapsackHelperIT(A, B, C);
  return ans;
}

int main()
{
  cout << "Hello Knapsack\n";
  vector<int> A = { 6, 10, 12 };
  vector<int> B = { 10, 20, 30 };
  cout << "Maxk sack size: " << solve(A, B, 50) << endl;
  return 0;
}