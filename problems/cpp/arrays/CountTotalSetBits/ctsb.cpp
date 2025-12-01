#include<iostream>
#include"../common/common.h"

using namespace std;

int setCount(unsigned int a);
int solve(int A);
int solveBF(int A);

int setCount(unsigned int a)
{
  int ans = 0;
  for (int b = getMSB(a); b >=0; b--)
  {
	if (a & (1 << b))
	  ans += 1;
  }
  return ans;
}

int solveBF(int A) 
{
  int ans = 0;
  unsigned int N = A;
  while (N)
  {
	ans += setCount(N);
	N -= 1;
  }
  return ans;
}

int solve(int A)
{
  int mod = 1000000007, power = 2, N = A + 1, ans = N / 2;

  while (power <= N)
  {
	int pair = N / power;

	ans += (pair / 2) * power;
	ans %= mod;

	ans += (pair & 1) ? (N % power) : 0;
	ans %= mod;
	power *= 2;
  }
  return ans;
}


int main()
{
  cout << "hello Set bits\n";
  cout << "Set bits : " << solve(3) << endl;
  cout << "Set bits : " << solve(10000000) << endl;
  return 0;
}