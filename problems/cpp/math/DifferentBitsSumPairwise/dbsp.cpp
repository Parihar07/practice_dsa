/*
* We define f(X, Y) as the number of different corresponding bits in the binary representation of X and Y.
For example, f(2, 7) = 2, since the binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2,..., AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.
*/


#include<iostream>
#include<vector>

using namespace std;

int func(int a, int b);
int cntBits(vector<int>& A);
int cntBitsOpt(vector<int>& A);
int mod = 1000000007;

int func(int a, int b)
{
  int temp = a ^ b;
  int ans = 0;
  for (int b = 31; b >= 0; b--)
  {
	if (temp & (1 << b))
	{
	  ans += 1;
	}
  }
  return ans;
}

int cntBits(vector<int>& A) {
  int N = A.size();
  int sum = 0;
  for (int x = 0; x < N - 1; x++)
  {
	for (int y = x + 1; y < N; y++)
	{
	  sum = (sum % mod + (2 * func(A[x], A[y])) % mod) % mod;
	}
  }
  return sum;
}

int cntBitsOpt(vector<int>& A) {
  int sumSetBits = 0;
  int ans = 0;
  for (int b = 0; b < 32; b++)
  {
	sumSetBits = 0;
	for (int i = 0; i < A.size(); i++)
	{
	  if (A[i] & (1 << b))
		sumSetBits += 1;
	}

	ans += 2 * sumSetBits * (A.size() - sumSetBits);
	ans %= mod;
  }
  return ans;
}
int main()
{
  vector<int> A = { 1, 3, 5 };
  vector<int> B = { 2, 3 };

  cout << "count diff bits : " << cntBitsOpt(A) << endl;
  cout << "count diff bits : " << cntBitsOpt(B) << endl;

  return 0;
}
