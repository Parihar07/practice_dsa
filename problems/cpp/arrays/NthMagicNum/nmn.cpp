#include<iostream>

using namespace std;

int MagicNumber(int A)
{
  int ans = 0, p = 5;
  while (A > 0)
  {
	int r = A % 2;
	A /= 2;
	ans += r * p;
	p *= 5;
  }
  return ans;
}
int main()
{
  cout << "Magic Number : " << MagicNumber(10) << endl;
  return 0;
}