#include<iostream>
#include<vector>
#include"../common/common.h"
using namespace std;

int solve(vector<int>& A, int B);

//int solve(vector<int>& A, int B) {
//  int ans = 0;
//  int N = A.size();
//  for (int i = 0; i < N; i++)
//  {
//	if (A[i] > B)
//	{
//	  for (int j = i + 1; j < N; j++)
//	  {
//		if (A[j] <= B)
//		{
//		  swap(A[i], A[j]);
//		  ans += 1;
//		  break;
//		}
//	  }
//	}
//  }
//  return ans;
//}
int solve(vector<int>& A, int B) {
  int N = A.size(), cnt = 0, ans=INT_MAX,sc=0;

  for (int i = 0; i < N; i++)
  {
	if (A[i] <= B)
	  cnt += 1;
  }

  for (int i = 0; i < cnt; i++)
  {
	if (A[i] > B)
	  sc += 1;
  }

  for (int i = 1, j = i+cnt-1;  j < N; i++, j++)
  {
	if (A[i - 1] > B)
	  sc -= 1;
	if (A[j] > B)
	  sc += 1;
	ans = _min(ans, sc);
  }
  return (ans == INT_MAX) ? 0 : ans;
}

int main()
{
  vector<int> A = { 1, 12, 10, 3, 14, 10, 5};
  cout << "Max swaps needed : " << solve(A, 8) << endl;
  vector<int> B = {5, 17, 100, 11};
  cout << "Max swaps needed : " << solve(B, 20) << endl;
  vector<int> C = {0};
  cout << "Max swaps needed : " << solve(C, 0) << endl;
  return 0;
}
