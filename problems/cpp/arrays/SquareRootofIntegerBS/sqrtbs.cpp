#include<iostream>

using namespace std;

int sqrt(int A) {
  long ans=0;
  long s = 0, e = A, mid = -1;
  if (A == 0)
  {
	return ans;
  }
  while (s <= e)
  {
	mid = (s + e) / 2;
	if ((mid * mid) <= A)
	{
	  ans = mid;
	  s = mid + 1;
	}
	else {
	  e = mid - 1;
	}
  }
  return ans%1000000007;
}


int main()
{
  cout << "hello square root\n";
  cout << "Square root of number : " << sqrt(0);
  return 0;
}