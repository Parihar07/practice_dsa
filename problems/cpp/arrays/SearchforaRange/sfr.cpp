#include<iostream>
#include<vector>

using namespace std;
vector<int> searchRange(const vector<int>& A, int B) {
  vector<int> ans;
  int s = 0, e = A.size() - 1, mid = -1;
  int fo = -1, lo =-1;
  while (s <= e)
  {
	mid = (s + e) / 2;
	if (A[mid] == B)
	{
	  fo = mid;
	  e = mid - 1;
	} else 	if (A[mid] < B)
	{
	  s = mid + 1;
	} else
	{
	  e = mid -1;
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
int main()
{
  vector<int> A = { 5, 7, 7, 8, 8, 10 };
  vector<int> B = { 5, 17, 100, 111 };
  cout << "Search range hello\n";

  vector<int> ans = searchRange(A, 8);
  for (auto i = ans.begin(); i != ans.end(); i++)
  {
	cout << *i << " ";
  }
  cout << endl;
  ans = searchRange(B, 3);
  for (auto i = ans.begin(); i != ans.end(); i++)
  {
	cout << *i << " ";
  }
  cout << endl;
  return 0;
}