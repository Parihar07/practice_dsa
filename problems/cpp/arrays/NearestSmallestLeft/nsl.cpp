#include<iostream>
#include<vector>
#include<stack>

using namespace std;
vector<int> prevSmallerBF(vector<int>& A);
vector<int> prevSmaller(vector<int>& A);

vector<int> prevSmallerBF(vector<int>& A) {
  int N = A.size();
  vector<int> ans(A.size(), -1);
  for (int i = N-1; i >=0; i--)
  {
	for (int j=i - 1; j >= 0; j--)
	{
	  if (A[j] < A[i])
	  {
		ans[i] = A[j];
		break;
	  }
	}
  }
  return ans;
}

vector<int> prevSmaller(vector<int>& A)
{
  vector<int> ans(A.size(), -1);
  stack<int> stk;
  for (int i = 0; i < A.size(); i++)
  {
	while (!stk.empty())
	{
	  if (stk.top() < A[i])
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
  vector<int> A = { 4, 5, 2, 10, 8 };
  vector<int> ans = prevSmaller(A);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  return 0;
}