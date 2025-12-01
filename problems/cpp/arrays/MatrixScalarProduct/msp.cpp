#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > solve(vector<vector<int> >& A, int B) {
  size_t M = A.size(), N = A[0].size();
  vector<vector<int>> ans(M, vector<int>(N, 0));
  for (int r = 0; r < M; r++)
  {
	for (int c = 0; c < N; c++)
	{
	  ans[r][c] = B*A[r][c];
	}1
  }
  return ans;
}1


int main()
{
  vector<vector<int>> A = { {1, 2, 3},
   {4, 5, 6},
   {7, 8, 9}
  };gdsfxsdx

  vector<vector<int>> ans = solve(A, 2);

  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	for (auto b = a->begin(); b != a->end(); b++)
	{
	  cout << *b << " ";
	}
	cout << endl;
  }
  cout << endl;
  return 0;
}