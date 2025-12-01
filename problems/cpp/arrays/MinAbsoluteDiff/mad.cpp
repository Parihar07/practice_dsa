#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int maxArr(vector<int>& A);
  int maxArrBF(vector<int>& A);
  int f(vector<int>& A, int i, int j);
};
int Solution::maxArrBF(vector<int>& A) {
  int N = (int)A.size();
  int ans = INT_MIN;
  for (int i = 0; i < N; i++)
  {
	for (int j = i; j < N; j++)
	{
	  ans = max(ans, f(A, i, j));
	}
  }
  return ans;
}
int Solution::maxArr(vector<int>& A) {
  int mx1 = INT_MIN, mx2 = INT_MIN;
  int mn1 = INT_MAX, mn2 = INT_MAX;
  for(int i=0;i<A.size();i++)
  {
	mx1 = max(mx1, (A[i] + i));
	mx2 = max(mx2, (A[i] - i));

	mn1 = min(mn1, (A[i] + i));
	mn2 = min(mn2, (A[i] - i));
  }
  return max(mx1 - mn1, mx2 - mn2);
}

int Solution::f(vector<int> &A, int i, int j)
{
  return (abs(A[i] - A[j]) + abs(i - j));
}

int main()
{
  cout << "Maximum Absolute Difference \n";
  Solution so;
  vector<int> A = { 1,3,-1 };
  vector<int> B = { 2 };
  cout << so.maxArr(A);
  cout << so.maxArr(B);
  return 0;
}