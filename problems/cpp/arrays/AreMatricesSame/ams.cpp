#include<iostream>
#include<vector>

using namespace std;

int solve(vector<vector<int> >& A, vector<vector<int> >& B) {
  size_t M = A[0].size(), N = A.size();
  if (A[0].size() != B[0].size()) return 0;
  if (A.size() != B.size()) return 0;
  for (int r = 0; r < M; r++)
  {
	for (int c = 0; c < N; c++)
	{
	  if (A[r][c] != B[r][c])
	  {
		return 0;
	  }
	}
  }
  return 1;
}

int main()
{
  cout << "Are matrices same\n";
  vector<vector<int>> A = { {1, 2, 3},
	{4, 5, 6},
	{7, 8, 9}
  };
  vector<vector<int>> B = { {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
  };

  vector<vector<int>> C = { {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
  };
  vector<vector<int>> D = { {1, 2, 3},
  {4, 5, 9},
  {7, 8, 6}
  };
  cout << "matrices equality : " << solve(A, B) << endl;
  cout << "matrices equality : " << solve(C, D) << endl;
  return 0;
}