#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<int>& A) {

  sort(A.begin(), A.end());

  int p = A[0];

  for (int i = 1; i < A.size(); i++)
  { 
	if (p+1 != A[i]) {
	  return 0;
	}
	p = A[i];
  }
  return 1;
}
int main()
{
  cout << "Consecutive Elements\n";
  vector<int> A = { 3, 2, 6, 4, 5 };
  vector<int> B = { 1, 3, 2, 5 };

  cout << "result : " << solve(A) << endl;
  cout << "result : " << solve(B) << endl;
  return 0;
}