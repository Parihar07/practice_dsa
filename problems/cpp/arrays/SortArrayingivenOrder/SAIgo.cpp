#include<iostream>
#include<vector>
#include"../common/common.h"
using namespace std;

vector<int> solve(vector<int>& A, vector<int>& B) {
  vector<int> ANS(A.size(), 0);
  for (int i = 0; i < A.size(); i++)
  {
	ANS[i] = A[i];
  }
  int t = 0;
  for (int p = 0; p < B.size(); p++)
  {
	for (int q = 0; q < A.size(); q++)
	{
	  if (B[p] == ANS[q])
	  {
		_swap(ANS[t], ANS[q]);
		t++;
	  }
	}
  }
  int p = A.size() - t;
  while (p)
  {
	for (int i = t; i < A.size()-1; i++)
	{
	  if (ANS[i] > ANS[i + 1])
	  {
		_swap(ANS[i], ANS[i + 1]);
	  }
	}
	p--;
  }
  return ANS;
}


int main()
{
  cout << "Sort in given order\n";
  vector<int> A = { 1, 2, 3, 4, 5, 4 };
  vector<int> B = { 5, 4, 2 };

  vector<int> rs = solve(A, B);
  for (auto a = rs.begin(); a != rs.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  vector<int> C = { 5, 17, 100, 11 };
  vector<int> D = { 1, 100 };
  rs = solve(C, D);
  for (auto a = rs.begin(); a != rs.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  return 0;
}