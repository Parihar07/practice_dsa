#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& A, int B);
int solveOpt(vector<int>& A, int B);

int solve(vector<int>& A, int B) {
  int N = A.size();
  int ans = 0;
  int mod = 1000000007;
  for (int i = 0; i < N; i++)
  {
	for (int j = i + 1; j < N; j++)
	{
	  if (!((A[i]%mod + A[j]%mod) % B))
	  {
		ans++;
	  }
	}
  }
  return ans % mod;
}

int solveOpt(vector<int>& A, int B)
{
  long ans = 0;
  int currInd = 0, pairInd = 0, mod = 1000000007;
  vector<int> FA(B, 0);
  for (int i = 0; i < A.size(); i++)
  {
	FA[A[i] % B]++;
  }

  ans += (FA[0] * (FA[0] - 1)) / 2;
  ans %= mod;
  currInd = 1; pairInd = B - 1;
  while (currInd < pairInd)
  {
	ans = (ans % mod + (FA[currInd] * FA[pairInd]) % mod) % mod;
	currInd++;
	pairInd--;
  }
  if (!(B % 2))
  {
	ans += ((FA[(B / 2)] * (FA[(B / 2)] - 1)) / 2)%mod;
	ans %= mod;
  }
  return (ans % mod)+mod;
}
int main()
{
  vector<int> A = { 1, 2, 3, 4, 5 };
  vector<int> B = { 5, 17, 100, 11 };
  cout << "Pair Sum sivisible by 2 : " << solveOpt(A, 2) << endl;
  cout << "Pair Sum sivisible by 2 : " << solveOpt(B, 28) << endl;
  return 0;
}
