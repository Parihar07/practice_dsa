#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
class Solution {
public:
  vector<int> solve(vector<int>& A);
  vector<int> solve2(vector<int>& A);
};
vector<int> Solution::solve2(vector<int>& A) {
  sort(A.begin(), A.end());
  vector<int> ans, B;
  int ind = 0;

  for (int i = 0; i < A.size(); i++)
  {
	B.push_back(A[i]);
	if (((int)B.size() % 2) == 0)
	{
	  ind = ((int)B.size() / 2) - 1;
	}
	else {
	  ind = ((int)B.size()) / 2;
	}
	ans.push_back(B[ind]);
  }
  return ans;
}

vector<int> Solution::solve(vector<int>& A) {
  priority_queue<int> pqMax;
  priority_queue<int> pqMin;
  vector<int> ans;
  int median = 0;
  pqMax.push(A[0]);

  for (int i = 0; i < A.size(); i++)
  {
	int t = pqMax.top();
	if (t < A[i])
	{

	}
  }
  return ans;
}
int main()
{
  Solution so;
  vector<int> A = { 1, 2, 5, 4, 3 };
  vector<int> ans = so.solve(A);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  return 0;
}