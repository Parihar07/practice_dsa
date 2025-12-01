#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
  int solve(vector<int>& A, int B);
  int checkFit(vector<int>& A, int B, int r);

};

int Solution::checkFit(vector<int>& A, int B, int r)
{
  int prev = A[0];
  B -= 1;
  for (int i = 1; i < A.size(); i++)
  {
	if (A[i] >= (prev + r))
	{
	  prev = A[i];
	  B--;
	}
  }
  return B == 0 ? 1 : 0;
}

int Solution::solve(vector<int>& A, int B)
{
  //Vector if not sorted
  sort(A.begin(), A.end());
  int s = 1, r = A[A.size() - 1], mid = -1;
  int ans = 0;
  while (s <= r)
  {
	mid = (s + r) / 2;
	if (checkFit(A, B, mid))
	{
	  ans = mid;
	  s = mid + 1;
	}
	else {
	  r = mid - 1;
	}
  }
  return ans;
}

int main()
{
  vector<int> A = { 1, 2, 3, 4, 5 };
  vector<int> B = { 0,1000000000 };
  Solution so;
  cout << "Minimum Disatance cows can be kept away : " << so.solve(A, 3) << endl;
  cout << "Minimum Disatance cows can be kept away : " << so.solve(B, 2) << endl;

  return 0;
}