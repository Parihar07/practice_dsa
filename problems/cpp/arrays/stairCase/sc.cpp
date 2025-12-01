#include<iostream>

using namespace std;

int climbStairs(int A)
{
  if (A <= 2)return A;
  long a = 1, b = 2, c = 0; int  mod = 1000000007;
  for (int i = 2; i < A; i++)
  {
	c = (a + b)%mod;
	a = b;
	b = c;
  }
  return c;
}

int main()
{
  cout << "hello stair case problem\n";
  cout << "No ways to climb stair case: " << climbStairs(55007) << endl;
  return 0;
}