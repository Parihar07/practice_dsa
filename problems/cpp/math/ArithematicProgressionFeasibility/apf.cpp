#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& A) {
  /*for (int i = 0; i < A.size(); i++)
  {
	for (int j = i + 1; j < A.size(); j++)
	{
	  if (A[i] > A[j]) swap(A[i], A[j]);
	}
  }*/
  sort(A.begin(), A.end());
  int d = A[1] - A[0];
  for (int i = 0; i < A.size()-1; i++)
  {
	if (d != A[i + 1] - A[i]) return 0;
  }
  return 1;
}

int main()
{
  cout << "Checking if array can be arthimatic progression\n";
  vector<int> A = { 3, 5, 1 };

  cout << "Is Ap : " << solve(A) << endl;
  return 0;
}