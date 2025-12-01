#include<iostream>
#include<vector>

using namespace std;
int calculateMinimumHP(vector<vector<int> >& A);
int calculateMinimumHPHelper(vector<vector<int> >& A, int i, int j, int M, int N);
int calculateMinimumHPHelperDP(vector<vector<int> >& A, vector<vector<int> >& dp, int i, int j, int M, int N);

int calculateMinimumHPHelper(vector<vector<int> >& A, int i, int j, int M, int N)
{
  if (i == M || j == N) return INT_MAX;
  if ((i == (M - 1)) && (j == (N - 1)))
  {
	return max(1, (1 - A[M - 1][N - 1]));
  }
  int a = calculateMinimumHPHelper(A, i + 1, j, M, N);
  int b = calculateMinimumHPHelper(A, i, j + 1, M, N);
  return max(1, (min(a, b) - A[i][j]));
}

int calculateMinimumHPHelperDP(vector<vector<int> >& A, vector<vector<int> >& dp,
  int i, int j, int M, int N)
{
  if (i == M || j == N) return INT_MAX;
  if (dp[i][j] == -1)
  {
	if (i == (M - 1) && (j == (N - 1)))
	{
	  dp[i][j] = max(1, (1 - A[M - 1][N - 1]));
	}
	else {
	  int a = calculateMinimumHPHelperDP(A, dp, i + 1, j, M, N);
	  int b = calculateMinimumHPHelperDP(A, dp, i, j+1, M, N);
	  dp[i][j] = max(1 , (min(a, b) - A[i][j]));
	}
  }
  return dp[i][j];
}
int calculateMinimumHP(vector<vector<int> >& A)
{
  int ans = 0;
  int R = (int)A[0].size(), C = (int)A.size(); //R-rows and C-columns
  vector<vector<int>> DP(R, vector<int>(C, -1));
  ans = calculateMinimumHPHelperDP(A, DP, 0, 0, R, C);
  return ans;
}

int main()
{
  cout << "hello knights princess\n";
  vector<vector<int>> A =
  {
	{ -2, -3, 3} ,
	{ -5, -10, 1},
	{10, 30, -5}
  };
  vector<vector<int>> B =
  {
	{1, -1, 0},
	{-1, 1, -1},
	{1, 0, -1}
  };

  cout << "Hello Prince to save you knight need health A:" << calculateMinimumHP(A) << endl;
  cout << "Hello Prince to save you knight need health B:" << calculateMinimumHP(B) << endl;

  return 0;
}