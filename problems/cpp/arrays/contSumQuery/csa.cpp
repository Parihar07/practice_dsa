#include <iostream>
#include <vector>

using namespace std;
vector<int> solveOP(int A, vector<vector<int>> &B);
vector<int> solve(int A, vector<vector<int>> &B);

vector<int> solve(int A, vector<vector<int>> &B)
{
  vector<int> psq;
  for (int i = 0; i < A; i++)
  {
    psq.push_back(0);
  }
  int p, q;
  for (int i = 0; i < B.size(); i++)
  {
    p = B[i][0];
    q = B[i][1];
    while (p <= q)
    {
      psq[p - 1] += B[i][2];
      p++;
    }
  }
  return psq;
}

vector<int> solveOP(int A, vector<vector<int>> &B)
{
  vector<int> psq, ans;
  for (int i = 0; i < A; i++)
  {
    psq.push_back(0);
  }
  ans = psq;
  int l, r, p;
  for (int i = 0; i < B.size(); i++)
  {
    l = B[i][0];
    r = B[i][1];
    psq[l - 1] += B[i][2];
    if (r < A)
      psq[r] -= B[i][2];
  }
  ans[0] = psq[0];
  p = ans[0];

  for (int i = 1; i < A; i++)
  {
    p += psq[i];
    ans[i] = p;
  }
  return ans;
}

int main()
{
  vector<vector<int>> A = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};

  vector<int> ans = solveOP(5, A);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}