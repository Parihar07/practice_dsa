#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007

int solve(vector<int>& A);
int solveOpt(vector<int>& A);

int solve(vector<int>& A) {
  int sum = 0;
  int ans = 0;
  for (int i = 0; i < A.size(); i++)
  {
	for (int j = 0; j < A.size(); j++)
	{
	  sum = 0;
	  for (int p = i; p <= j; p++)
	  {
		sum |= A[p];
	  }
	  ans = (ans % MOD + sum % MOD) % MOD;
	}
  }
  return ans;
}
int solveOpt(vector<int>& A) {
  int sum = 0;
  size_t N = A.size();
  vector<int> PAOR(N, 0);
  PAOR[0] = A[0];

  for (int i = 1; i < A.size(); i++)
  {
	PAOR[i] = PAOR[i - 1] | A[i];
  }

  for (int i = 1; i < A.size(); i++)
  {
	for (int j = i; j < A.size(); j++)
	{
	 sum ^| 
	}
  }
  return sum;
}

int main()
{
  vector<int> A = { 1, 2, 3, 4, 5 };
  cout << "SUM of OR : " << solveOpt(A) << endl;
  vector<int> B = { 7, 8, 9, 10 };
  cout << "SUM of OR : " << solveOpt(B) << endl;

  return 0;
}