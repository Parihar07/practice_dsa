#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& A) {
  long ans = 0;
  int mod = 1000000007;
  for (int i = 0; i < A.size(); i++)
  {
	for (int j = i + 1; j < A.size(); j++)
	{
	  if (A[i] > A[j])
	  {
		ans++;
	  }
	}
  }
  return ans%mod ;
}

int main()
{
  cout << "heelo inversion sum pairs\n";
  vector<int> A = { 1, 3, 2 };
  cout << "Inversion sum pair : " << solve(A) << endl;
  vector<int> B = { 3, 4, 1, 2 };
  cout << "Inversion sum pair : " << solve(B) << endl;
  return 0;
}