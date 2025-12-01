#include<iostream>
#include<vector>

using namespace std;
vector<int> searchRange(const vector<int>& A, int B);
int solve(vector<int>& A);

vector<int> searchRange(const vector<int>& A, int B) {
  vector<int> ans;
  int s = 0, e = A.size() - 1, mid = -1;
  int fo = -1, lo = -1;
  while (s <= e)
  {
	mid = (s + e) / 2;
	if (A[mid] == B)
	{
	  fo = mid;
	  e = mid - 1;
	}
	else 	if (A[mid] < B)
	{
	  s = mid + 1;
	}
	else
	{
	  e = mid - 1;
	}

  }
  ans.push_back(fo);
  s = 0, e = A.size() - 1, mid = -1;
  while (s <= e)
  {
	mid = (s + e) / 2;
	if (A[mid] == B)
	{
	  lo = mid;
	  s = mid + 1;
	}
	else if (A[mid] < B)
	{
	  s = mid + 1;
	}
	else
	{
	  e = mid - 1;
	}

  }
  ans.push_back(lo);

  return ans;
}

int solve(vector<int>& A)
{
  vector<int> ans;
  int i = 0;
  for ( i = 0; i < A.size(); i++)
  {
	ans = searchRange(A, A[i]);
	if (ans[0] == ans[1])
	  return A[i];
  } 
  return -1;
}

int main()
{
  vector<int> A = { 1, 1, 7 };

  cout << "Single ellemt : " << solve(A) << endl;
  return 0;
}