#include<iostream>
#include<vector>

using namespace std;
int check(vector<int>& A, int j, int B);
int solve(vector<int>& A, int B);

int check(vector<int>& A, int j, int B)
{
  for (int i = 0; i < A.size(); i++)
  {
	if (i == j)
	  continue;
	//A[i]+A[j] == B ->> B - A[j] = A[i]
	if ((B - A[j]) == A[i])
	{
	  return 1;
	}
  }
  return 0;
}
int solve(vector<int>& A, int B) {
  for (int i = 0; i < A.size(); i++)
  {
	if (check(A, i, B))
	{
	  return 1;
	}
  }
  return 0;
}

int main()
{
  vector<int> A = { 1,2,3,4 };
  vector<int> B = { 1,2,4 };
  vector<int> C = { 1,2,2 };

  cout << "Goodpair: " << solve(A, 7) << endl;
  cout << "Goodpair: " << solve(B, 4) << endl;
  cout << "Goodpair: " << solve(C, 4) << endl;
  return 0;
}