#include<iostream>
#include<string>
using namespace std;
string reverseString(string str);
void rev(char ar[], int l);
void printReverseString(string S, int len);

void rev(char ar[], int l)
{
  if (l == 0)
	return;
  cout << ar[l - 1];
  rev(ar, l - 1);
}

string reverseString(string S)
{
  string str = S;
  int s = 0, e = S.length() - 1;
  if (s < e)
  {
	char t = str[s];
	str[s] = str[e];
	str[e] = t;
	s++; e--;
  }
  return str;
}

void printReverseString(string S, int len)
{
  if (len == 0)
	return;
  cout << S[len - 1];
  printReverseString(S, len - 1);
}

int main()
{
  string input;
  cin >> input;
  printReverseString(input, input.length());
  return 0;
}