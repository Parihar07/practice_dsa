#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int>& A, int B) {
  int s = 0, e = A.size() - 1, ans = 0, mid = -1;
  while (s <= e)
  {
	mid = (s + e) / 2;
	if (A[mid] == B)
	{
	  return mid;
	}
	else if (A[mid] > B)
	{
	  //ans = mid+1;
	  e = mid - 1;
	}
	else {
	  ans = mid+1;
	  s = mid + 1;
	}
  }
  return ans;
}

int main()
{
  cout << "hello binary serach\n";
  vector<int> A = { 1, 3, 5, 6 };
  vector<int> B = { 1, 4, 9 };

  cout << " key search : " << searchInsert(A, 5) << endl;
  cout << " key search : " << searchInsert(B, 3) << endl;
  return 0;
}