#include<iostream>
#include"../common/common.h"

using namespace std;

int divide(int A, int B) {
 
  long long int a = A, b = B;
  long long int ans = 0, t = a;
  int sign = 1;
  int flag = 0;
  if (a < 0)
	sign = -sign;
  if (b < 0)
	sign = -sign;

  if (A == 1 || A == -1)
	return A;

  a = abs(a);
  b = abs(b);


  for (int bit = 31; bit >= 0; bit--)
  {
	if (b * (static_cast<long long>(1) << bit) <= t)
	{
	  ans |= (static_cast<long long>(1) << bit);
	  t -= (b * (static_cast<long long>(1) << bit));
	  flag = 1;
	}
  }
 

  if (!flag) {
	ans = a;
  }

  if (sign < 0)
	ans = -ans;

  if (ans > INT_MAX)
	return INT_MAX;
  else
	return (int)ans;
}

int main()
{
  cout << "hello divide\n";
  cout << "Divisor : " << divide(5, 2) << endl;
  cout << "Divisor : " << divide(17, 2) << endl;
  cout << "Divisor : " << divide(0, 1) << endl;
  cout << "Divisor : " << divide(-2147483648, -10000000) << endl;

  return 0;
}