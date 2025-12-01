#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
  vector<int> solve(int A, vector<int>& B);
};

vector<int> Solution::solve(int A, vector<int>& B) {
  vector<int> ans;
  priority_queue<int> pq;
  for (int i = 0; i < B.size(); i++)
  {
	pq.push(-(B[i]));
	if (pq.size() >= A )
	{
	  ans.push_back(-(pq.top()));
	  pq.pop();
	}
	else {
	  ans.push_back(-1);
	}
  }
  return ans;
}

int main()
{
  Solution sso;
  vector<int> A = { 1,2,3,4,5,6 };
  vector<int> ans = sso.solve(4, A);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  return 0;
}