#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
  vector<int> solve(vector<vector<int> >& A, vector<int>& B, vector<int>& C,
	vector<int>& D, vector<int>& E);
};

vector<int> Solution::solve(vector<vector<int> >& A,
  vector<int>& B, vector<int>& C,
  vector<int>& D, vector<int>& E)
{
  int mod = 1000000007;
  //Answer array
  vector<int> ans;
  //create Prefix sum matrix;
  vector<vector<int>> PFS(A.size(), vector<int>(A[0].size(), 0));
  for (int i = 0; i < A.size(); i++)
  {
	for (int j = 0; j < A[i].size(); j++)
	{
	  PFS[i][j] = A[i][j];
	}
  }

  for (int i = 0; i < A.size(); i++)
  {
	for (int j = 1; j < A[i].size(); j++)
	{
	  PFS[i][j] = ((PFS[i][j - 1]) % mod + (A[i][j]) % mod) % mod;
	}
  }

  for (auto a : PFS)
  {
	for (auto b : a)
	{
	  cout << b << " ";
	}
	cout << endl;
  }

  for (int j = 0; j < A[0].size(); j++)
  {
	for (int i = 1; i < A.size(); i++)
	{
	  PFS[i][j] = ((PFS[i - 1][j]) % mod + (PFS[i][j])%mod) % mod;
	}
  }

  // for (auto a : PFS)
  // {
	 //for (auto b : a)
	 //{
	 //  cout << b << " ";
	 //}
	 //cout << endl;
  // }

  for (int q = 0; q < B.size(); q++)
  {
	int a = B[q] - 1, b = C[q] - 1, x = D[q] - 1, y = E[q] - 1;
	int sum = PFS[x][y];
	if (b > 0)sum -= PFS[x][b - 1];
	if (a > 0)sum -= PFS[a - 1][y];
	if (a > 0 && b > 0)sum = (sum + PFS[a - 1][b - 1])%mod;

	ans.push_back(sum);
  }

  return ans;
}

int main()
{
  cout << "Hello sum of sub matrix queries2\n";
  vector<int> ans;

  vector<vector<int>> A = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
  vector<int> B = { 1, 2 }, C = { 1, 2 }, D = { 2, 3 }, E = { 2, 3 };

  vector<vector<int>> K = { {5, 17, 100, 11},{0, 0, 2, 8} };
  vector<int> L = { 1, 1 }, M = { 1, 4 }, N = { 2, 2 }, O = { 2, 4 };

  Solution so;
  ans = so.solve(A, B, C, D, E);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  ans = so.solve(K, L, M, N, O);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  return 0;
}