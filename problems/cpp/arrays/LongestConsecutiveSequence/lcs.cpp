#include<iostream>
#include<vector>
#include<unordered_set>

#include"../common/common.h"

using namespace std;
int longestConsecutiveBF(const vector<int>& A);
int longestConsecutive(const vector<int>& A);
int longestConsecutiveBF(const vector<int>& A) {

  size_t N = A.size();
  int nxt = 0, cnt = 1, ans=0;
  for (int i = 0; i < N; i++)
  {
	cnt = 1;
	nxt = A[i] + 1;
	for (int j = 0; j < N; j++) {
	  if (A[j] == nxt) {
		cnt++;
		nxt = A[j] + 1;
		j = -1;
	  }
	}
	ans = _max(cnt, ans);
  }
  return ans;
}
int longestConsecutive(const vector<int>& A)
{
  unordered_set<int> uset;
  size_t N = A.size();
  int ans = 0, cnt = 1, nxt=0;
  
  for (int i = 0; i < N; i++)
  {
	uset.insert(A[i]);
  }
  for (int i = 0; i < N; i++)
  {
	nxt = A[i];
	cnt = 0;
	if (uset.find(nxt-1) == uset.end())
	{
	  while (uset.find(nxt) != uset.end())
	  {
		cnt++;
		nxt = nxt + 1;
	  }
	}
	ans = _max(cnt, ans);
  }
  return ans;
}
int main()
{
  vector<int> A = { 100, 4, 200, 1, 3, 2 };
  vector<int> B = { 6,4,5,2,3 };
  cout << "Longest Sequence : " << longestConsecutive(A) << endl;
  cout << "Longest Sequence : " << longestConsecutive(B) << endl;

  return 0;
}