#include<iostream>
#include<string>
using namespace std;

int solve(string A)
{
  int ans = 0;
  for (int i = 0; i < A.length(); i++)
  {
	if (A[i] == 'a' || A[i] == 'A' ||
	  A[i] == 'e' || A[i] == 'E' ||
	  A[i] == 'i' || A[i] == 'I' ||
	  A[i] == 'o' || A[i] == 'O' ||
	  A[i] == 'u' || A[i] == 'U')
	  //(a+b)%M = (a%M + b%M)%M, (a-b)%M = (a%M  b%M + M)%M
	  ans = (ans + (((int)A.length() % 10003 - i % 10003 + 10003)) % 10003) % 10003;
  }
  return ans%10003;
}
int main()
{
  cout << "Amazing Strings\n";
  cout << "Substrings : " << solve("aaaaaaaaaa");
  return 0;
}