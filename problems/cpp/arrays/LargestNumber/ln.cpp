#include<iostream>
#include<vector>
#include"../common/common.h"
using namespace std;
vector<int> getDigitVector(int N);

vector<int> getDigitVector(int N)
{
  vector<int> ans;
  int t = 0;
  while (N)
  {
	t = N % 10;
	ans.push_back(t);
	N /= 10;
  }
 // for (int i = 0; i < ans.size(); i++)
 // {
	//cout << ans[i] << " ";
 // }
 // cout << endl;
  return ans;
}

string largestNumber(const vector<int>& A) {
 int ind = 0;
  vector<int> fa = A;
  vector<int> s,n;
  string str;
  for (int i = 0; i < A.size(); i++)
  {
	s = getDigitVector(fa[i]);
	for (int j = i+1; j < A.size(); j++)
	{
	  n = getDigitVector(fa[j]);
	  if (s<n) {
		ind = j;
		s = n;
	  }
	}
	_swap(fa[i], fa[ind]);
  }
  
  for (int i = 0; i < fa.size(); i++)
  {
	cout << fa[i] << " ";
  }
  cout << endl;
  return str;
}
int main()
{
  vector<int> A = { 3, 30, 34, 5, 9 };
  cout << "Largest Number\n";
  getDigitVector(987652);
  return 0;
}