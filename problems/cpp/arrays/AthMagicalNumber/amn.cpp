#include<iostream>
#include"../common/common.h"

using namespace std;
long gcd(long a, long b);
long f(long x, long b, long c);
int solve(int A, int B, int C);

long gcd(long a, long b)
{
  if (a == 0)
	return b;
  return gcd(b % a, a);
}

long f(long x, long b, long c)
{
  long l = ((b * c) % 1000000007) / gcd(b, c);
  return ((x / b) + (x / c) - (x / l));
}

int solve(int A, int B, int C) {
  long s = 1, e = A * _min(B, C), mid=-1, ans=0;
  int cnt = 0;
  while (s <= e)
  {
	mid = (s + e) / 2;
	cnt = f(mid, B, C);
	if (cnt >= A)
	{
	  ans = mid;
	  e = mid - 1;
	}
	else {
	  s = mid + 1;
	}
  }
  return (int)ans%1000000007;
}

int main()
{
  cout << "Something magical\n";
  cout << "Magical Sequence: " << solve(1, 2, 3) << endl;
  cout << "Magical Sequence: " << solve(4, 2, 3) << endl;
  cout << "Magical Sequence: " << solve(807414236, 3788, 38141)<< endl;
  return 0;
}