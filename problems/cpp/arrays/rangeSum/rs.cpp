#include<iostream>
#include<vector>
using namespace std;

vector<long long> rangeSum(vector<int>& A, vector<vector<int> >& B) {
  vector<long long> ans;
  vector<long long> pf(A.size(), 0);
  pf[0] = A[0];
  for (int i = 1; i < A.size(); i++)
  {
	pf[i] = pf[i - 1] + A[i];
  }

  for (int i = 0; i < B.size(); i++)
  {
	int s = 0, e = 0;
	long long sm = 0;

	e = B[i][1];
	s = B[i][0];
	sm = (s == 0) ? pf[e] : pf[e] - pf[s-1];
	ans.push_back(sm);
  }

  return ans;
}

int main()
{
  cout << "Range Sum Problem\n";
  vector<int> A = { 1,2,3,4,5 };
  vector< vector<int>> B = {{0, 3}, { 1,2 }};
  vector<long long> ans = rangeSum(A, B);

  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;

  vector<int> C = { 2,2,2 };
  vector< vector<int>> D = { {0, 0}, { 1,2 } };
  ans = rangeSum(C, D);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  return 0;
}