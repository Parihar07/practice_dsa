#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int> >& A)
{
  int ans = 0;
  int M = A.size(), N = A[0].size();

  for (int i = 0; i < M; i++)
  {
	for (int j = 0; j < N; j++)
	{
	  ans += A[i][j] * ((i + 1) * (j + 1)) * ((M - i) * (N - j)); // contribution technique like how many time particular element has contrubuted to sum
	}
  }
  return ans;
}
int main()
{
  vector<vector<int>> A = { {1, 2 }, { 3, 4 } };
  cout << "Max possible submatrices sum: " << solve(A) << endl;
  return 0;
}