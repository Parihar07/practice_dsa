#include<iostream>
#include<vector>

using namespace std;
int solve(vector<vector<int> >& A);
void dfs(vector<vector<int> >& M, int r, int c);

void dfs(vector<vector<int> >& M, int r, int c)
{
  int m = (int)M.size(), n = (int)M[0].size();
  if (r<0 || c<0 || r>=m || c>=n || M[r][c] == 0) return;
  M[r][c] = 0;
  //dfs(M, i + 1, j); //Down
  //dfs(M, i - 1, j); //Up
  //dfs(M, i, j + 1); //right
  //dfs(M, i, j - 1); //left
  //dfs(M, i + 1, j - 1); // down left corner
  //dfs(M, i + 1, j + 1); // down right corner
  //dfs(M, i - 1, j - 1); // up left corner
  //dfs(M, i - 1, j + 1); // up righ tcorner
  int x[] = { -1,-1,-1,0,0,1,1,1 };
  int y[] = { -1,0,1,-1,1,-1,0,1 };
  for (int i = 0; i < 8; i++)
  {
	dfs(M, (r + x[i]), (c + y[i]));
  }
  return;
}

int solve(vector<vector<int> >& A)
{
  int ans = 0;
  for (int i = 0; i < A.size(); i++)
  {
	for (int j = 0; j < A[0].size(); j++)
	{
	  if (A[i][j] == 1)
	  {
		ans += 1;
		dfs(A, i, j);
	  }
	}
  }
  return ans;
}

int main()
{
  cout << "hello no islands\n";
  vector<vector<int>> A = { {0, 1, 0},{0, 0, 1},{1, 0, 0} };
  vector<vector<int>> B = { {1, 1, 0, 0, 0},{0, 1, 0, 0, 0},{1, 0, 0, 1, 1},{0, 0, 0, 0, 0},{1, 0, 1, 0, 1} };

  cout << "Connected Islands : " << solve(B) << endl;
  return 0;
}