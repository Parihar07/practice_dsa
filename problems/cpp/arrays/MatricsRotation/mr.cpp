#include<iostream>
#include<vector>
#include"../common/common.h"

using namespace std;

void solve(vector<vector<int> >& A) {
  for (int r = 0; r < A[0].size(); r++)
  {
	for (int c = r+1; c < A.size(); c++)
	{
	  _swap(A[r][c], A[c][r]);
	}
  }

  for (int r = 0; r < A[0].size(); r++)
  {
	for (int c = 0; c < (A.size() / 2) ; c++)
	{
	  _swap(A[r][c], A[r][(A.size() - 1)-c]);
	}
  }

  for (int r = 0; r < A[0].size(); r++)
  {
	for (int c = 0; c < A.size(); c++)
	{
	  cout << A[r][c] << " ";
	}
	cout << endl;
  }
}

int main()
{
  vector<vector<int>> A = { {1,2,3},{4,5,6},{7,8,9} };
  solve(A);
  return 0;
}