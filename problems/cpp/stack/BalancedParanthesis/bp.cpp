#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

int solve(string A);
int solve2(string A);

int solve2(string A) {
  unordered_map<char, char> pmap;
  pmap['['] = ']';
  pmap['{'] = '}';
  pmap['('] = ')';
  pmap['"'] = '"';
  pmap[']'] = '[';
  pmap['}'] = '{';
  pmap[')'] = '(';
  pmap['"'] = '"';

  stack<char> stk;
  int l = A.length() - 1;
  while (l >= 0)
  {
	if (stk.empty())
	{
	  stk.push(A[l]);
	}
	else {
	  if (pmap.find(stk.top()) != pmap.end())
	  {
		stk.pop();
	  }
	  else {
		stk.push(A[l]);
	  }
	}
	l--;
  }

  return stk.empty() ? 1 : 0;
}

int solve(string A)
{
  stack<char> stk;
  int l = A.length() - 1;
  while (l >= 0)
  {
	if (stk.empty())
	{
	  stk.push(A[l]);
	}
	else {
	  if ((stk.top() == '}' && A[l] == '{') ||
		(stk.top() == ')' && A[l] == '(') ||
		(stk.top() == ']' && A[l] == '['))
	  {
		stk.pop();
	  }
	  else {
		stk.push(A[l]);
	  }
	}
	l--;
  }

  return stk.empty() ? 1 : 0;
}
int main()
{
  string A = "{([])}";
  string B = "{([])";
  string C = "{[]}[]";
  string D = "(((((((((((";

  cout << " Valid : " << solve(A) << endl;
  cout << " Valid : " << solve(B) << endl;
  cout << " Valid : " << solve(C) << endl;
  cout << " Valid : " << solve(D) << endl;

  return 0;
}