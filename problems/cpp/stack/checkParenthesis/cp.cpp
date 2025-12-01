#include<iostream>
#include<string>
#include<stack>
using namespace std;

int checkParenthesis(string str)
{
  stack<char> st;
  for (int i = 0; i < str.length(); i++)
  {
	char ch = str[i];
	if (st.empty())
	{
	  st.push(ch);
	}
	else
	{
	  char t = st.top();
	  if (ch == '{' || ch == '[' || ch == '(')
	  {
		if (t == '}' || t == ']' || t == ')')
		{
		  st.pop();
		}
		else
		{
		  st.push(ch);
		}
	  }
	  else 
	  {
		if (ch == '}' || ch == ']' || ch == ')')
		{
		  if (t == '{' || t == '[' || t == '(')
		  {
			st.pop();
		  }
		  else
		  {
			st.push(ch);
		  }
		}
	  }
	}
  }
  if (st.empty())
  {
	return 1;
  }
  else
  {
	return 0;
  }
}

int main()
{
  cout << "Hello Parenthesis check stuff\n";
  string s = "{[()()()()()()()()(()()()()()()]}";
  cout << "Checking parenthesis : " << checkParenthesis(s) << endl;
  return 0;
}
