#include<iostream>
#include<vector>

using namespace std;

vector<int> solve(const vector<int>& A, const vector<int>& B) {
  int M = A.size();
  int N = B.size();
  int i = 0, j = 0, k = 0;
  vector<int> sa((M + N), 0);
  while (i < M && j < N)
  {
	if (A[i] < B[j])
	{
	  sa[k] = A[i];
	  i++; k++;
	}
	else {
	  sa[k] = B[j];
	  j++; k++;
	}
  }

  while (i < M) {
	sa[k] = A[i];
	i++; k++;
  }
  while (j < N)
  {
	sa[k] = B[j];
	j++; k++;
  }

  return sa;
}


int main()
{
  cout << "hello merging of sorted arrays";
  vector<int> A = { 4, 7, 9 };
  vector<int> B = { 2, 11, 19 };
  vector<int> C = { -5 };

  vector<int> ans = solve(C,C);
 
  for (int i=0; i < ans.size(); i++)
  {
	cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}