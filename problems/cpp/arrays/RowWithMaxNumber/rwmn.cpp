#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  int solve(vector<vector<int> >& A);
};

int Solution::solve(vector<vector<int> >& A) 
{
  int ind = 0;
  int cnt = 0;
  int ans = 0;
  for (int i = (int)A.size() - 1; i >= 0; i--)
  {
	for (int j = (int)A[0].size() - 1; j >= 0; j--)
	{
	  if (A[i][j] == 1)
	  {
		cnt++;
	  }
	}
	if (cnt >= ans)
	{
	  ind = i;
	  ans = cnt;
	}
	cnt = 0;
  }
  return ind;
}


int main()
{
  vector<vector<int>> A = { {0, 1, 1},{0, 0, 1},{0, 1, 1} };
  vector<vector<int>> B = { {0, 0, 0, 0},{0, 0, 0, 1},{0, 0, 1, 1},{0, 1, 1, 1} };

  Solution so;
  cout << "Lowest Row : " << so.solve(A) << endl;
  cout << "Lowest Row : " << so.solve(B) << endl;
  return 0;
}