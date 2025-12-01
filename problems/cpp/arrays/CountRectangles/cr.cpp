#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int solve(vector<int>& A, int B);
};

int Solution::solve(vector<int>& A, int B) {
  int ans=0;
  int s = 0, e = A.size() - 1;
  while (s < A.size() && e >= 0)
  {
	long long area = A[s] * A[e];
	if (area < B)
	{
	  ans += (1 + e);
	  s++;
	}
	else {
	  e--;
	}
  }
  return ans;
}

int main()
{
  cout << "Area Rectangles\n";
  Solution sol;
  vector<int> A = { 1, 2 };
  vector<int> B = { 1 };
  cout << sol.solve(A, 5) << endl;
  cout << sol.solve(A, 1) << endl;
  cout << sol.solve(B, 1000000000) << endl;
  return 0;
}