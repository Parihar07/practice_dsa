#include<iostream>
#include<vector>
#include"../common/common.h"
#include<iomanip>
using namespace std;

long solve(vector<vector<int> >& A) {
  int M = (int)A.size(), N = (int)A[0].size();

  vector<vector<int>> PFSM(M, vector<int>(N, 0));

  for (int i = 0; i < M; i++)
  {
	for (int j = 0; j < N; j++)
	{
	  PFSM[i][j] = A[i][j];
	}
  }

  for (int i = 0; i < M; i++)
  {
	for (int j = 1; j < N; j++)
	{
	  PFSM[i][j] = PFSM[i][j - 1] + A[i][j];
	}
  }
  for (int i = 0; i < M; i++)
  {
	for (int j = 1; j < N; j++)
	{
	  PFSM[j][i] = PFSM[j - 1][i] + PFSM[j][i];
	}
  }
  /*
  //This is suffix sum matrix logic
  for (int i = M - 1; i >= 0; i--)
  {
	for (int j = N - 2; j >= 0; j--)
	{
	  PFSM[i][j] += PFSM[i][j + 1];
	}
  }

  for (int i = M - 1; i >= 0; i--)
  {
	for (int j = N - 2; j >= 0; j--)
	{
	  PFSM[j][i] += PFSM[j + 1][i];
	}
  }*/
  int ans = INT_MIN;
 int TR = 0, TC = 0, BR = 0, BC = 0;
  
  for (TR = 0; TR < M; TR++)
  {
	for (TC = 0; TC < N; TC++)
	{

	  for (BR = TR; BR < M; BR++)
	  {
		for (BC = TC; BC < N; BC++)
		{
		  int sum = PFSM[BR][BC];
		  if (TC > 0) sum -= PFSM[BR][TC - 1];
		  if (TR > 0) sum -= PFSM[TR - 1][BC];
		  if (TR > 0 && TC > 0) sum += PFSM[TR - 1][TC - 1];
		  ans = max(sum, ans);
		}
	  }
	}
  }

 /* cout << "[";
  for (int i = TR; i <= BR; i++)
  {
	for (int j = TC; j <= BC; j++)
	{
	  cout << setw(5) << A[i][j];
	}
	cout << endl;
  }
  cout << "]" << endl;*/

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