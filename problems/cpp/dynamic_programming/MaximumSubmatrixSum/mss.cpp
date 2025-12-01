#include<iostream>
#include<vector>
#include"../common/common.h"

using namespace std;

long kadane(vector<int> arr);
long solveNaive(vector<vector<int> >& A) {
  long mSum = INT_MIN;
  int M = A.size(), N = A[0].size();

  vector<vector<int>> sam(M, vector<int>(N, 0));

  for (int i = 0; i < M; i++)
  {
	for (int j = 0; j < N; j++)
	{
	  sam[i][j] = A[i][j];
	}
  }

  for (int i = M-1; i >= 0; i--)
  {
	for (int j = N-2; j >=0; j--)
	{
	  sam[i][j] += sam[i][j+1];
	}
  }

  for (int i = M - 1; i >= 0; i--)
  {
	for (int j = N - 2; j >= 0; j--)
	{
	  sam[j][i] += sam[j + 1][i];
	}
  }

  for (int i = 0; i < M; i++)
  {
	for (int j = 0; j < N; j++)
	{
	  cout << sam[i][j]<< " ";
	}
	cout << endl;
  }

  for (int i = 0; i < M; i++)
  {
	for (int j = 0; j < N; j++)
	{
	  mSum = max((int)mSum, sam[i][j]);
	}
  }

  return mSum;
}

long kadane(vector<int> arr)
{
  int ans = arr[0];
  int curr = 0;
  for (int i = 0; i < arr.size(); i++)
  {
	curr += arr[i];
	ans = max(curr, ans);
	if (curr < 0) curr = 0;
  }
  return ans;
}
long solve(vector<vector<int> >& A)
{
  long ans = A[0][0];
  int N = (int)A.size(), M = (int)A[0].size();
  for(int sr=0;sr<N;sr++)
  {
	vector<int> arr(M, 0);
	for (int r = 0; r < N; r++)
	{
	  for (int i = 0; i < M; i++)
	  {
		arr[i] += A[r][i];
	  }
	  ans = max(ans, kadane(arr));
	}
  }
  return ans;
}
int main()
{
  vector<vector<int>> A = { {-5, -4, -3 }, { -1,  2,  3 }, {2,2,4} };
  vector<vector<int>> B = { {1, 2, 3 }, {4, 5, 6}, {7, 8, 9} };
  cout << "Max Sum: " << solve(A) << endl;
  cout << "Max Sum2: " << solve(B) << endl;
  return 0;
}