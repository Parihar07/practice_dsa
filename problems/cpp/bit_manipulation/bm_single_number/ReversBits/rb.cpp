#include<iostream>
using namespace std;

unsigned int reverse(unsigned int A) {
  // Do not write main() function.
  // Do not read input, instead use the arguments to the function.
  // Do not print the output, instead return values as specified
  // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  unsigned int ans=0;
  for (int s = 0, r = 31; s < 32; s++, r--)
  {
	if (A & (1 << s))
	{
	  ans |= (1 << r);
	}
  }
  return ans;
}

int main()
{
  cout << "reversed  : " << reverse(0) << endl;
  cout << "reversed  : " << reverse(3) << endl;
  return 0;
}