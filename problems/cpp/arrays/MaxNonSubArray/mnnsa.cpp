#include<iostream>
#include<vector>
using namespace std;

vector<int> maxset(vector<int>& A) {
  int l = 0, r = 0, maxi = INT_MIN, sum = 0;
  int s = 0, e = 0;
  vector<int> v;
  for (int i = 0; i < A.size(); i++)
  {
	sum += A[i];
	if (sum < 0)
	{
	  l = r = i;
	  sum = 0;
	}
	else {
	  r = i;
	}
	if (sum > maxi)
	{
	  s = l; e = r;
	  maxi = sum;
	}
  }
  cout << "Maxi: " << maxi << endl;
  if (maxi == 0) return vector<int>();
  v.resize((e - s + 1), 0);
  int j = 0;
  for (int i = s; i <= e; i++)
  {
	v[j] = A[i];
	j++;
  }
  return v;
}

int main()
{
  vector<int> A = { 0,0,-1,0 };
  vector<int> ans = maxset(A);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  return 0;
}