#include<iostream>
#include<vector>
#include"../common/common.h"
using namespace std;

int solve(vector<vector<int> >& A, int B) {

  int M = A.size(), N = A[0].size();
  int mSum = INT_MIN;
  vector<vector<int>> psm(M, vector<int>(N, 0));
  for (int r = 0; r < M; r++)
  {
	for (int c = 0; c < N; c++)
	{
	  psm[r][c] = A[r][c];
	}
  }

  //Row wise prefix sum matrix 
  for (int r = 0; r < M; r++)
  {
	for (int c = 1; c < N; c++)
	{
	  psm[r][c] += psm[r][c - 1];
	}
  }
  //Column wise prefix sum matrix
  for (int c = 0; c < N; c++)
  {
	for (int r = 1; r < M; r++)
	{
	  psm[r][c] += psm[r - 1][c];
	}
  }

  for (int r = 0; r < M; r++)
  {
	for (int c = 0; c < N; c++)
	{
	  cout << psm[r][c] <<" ";
	}
	cout << endl;
  }


  //Iterating through all sub matric of size B
  int TR = 0, TC = 0, BR = 0, BC = 0;
  for (int r = 0; r <= M - B; r++)
  {
	for (int c = 0; c <= N - B; c++)
	{
	  TR = r;
	  TC = c;
	  BR = TR + B - 1;
	  BC = TC + B - 1;

	  if (r == 0 && c == 0)
	  {
		mSum = _max(mSum, psm[BR][BC]);
	  }
	  else if (r == 0)
	  {
		mSum = _max(mSum, (psm[BR][BC] - psm[BR][TC - 1]));
	  }
	  else if (c == 0)
	  {
		mSum = _max(mSum, (psm[BR][BC] - psm[TR - 1][BC]));
	  }
	  else {
		mSum = _max(mSum, (psm[BR][BC] - psm[BR][TC - 1] - psm[TR - 1][BC] - psm[TR - 1][TC - 1]));
	  }
	}
  }
  return mSum;
}


int main()
{
  cout << "Maximum Sum Square SubMatrix\n";
  vector<vector<int>> A = {
	{1, 1, 1, 1, 1},
	{2, 2, 2, 2, 2},
	{3, 8, 6, 7, 3},
	{4, 4, 4, 4, 4},
	{5, 5, 5, 5, 5}
  };

  vector<vector<int>> C = {
	{-33, 34, 0, 69, 24, -22},
	{58, 62, -36, 5, 45, -19},
	{-73, 61, -9, 95, 42, -73},
	{-64, 91, -96, 2, 53, -8},
	{82, -79, 16, 18, -5, -53},
	{26, 71, 38, -31, 12, -33}
  };

  vector<vector<int>> B = {
	{2, 2},
	{2, 2}
  };
  cout << "Maximum Square Matrix : " << solve(A, 3) <<endl;
  cout << "Maximum Square MatrixB : " << solve(B, 2)<<endl;
  cout << "Maximum Square MatrixC : " << solve(C, 2)<<endl;
  return 0;
}