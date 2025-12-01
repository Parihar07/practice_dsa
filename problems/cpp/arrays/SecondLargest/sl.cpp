#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solveNaive(vector<int>& A);
int solve(vector<int>& A);
int solveNaive(vector<int>& A) {
  sort(A.begin(), A.end());
  if (A.size() == 1)
	return -1;
  return A[A.size() - 2];
}

int solve(vector<int>& A)
{
  int p = A[0], q = -1;
  for (int i = 0; i < A.size(); i++)
  {
	if (A[i] > p)
	{
	  p = A[i];
	}
  }
  cout << "First Largest" << p << endl;
  for (int i = 0; i < A.size(); i++)
  {
	if (A[i] > q)
	{
	  if (A[i] < p)
		q = A[i];
	}
  }
  return q;
}
int main()
{
  vector<int> A = { 2, 1, 2 };
  vector<int> B = { 2 };
  cout << "Second Largest : " << solve(A) << endl;
  cout << "Second Largest : " << solve(B) << endl;
  return 0;
}