#include<iostream>
#include<string>

using namespace std;


int pow(int N, int p)
{
  if (p == 0)return 1;
  return N * pow(N, p - 1);
}

int getDigitCount(int N)
{
  if (N == 0)return 0;
  return 1 + getDigitCount(N / 10);
}

int getNumericNum(string s)
{
  int n = (int)s.length() - 1;
  int ans = 0;
  int tens = 1;
  while (n >= 0)
  {
	char ch = s[n];
	int digi = ch - '0';

	if (ans == 0)
	  ans += digi * tens;
	else
	{
	  tens *= 10;
	  ans += tens * digi;
	}
	n--;
  }
  return ans;
}
int modString(string A, int B)
{
  int n = (int)A.length() - 1;
  long ans = 0;
  long tens = 1;
  while (n >= 0)
  {
	char ch = A[n];
	int digi = ch - '0';
	ans = (ans % B + (digi * tens)%B) % B;
	tens = (tens % B * 10 % B) % B;
	n--;
  }
  return ans;
}

int main()
{
  cout << "Hello mod string\n";
  cout << "mod : " << modString("43535321", 47) << endl;
  return 0;
}