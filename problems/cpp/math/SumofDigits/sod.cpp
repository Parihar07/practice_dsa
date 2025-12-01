#include<iostream>

using namespace std;

int solve(int A);
int solveL(int A);

int solveL(int A) {
  int ans = 0;
  int N = A;
  if ((A % 10) == A)
	return A;
  while (N > 0)
  {
	ans += (N % 10);
	N /= 10;
  }
  return ans;
}

int solve(int A) {
  int ans = 0;
  if ((A % 10) == A)
	return A;
  ans += (A % 10);
  return ans + solve(A / 10);
}

int main()
{
  cout << "hello sum of digits\n";
  cout << "Sum : " << solve(46) << endl;
  return 0;
}