#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> flip(string A) {
  vector<int> ans;
  int l = 0, r = 0, sum = 0, maxi = INT_MIN;
  if (A.length() == 1)
  {
	return ans;
  }
  ans.resize(2, 0);
  for (int i = 0; i < A.length(); i++)
  {
	if (A[i] == '1')
	{
	  sum -= 1;
	}
	else {
	  sum += 1;
	}
	if (sum > maxi)
	{
	  maxi = sum;
	  ans[0] = l + 1;
	  ans[1] = r + 1;
	}

	if (sum < 0)
	{
	  sum = 0;
	  l = 1 + i;
	  r = i+1;
	}
	else {
	  r = i+1;
	}
  }
  if (maxi == 0) return vector<int>();
  return ans;
}


int main()
{
  string str = "11111111";
  vector<int> ans = flip(str);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  return 0;
}