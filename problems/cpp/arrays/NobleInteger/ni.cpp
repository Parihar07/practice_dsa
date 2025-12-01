#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve1(vector<int>& A);
int solve(vector<int>& A);

int solve1(vector<int>& A) {
  int cnt = 0;
  for (int i = 0; i < A.size(); i++)
  {
	cnt = 0;
	for (int j = 0; j < A.size(); j++)
	{
	  if (A[i] < A[j]) cnt++;
	  if (A[i] == cnt || A[i] == -cnt) return 1;
	}
  }
  return -1;
}

int solve(vector<int>& A)
{
  sort(A.begin(), A.end());
  int N = (int)A.size();
  for (int i = 0; i < N; i++)
  {
	if (A[i] == A[i + 1]) continue;
	if (A[i] == N - (i + 1)) return 1;
  }
  if (A[N - 1] == 0) return 1;
  return -1;
}

int main()
{
  cout << "hello noble integer\n";
  vector<int> A = { -4,-2,0,-1,-6 };

  cout << " Noble Integer: " << solve(A) << endl;
}