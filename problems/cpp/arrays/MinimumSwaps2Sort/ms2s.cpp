#include<iostream>
#include<vector>
#include"../common/common.h"

using namespace std;

//int solve(vector<int>& A) {
//  int N = A.size(), sc = 0;
//  while (N)
//  {
//	for (int i = 0; i+1 < A.size(); i++)
//	{
//	  if (A[i] > A[i + 1])
//	  {
//		_swap(A[i], A[i + 1]);
//		sc += 1;
//	  }
//	}
//	N -= 1;
//  }
//  return sc;
//}

int solve(vector<int>& A) {
  int ans = 0;
  for (int i = 0; i < A.size(); i++)
  {
	while (A[i] != i)
	{
	  ans += 1;
	  _swap(A[i], A[A[i]] );
	}
  }
  return ans;
}

int main()
{
  cout << "Hello minimal swap to sort\n";
  vector<int> A = {1, 2, 3, 4, 0};
  cout << "Swap count : " << solve(A) << endl;
  vector<int> B = { 2, 0, 1, 3 };
  cout << "Swap count : " << solve(B) << endl;
  vector<int> C = { 0 };
  cout << "Swap count : " << solve(C) << endl;
  return 0;
}