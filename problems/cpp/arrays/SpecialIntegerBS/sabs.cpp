#include<iostream>
#include<vector>

using namespace std;

int check(vector<int>& A, int k, int B);
int solve(vector<int>& A, int B);

int check(vector<int>& A, int k, int B)
{
  int sum = 0; int flag = 0;
  for (int i = 0; i < k; i++)
  {
	sum += A[i];
  }
  if (sum >= B)
	return false;

  for (int w = k; w < A.size(); w++)
  {
	sum += A[w];
	sum -= A[w - k];
	if (sum >= B)
	{
	  return false;
	}
  }
   return true;
}
int solve(vector<int>& A, int B) {
  for (int k = (A.size()); k >= 0; k--)
  {
	if (check(A, k, B))
	{
	  return k;
	}
  }
  return 0;
}


int main()
{
  vector<int> A = { 1, 2, 3, 4, 5 };
  vector<int> B = { 5, 17, 100, 11 };
  vector<int> C = { 1, 2, 3, 4, 5, 100 };
  cout << "K Value:  " << solve(A, 10) << endl;
  cout << "K Value:  " << solve(B, 130) << endl;
  cout<< "K Value:  "<< solve(C, 10) << endl;

  return 0;
}