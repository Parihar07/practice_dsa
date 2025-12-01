#include<iostream>
#include<vector>
#include<stack>

using namespace std;
vector<int> nextGreaterBF(vector<int>& A);
vector<int> nextGreater(vector<int>& A);

vector<int> nextGreaterBF(vector<int>& A) {
  vector<int> ans(A.size(), -1);
  int N = A.size();
  for (int i = 0; i < N; i++)
  {
	for (int j = i + 1; j < N; j++)
	{
	  if (A[j] > A[i])
	  {
		ans[i] = A[j];
		break;
	  }
	}
  }
  return ans;
}
vector<int> nextGreater(vector<int>& A)
{
  stack<int> stk;
  vector<int> ans(A.size(), -1);
  int N = A.size();
  for (int i = N - 1; i >= 0; i--)
  {
	while (!stk.empty())
	{
	  if (stk.top()>A[i])
	  {
		ans[i] = stk.top();
		stk.push(A[i]);
		break;
	  }
	  stk.pop();
	}
	if (stk.empty())
	{
	  ans[i] = -1;
	  stk.push(A[i]);
	}
  }
  return ans;
}
int main()
{
  vector<int> A = { 4, 5, 2, 10 };
  
  vector<int> ans = nextGreater(A);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  vector<int> B = { 3, 2, 1 };
  ans = nextGreater(B);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  return 0;
}