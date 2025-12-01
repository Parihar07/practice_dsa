#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
  char ch[2] = { 0 };
  vector<string> s = { "2", "1", "+", "3", "*" };

  for (int i = 0; i < s.size(); i++)
  {
	strcpy_s(ch, s[i].c_str());

	switch (ch[0])
	{
	case '+':
	{
	  cout << "Plus is called\n";
	  break;
	}
	case '-':
	{
	  cout << "Minus is called\n";
	  break;
	}
	case '*':
	{
	  cout << "Multiplication is called\n";
	  break;
	}
	default:
	  break;
	}
  }
  

  return 0;
}