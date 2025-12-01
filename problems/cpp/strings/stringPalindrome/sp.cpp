#include<iostream>
#include<string>

using namespace std;
int checkPalindrome(string S, int s, int e);

int solveIterative(string A);
int solve(string A);

int solveIterative(string A) {
  int s = 0, e = A.length() - 1;

  if (A[s] != A[e])
  {
	return 0;
  }
  s++; e--;
  return 1;
}

int solve(string A)
{
  return checkPalindrome(A, 0, A.length() - 1);
}

int checkPalindrome(string S, int s, int e)
{
  if (s > e)
  {
	return 1;
  }
  if(S[s] == S[e])
  {
	checkPalindrome(S, s + 1, e - 1);
  }
  return 0;
}

int main()
{
  string str = "hello";
  cout << "Hello palindrome\n";
  cout << "stringg Palindrome: " << solve("hello") << endl;
  cout << "stringg Palindrome: " << solve("hellolleh") << endl;
  cout << "stringg Palindrome: " << solve("helloolleh") << endl;
  return 0;
}