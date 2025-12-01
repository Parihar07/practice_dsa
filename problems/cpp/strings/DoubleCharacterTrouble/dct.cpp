#include<iostream>
#include<string>
#include<stack>

using namespace std;

string solve(string A) {
  int l = A.length()-1;
  string ans;
  stack<char> stk;
  while (l>=0)
  {
	if (stk.empty())
	{
	  stk.push(A[l]);
	}
	else {
	  if (stk.top() == A[l])
	  {
		stk.pop();
	  }
	  else {
		stk.push(A[l]);
	  }
	}
	l--;
  }
  while (!stk.empty())
  {
	ans.push_back(stk.top());
	stk.pop();
  }
  return ans;
}

int main()
{
  string A = "abccbc";
  string b = "parihar";

  cout << "Trouble Free String " << solve(A) << endl;
  cout << "Trouble Free String " << solve(b) << endl;

  return 0;
}