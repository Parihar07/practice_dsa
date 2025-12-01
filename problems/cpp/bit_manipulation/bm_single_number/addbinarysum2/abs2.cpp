#include<iostream>
#include<string>

using namespace std;
string addBinSum(string A, string B)
{
  string ans;
  int lenA = A.length()-1;
  int lenB = B.length()-1;
  int N = 0;
  string mB;

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
  }
  else {
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

  for (int i = 0; i <= mB.length(); i++)
  {
	ans.push_back('0');
  }

  if (A.length() > B.length())
  {
	for (int b = A.length(); b >= 0; b--)
	{
	  if ((A[b] == '1') || (mB[b] == '1'))
	  {
		if (mB[b] == '1')
		{
		  if (ans[b + 1] == '0')
		  {
			ans[b + 1] = '0';
			ans[b] = '1';
		  }
		  else
		  {
			ans[b + 1] = '1';
			ans[b] = '1';
		  }
		}
		else if (A[b]=='0') 
		{
		  if (ans[b + 1] == '0')
		  {
			ans[b + 1] = '1';
		  }
		  else
		  {
			ans[b + 1] = '0';
			ans[b] = '1';
		  }
		}
		else{
		  if (ans[b + 1] == '0')
		  {
			ans[b + 1] = '1';
		  }
		  else {
			ans[b + 1] = '0';
			ans[b] = '1';
		  }
		}
	  }
	  else if ((A[b] == '0') || (mB[b] == '0')) {
		if (mB[b] == '1')
		{
		  if (ans[b + 1] == '0')
		  {
			ans[b+1] = '1';
		  }
		  else
		  {
			ans[b + 1] = '0';
			ans[b] = '1';
		  }
		}
		else if (A[b] == '1')
		{
		  if (ans[b + 1] == '0')
		  {
			ans[b + 1] = '1';
		  }
		  else //1
		  {
			ans[b + 1] = '0';
			ans[b] = '1';
		  }
		}
		else {
		  if (ans[b + 1] == '0')
		  {
			ans[b + 1] = '0';
		  }
		  else {
			ans[b + 1] = '1';
		  }
		}
	  }
	}
  }


  return ans;
}
int main()
{
  cout << "Add binary sums\n";
  string A = "1101";
  string B = "11";
  cout << "sum of binstring : " << addBinSum(A, B) << endl;
  return 0;
}