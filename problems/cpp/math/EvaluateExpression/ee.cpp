#include<iostream>
#include<stack>
#include<vector>
#include<unordered_set>
#include <string>

using namespace std;
//"5","1","2","+","4","*","+","3","-"
int evalRPN(vector<string>& A) {
  int ans = 0;
  int N = A.size();
  stack<string> stk;
  unordered_set<string> o_set;
  o_set.insert("+");  o_set.insert("-");
  o_set.insert("*");  o_set.insert("/");
  vector<int> digits(2, 0);
  for (int i = 0; i < N; i++)
  {
	if (stk.empty())
	{
	  stk.push(A[i]);
	}
	else {
	  if (o_set.find(A[i]) == o_set.end())
	  {
		stk.push(A[i]);
	  }
	  else {
		char ch[2] = { 0 };
		strcpy_s(ch, A[i].c_str());
		int ind = 0;
		while (!stk.empty())
		{
		  digits[ind] = stoi(stk.top());
		  stk.pop();
		  ind++;
		  if (ind == 2)
		  {
			break;
		  }
		}
		switch (ch[0])
		{
		case '+':
		{
		  if (ind == 2)
		  {
			ans = (digits[1]+ digits[0]);
		  }
		  stk.push(to_string(ans));
		  break;
		}
		case '-':
		{
		  if (ind == 2)
		  {
			ans = (digits[1] - digits[0]);
		  }
		  stk.push(to_string(ans));
		  break;
		}
		case '*':
		{
		  if (ans == 0)
			ans = 1;
		  if (ind == 2)
		  {
			ans = (digits[1] * digits[0]);
		  }
		  stk.push(to_string(ans));
		  break;
		}
		case '/':
		{
		  if (ans == 0)
			ans = 1;
		  if (ind == 2)
		  {
			ans = (digits[1] / digits[0]);
		  }
		  stk.push(to_string(ans));
		  break;
		}
		default:
		  break;
		}
	  }
	}
  }
  if (!stk.empty())
  {
	return stoi(stk.top());
  }
  else {
	return ans;
  }
}

int main()
{
  vector<string> A = { "2", "1", "+", "3", "*" };
  vector<string> B = { "4", "13", "5", "/", "+" };
  vector<string> C = { "5","1","2","+","4","*","+","3","-" };
  vector<string> D = {"5"};

  cout << "Evaluation done: " << evalRPN(A) << endl;
  cout << "Evaluation done: " << evalRPN(B) << endl;
  cout << "Evaluation done: " << evalRPN(C) << endl;
  cout << "Evaluation done: " << evalRPN(D) << endl;
  return 0;
}