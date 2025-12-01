#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
  int solve(vector<vector<int> >& A, int B);
};
int Solution::solve(vector<vector<int> >& A, int B) {
  int ans = INT_MAX;
  for (int i = 0; i < A.size(); i++)
  {
	for (int j = 0; j < A[0].size(); j++)
	{
	  if (B == A[i][j])
	  {
		ans = min(ans, ((i + 1) * 1009 + (j + 1)));
	  }
	}
  }
  return ans==INT_MAX?-1:ans;
}
int main()
{
  cout << "Earching value in sorted matric\n";
  vector<vector<int>> A = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
  Solution so;
  cout << so.solve(A, 2) << endl;
  return 0;
}