#include<iostream>
#include<string>

using namespace std;

void revWord(string &str, int s, int e);
void revWord(string &str, int s, int e)
{
  while (s < e)
  {
	swap(str[s], str[e]);
	s++, e--;
  }
  return;
}

string solve(string A) {
  string ans(A);
  cout << ans << endl;

  int s = 0, e = (int)ans.length() - 1;
  revWord(ans, s, e);

  cout << ans << endl;

  for (int i = 0; i < ans.length(); i++)
  {
	if (i == 0 || ans[i] == ' ' || i == ans.length()-1)
	{
	  if (i == 0)
	  {
		s = 0;
		continue;
	  }
	  if (i == ans.length() - 1)
		e = i+1;
	  else
		e = i;
	  revWord(ans, s, e-1);
	  s = e+1;
	}
  }

  cout << ans << endl;
  return ans;
}

int main()
{
  cout << "Reversing string\n";
  string str = "e jrkeymu coklj si vohl slje sxtpf xvak p kicqxoqaof uqwftidoi xixfvqbjey n tpkh ylqllzln ljo gvozwv";
  solve(str);
  return 0;
}