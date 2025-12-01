#include<iostream>
#include<string>
#include<queue>

using namespace std;
string reverseStr(string str);
string solve(int A);

string reverseStr(string str)
{
  string ans;
  for (int i = (str.length() - 1); i >= 0; i--)
  {
	ans.push_back(str[i]);
  }
  return ans;
}

string solve(int A) {
  string ans;
  queue<string> Q;
  Q.push("1"); Q.push("2");
  while ((A) > 0)
  {
	ans = Q.front();
	Q.push(ans + "1");
	Q.push(ans + "2");
	Q.pop();
	A--;
  }
  cout << "Answer: " << ans << endl;
  ans = ans + reverseStr(ans);
  return ans;
}

int main()
{
  cout << "hello perfect patterm\n";
  cout<< solve(40);
  return 0;
}