#include<iostream>
#include<vector>

using namespace std;

int singleNumber(const vector<int>& A) {
  int ans = 0, N = A.size();
  for (int i = 0; i < N; i++)
  {
	ans ^= A[i];
  }
  return ans;
}

int main()
{
  vector<int> A = { 1, 2, 2, 3, 1 };
  cout << "Single NUmber : " << singleNumber(A);
  return 0;
}