#include<iostream>
#include<string>

using namespace std;

int main()
{
  string A = "1011";
  string B = "110101101";

  string mB;
  int N = 0;

  if (A.length() > B.length())
  {
	N = A.length() - B.length();

	for (int i = 0; i < N; i++)
	{
	  mB.push_back('0');
	}
	for (int i = 0; i < B.length(); i++)
	{
	  mB.push_back(B[i]);
	}
  }else{
	N = B.length() - A.length();
	for (int i = 0; i < N; i++)
	{
	  mB.push_back('0');
	}
	for (int i = 0; i < A.length(); i++)
	{
	  mB.push_back(A[i]);
	}
  }

  cout << mB << endl;
  cout << A << endl;
  cout << B << endl;

  return 0;
}