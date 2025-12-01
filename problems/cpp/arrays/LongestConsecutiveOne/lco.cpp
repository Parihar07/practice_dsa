#include<iostream>
#include<string>

using namespace std;
int solve(string A);
int solve(string A)
{
  int* li = new int[A.length()];
  int* ri = new int[A.length()];
  memset(li, 0, A.length());
  memset(ri, 0, A.length());
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < A.length(); i++)
  {
	if (A[i] == '1')
	  cnt += 1;
	else
	  cnt = 0;
	li[i] = cnt;
  }
  cnt = 0;
  for (int i = (int)A.length() - 1; i >= 0; i--)
  {
	if (A[i] == '1')
	  cnt += 1;
	else
	  cnt = 0;
	ri[i] = cnt;
  }
  cnt = 0; int len = (int)A.length();

  if (len == 1)
  {
	ans = 1;
  }
  else {
	for (int i = 0; i < len - 1; i++)
	{
	  if (i == 0&&A[i]=='0')
	  {
		cnt = ri[i + 1];
	  }
	  else if (li[i - 1] && ri[i + 1])
	  {
		cnt = li[i - 1] + ri[i + 1] + 1;
	  }
	  else if (li[i - 1] == 0 || ri[i + 1] == 0)
	  {
		cnt = ri[i + 1] + li[i - 1] +1;
	  }
	  ans = max(cnt, ans);
	}
  }

  int total = 0;
  for (int i = 0; i < len; i++) {
	if (A[i] == '1') 
	{
	  total++;
	}
  }

  if (ans > total) {
	return total;
  }
  else
	return ans;
}
int solveFailed(string A)
{
  int F = 0, ans = 0, cnt = 0;
  for (int i = 0; i < A.length(); i++)
  {
	//cnt++;
	char ch = A[i];
	if (ch == '0')
	{
	  if (F == 0)
	  {
		F = cnt;
	  }
	  else {
		ans = max(ans, cnt + 1);
		cnt -= F;
		F = cnt;
	  }
	}
	else {
	  cnt++;
	}
  }
  return ans;
}

int main()
{
  cout << "hello Longest Conseutive string\n";

  string A = "110011001010111001111111000101001011111";
  cout << "Longest consecutive: " << solve(A) << endl;
  return 0;
}