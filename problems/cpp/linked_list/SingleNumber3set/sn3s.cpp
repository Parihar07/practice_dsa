#include<iostream>
#include<vector>

using namespace std;

int singleNumber(const vector<int>& A) {
  int ans = 0, bc = 0, N = A.size();
  for (int b = 31; b >= 0; b--)
  {
	bc = 0;
	for (int i = 0; i < N; i++)
	{
	  if (A[i] & (1 << b))
		bc += 1;
	}
	if (bc % 3)
	  ans |= (1 << b);
  }
  return ans;
}

int main()
{
  vector<int> A = { 1, 2, 4, 3, 3, 2, 2, 3, 1, 1 };
  vector<int> B = { 0, 0, 0, 1 };

  cout << "Single Number : " << singleNumber(A) << endl;
  cout << "Single Number : " << singleNumber(B) << endl;
  return 0;
}