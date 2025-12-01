#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<int>& A) {
  sort(A.begin(), A.end());
  int p = 0, q = A[A.size() - 1];

  for (int i = A.size() - 2; i >= 0; i--)
  {
	p = A[i];
	if (p != q)
	  break;
  }
  return p % q;
}


int main()
{
  cout << "Mox mod hello"<<endl;
  vector<int> A = { 1, 2, 44, 3 };
  cout << solve(A) << endl;
  vector<int> B = { 2, 6, 4 };
  cout << solve(B) << endl;
  //1,2,3,3
  vector<int> C = { 1,2,3,3 };
  cout << solve(C) << endl;
  return 0;
}