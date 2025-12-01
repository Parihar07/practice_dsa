#include<iostream>
#include<vector>

using namespace std;
int getFirstSetBit(int A)
{
  for (int b = 30; b >= 0; b--)
  {
	if (A & (1 << b))
	  return b;
  }

}

vector<int> solve(vector<int>& A) {
  vector<int> ans(2, 0);
  int b = 0;
  for (int i = 0; i < A.size(); i++)
  {
	b ^= A[i];
  }
  b = getFirstSetBit(b);

  for (int i = 0; i < A.size(); i++)
  {
	if (A[i] & (1 << b))
	  ans[1] ^= A[i];
	else
	  ans[0] ^= A[i];
  }

  return ans;
}

int main()
{
  vector<int> A = { 1, 2, 3, 1, 2, 4 };
  vector<int> B = { 1, 2 };
  vector<int> ans = solve(A);
  for (int i = 0; i < ans.size(); i++)
  {
	cout << ans[i] << " ";
  }
  cout << endl;

  ans = solve(B);
  for (int i = 0; i < ans.size(); i++)
  {
	cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}