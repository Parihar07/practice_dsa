#include<iostream>
#include<vector>
#include<stack>
#include"../common/common.h"

using namespace std;
int solveBF(vector<int>& A);
int solveBF2(vector<int>& A);
int solve(vector<int>& A);
vector<int> createNGL(vector<int> A);
vector<int> createNGR(vector<int> A);
vector<int> createNSL(vector<int> A);
vector<int> createNSR(vector<int> A);

int solveBF(vector<int>& A) {  // Time Complexity O(n^3)
  int N = A.size();
  int maxi = 0, mini = 0;
  long ans = 0;
  int mod = 1000000007;
  for (int s = 0; s < N; s++)
  {
	for (int e = s; e < N; e++)
	{
	  maxi = INT_MIN; mini = INT_MAX;
	  for (int i = s; i <= e; i++)
	  {
		maxi = _max(maxi, A[i]);
		mini = _min(mini, A[i]);
	  }
	  ans += (maxi - mini);
	}
  }
  return ans % mod;
}

int solveBF2(vector<int>& A) //Time Complexity O(N^2)
{
  int N = A.size();
  int maxi = 0, mini = 0;
  long ans = 0;
  int mod = 1000000007;
  for (int s = 0; s < N; s++)
  {
	maxi = INT_MIN; mini = INT_MAX;
	for (int e = s; e < N; e++)
	{
	  maxi = _max(maxi, A[e]);
	  mini = _min(mini, A[e]);
	  ans += (maxi - mini);
	}
  }
  return ans % mod;
}
vector<int> createNGR(vector<int> A)
{
  vector<int>ngr(A.size(), -1);
  stack<int> stk;
  for (int i = (A.size() - 1); i >= 0; i--)
  {
	while (!stk.empty())
	{
	  if (A[stk.top()] > A[i])
	  {
		ngr[i] = stk.top();
		stk.push(i);
		break;
	  }
	  stk.pop();
	}
	if (stk.empty())
	{
	  ngr[i] = -1;
	  stk.push(i);
	}
  }
  return ngr;
}
vector<int> createNGL(vector<int> A)
{
  vector<int>ngl(A.size(), -1);
  stack<int> stk;
  for (int i = 0; i < A.size(); i++)
  {
	while (!stk.empty())
	{
	  if (A[stk.top()] > A[i])
	  {
		ngl[i] = stk.top();
		stk.push(i);
		break;
	  }
	  stk.pop();
	}
	if (stk.empty())
	{
	  ngl[i] = -1;
	  stk.push(i);
	}
  }

  return ngl;
}
vector<int> createNSL(vector<int> A)
{
  vector<int>nsl(A.size(), -1);
  stack<int> stk;
  for (int i = 0; i < A.size(); i++)
  {
	while (!stk.empty())
	{
	  if (A[stk.top()] < A[i])
	  {
		nsl[i] = stk.top();
		stk.push(i);
		break;
	  }
	  stk.pop();
	}
	if (stk.empty())
	{
	  nsl[i] = -1;
	  stk.push(i);
	}
  }

  return nsl;
}
vector<int> createNSR(vector<int> A)
{
  vector<int>nsr(A.size(), -1);
  stack<int> stk;
  for (int i = (A.size() - 1); i >= 0; i--)
  {
	while (!stk.empty())
	{
	  if (A[stk.top()] < A[i])
	  {
		nsr[i] = stk.top();
		stk.push(i);
		break;
	  }
	  stk.pop();
	}
	if (stk.empty())
	{
	  nsr[i] = -1;
	  stk.push(i);
	}
  }
  return nsr;
}

int solve(vector<int>& A)
{
  int ans = 0;
  int maxi = INT_MIN, mini = INT_MAX;
  vector<int> NGL = createNGL(A);
  for (auto a = NGL.begin(); a != NGL.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  vector<int> NGR = createNGR(A);
  for (auto a = NGR.begin(); a != NGR.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  vector<int> NSL = createNSL(A);
  for (auto a = NSL.begin(); a != NSL.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;

  vector<int> NSR = createNSR(A);
  for (auto a = NSR.begin(); a != NSR.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;


  for (int i = 0; i < A.size(); i++)
  {
	maxi = A[i] * (i - NGL[i]) * (NGR[i] - i);
	mini = A[i] * (i - NSL[i]) * (NSR[i] - i);
	ans += (maxi - mini);
  }
  return ans;
}

int main()
{
  vector<int> A = { 7,1,3,6,4,5 };
  cout << solve(A) << endl;
  return 0;
}