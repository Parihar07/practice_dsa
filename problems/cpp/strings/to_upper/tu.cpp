#include<iostream>
#include<vector>

using namespace std;

vector<char> to_upper(vector<char>& A) {
  vector<char> ans(A);
  for (int i = 0; i < A.size(); i++)
  {
	if (ans[i] >= 'a' && ans[i] <= 'z')
	{
	  ans[i] = ans[i] - 32;
	}
  }
  return ans;
}


int main()
{
  cout << "To Upper string \n";
  vector<char> A = { 'S', 'c', 'A', 'l', 'e', 'r', 'A', 'c', 'a', 'D', 'e', 'm', 'y' };
  vector<char> B = { 'S', 'c', 'a', 'L', 'e', 'r', '#', '2', '0', '2', '0' };

  vector<char> ans = to_upper(B);

  for (auto a : ans)
  {
	cout << a << " ";
  }

  cout << endl;
  return 0;
  return 0;
}