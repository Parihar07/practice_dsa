#include<iostream>
#include<vector>
#include"../common/common.h"

using namespace std;
vector<int> solve(const vector<int>& A) {
  int i = 0, j = A.size() - 1;
  vector<int> ans(A.size(), 0);
  for (int i = 0; i < A.size(); i++)
  {
	ans[i] = A[i];
  }
  while (i <= j)
  {
	_swap(ans[i], ans[j]);
	i++; j--;
  }
  return ans;
}
int main()
{
  vector<int> A = { 1,2,3,4,5,6 };
  vector<int> B = { 1,2,3,2,1 };
  vector<int> C = { 1,2 };
  vector<int> ans = solve(A);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  ans = solve(B);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  ans = solve(C);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  return 0;
}