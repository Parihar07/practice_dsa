#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<char> to_lower(vector<char>& A) {
  
  vector<char> ans(A);
  for (int i = 0; i < ans.size(); i++)
  {
	if (ans[i] >= 'A' && ans[i] <= 'Z')
	{
	  ans[i] = (int)ans[i] + 32;
	}
  }
  return ans;
}

int main()
{
  cout << "To lower string \n";
  vector<char> A = { 'S', 'c', 'A', 'l', 'e', 'r', 'A', 'c', 'a', 'D', 'e', 'm', 'y' };
  vector<char> B = { 'S', 'c', 'a', 'L', 'e', 'r', '#', '2', '0', '2', '0' };

  vector<char> ans = to_lower(B);

  for (auto a : ans)
  {
	cout << a << " ";
  }

  cout << endl;
  return 0;
}