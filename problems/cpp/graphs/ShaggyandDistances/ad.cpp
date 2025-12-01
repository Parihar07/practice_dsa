#include<iostream>
#include<unordered_map>
#include"../common/common.h"
using namespace std;

int solve(vector<int>& A) {
  unordered_map<int, int> umap;
  int ans = INT_MAX;
  for (int i = 0; i < A.size(); i++)
  {
	if (umap.find(A[i]) != umap.end())
	{
	  ans = _min(ans, abs(umap[A[i]] - i));
	}
	umap[A[i]] = i;
  }

  return ans == INT_MAX ? -1 : ans;
}

int main()
{
  vector<int> A = { 7, 1, 3, 4, 1, 7 };
  vector<int> B = { 1, 1 };
  cout << "Minimun distance of Shaggy : " << solve(A) << endl;
  cout << "Minimun distance of Shaggy : " << solve(B)<< endl;
  return 0;
}