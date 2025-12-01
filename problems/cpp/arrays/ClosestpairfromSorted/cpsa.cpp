#include<iostream>
#include<vector>

using namespace std;
vector<int> solve(vector<int>& A, vector<int>& B, int C) {
  vector<int> ans(2, 0);
  vector<int> MA(A.size() + B.size(), 0);
  long s = 0, e = 0, k = 0;
  while (s <= e)
  {
	if (A[s] < B[e])
	{
	  MA[k++] = A[s++];
	}
	else {
	  MA[k++] = B[e++];
	}
  }
  while (s < A.size())
  {
	MA[k++] = A[s++];
  }
  while (e < B.size())
  {
	MA[k++] = B[e++];
  }
  
 // for (auto i = MA.begin(); i != MA.end(); i++)
 // {
	//cout << *i << " ";
 // }
 // cout << endl;
  long i = 0, j = MA.size() - 1;

  while (i<j)
  {
	int sum = MA[i] + MA[j];
	if ((sum - C) == 0)
	{
	  ans[0] = MA[i];
	  ans[1] = MA[j];
	  return ans;
	}
	if ((sum - C) < 0)
	{
	  i++;
	}
	else {
	  ans[0] = MA[i];
	  ans[1] = MA[j];
	  j--;
	}
  }
  return ans;
}

int main()
{
  vector<int> A = { 1, 2, 3, 4, 5 };
  vector<int> B = { 2, 4, 6, 8 };  

  vector<int> C = { 5, 10, 20 };
  vector<int> D = { 1, 2, 30 };

  vector<int> E = { 1 };
  vector<int> F = { 1000000000 };

  vector<int> ans;
  cout << "Closet pair sum\n";

  ans = solve(A, B, 9);
  for (auto i = ans.begin(); i != ans.end(); i++)
  {
	cout << *i << " ";
  }
  cout << endl;
  ans = solve(C, D, 13);
  for (auto i = ans.begin(); i != ans.end(); i++)
  {
	cout << *i << " ";
  }
  cout << endl;

  ans = solve(E, F, 1000000000);
  for (auto i = ans.begin(); i != ans.end(); i++)
  {
	cout << *i << " ";
  }
  cout << endl;

  return 0;
}