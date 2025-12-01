#include<iostream>
#include<vector>

using namespace std;
vector<int> sortColors1(vector<int>& A);
vector<int> sortColors(vector<int>& A);

  vector<int> sortColors1(vector<int>& A) {
  vector<int> ans(A.size(), 0);
  for (int i = 0; i < A.size(); i++)
	ans[i] = A[i];

  for (int i = 0; i < ans.size(); i++)
  {
	for (int j = i + 1; j < ans.size(); j++)
	{
	  if (ans[i] > ans[j]) swap(ans[i], ans[j]);
	}
  }
  return ans;
}

vector<int> sortColors(vector<int>& A) {
  vector<int> ans;
  int z = 0, o = 0, t = 0;
  for (int i = 0; i < A.size(); i++)
  {
	if (A[i] == 0) z++;
	else if (A[i] == 1)o++;
	else t++;
  }
  for (int i = 0; i < z; i++) ans.push_back(0);
  for (int i = 0; i < o; i++) ans.push_back(1);
  for (int i = 0; i < t; i++) ans.push_back(2);
  return ans;
}
int main()
{
  vector<int> A = { 0, 1, 2, 0, 1, 2 };
  vector<int> ans = sortColors(A);
  
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  return 0;
}