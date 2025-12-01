#include<iostream>
#include<vector>

using namespace std;
int solve(vector<int>& A);
int gcd(int a, int b);

int gcd(int a, int b)
{
  if (a == 0) return b;
  return gcd(b % a, a);
}

int solve(vector<int>& A) {
  vector<int> pgcd(A.size(),0);
  vector<int> sgcd(A.size(),0);
  int ans = 0;
  pgcd[0] = A[0];
  sgcd[A.size() - 1] = A[A.size() - 1];

  for (int i = 1,j = (A.size() - 2); i < A.size(); i++,j--)
  {
	pgcd[i] = gcd(pgcd[i], A[i]);
	sgcd[j] = gcd(sgcd[j], A[j]);
  }

  for (int i = 0, j = (A.size() - 1); i < A.size(); i++, j--)
  {
	cout << pgcd[i] << " " << sgcd[j];
	cout << endl;
  }
  return ans;
}
int main()
{
  vector<int> A = { 12, 15, 18 };
  cout << "Hello delete one\n";
  cout << "Max value of GCD : " << solve(A) << endl;
  return 0;
}