#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
  int firstMissingPositive(vector<int>& A);
};

int Solution::firstMissingPositive(vector<int>& A) {
  int N = (int)A.size();
  vector<int> mA(A);
  for (int i = 0; i < N; i++)
  {
	if (A[i] <= 0) A[i] = N + 1;
  }

  for (int i = 0; i < N; i++)
  {
	if (abs(A[i]) <= N)
	{
	  A[abs(A[i]) - 1] = (-1 * (abs(A[abs(A[i]) - 1])));
	}
	  }

  for (int i = 0; i < N; i++)
  {
	if (A[i] > 0) return i + 1;
  }
  return N + 1;
}

int main()
{
  cout << "Finding Missing integer\n";
  vector<int> A = { 417,929,845,462,675,175,73,867,14,201,777,407,80,882,785,563,209,261,776,362,730,74,649,465,353,801,503,154,998,286,520,692,68,805 };
  vector<int> B = { 3,4,-1,1 };
  vector<int> C = { -8,-7,-6 };

  Solution so;
  cout << " Missing : " << so.firstMissingPositive(A) << endl;
  cout << " Missing : " << so.firstMissingPositive(B) << endl;
  cout << " Missing : " << so.firstMissingPositive(C) << endl;

  return 0;
}