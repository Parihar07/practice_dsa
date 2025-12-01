#include<iostream>
#include<vector>
using namespace std;

int solve(vector<char>& A) {
  int ans = 0;
  for (int i = 0; i < A.size(); i++)
  {
	if (!(A[i] >= 'A' && A[i] <= 'Z' ||
	  A[i] >= 'a' && A[i] <= 'z' ||
	  A[i] >= '0' && A[i] <= '9'))
	{
	  return 0;
	}
  }
  return 1;
}

int main()
{
  cout << "Hello AlphaNumeric\n";
  vector<char> A = { 'S', 'c', 'A', 'l', 'e', 'r', 'A', 'c', 'a', 'D', 'e', 'm', 'y' };
  vector<char> B = { 'S', 'c', 'a', 'L', 'e', 'r', '#', '2', '0', '2', '0' };

  cout << "Alphanumeric: " << solve(A)<<endl;
  cout << "Alphanumeric: " << solve(B)<<endl;
  return 0;
}