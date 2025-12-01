#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& A, int B) {
  long ans = 0;
  vector<int> ps(A.size(), 0);
  ps[0] = A[0];
  for (int i = 1; i < A.size(); i++)
  {
	ps[i] = A[i] + ps[i - 1];
  }
  for (int s = 0; s < A.size(); s++)
  {
	for (int e = s; e < A.size(); e++)
	{
	  if (!((e - s + 1) % 2))
	  {
		if (s == 0)
		{
		  if ((ps[e]) < B) {
			ans++;
		  } 
		}
		else {
		  if ((ps[e] - ps[s - 1]) < B) {
			ans++;
		  }
		}
	  }
	  else {
		if (s == 0)
		{
		  if ((ps[e]) > B) {
			ans++;
		  }
		}
		else {
		  if ((ps[e] - ps[s - 1]) > B) {
			ans++;
		  }
		}
	  }
	}
  }
  return ans;
}

int main()
{
  vector<int> A = { 1, 2, 3, 4, 5 };
  vector<int> B = { 13, 16, 16, 15, 9, 16, 2, 7, 6, 17, 3, 9 };
  cout << "Hello good arrays\n";
  cout << "Good sub arrays : " << solve(A, 4) << endl;
  cout << "Good sub arrays : " << solve(B,65) << endl;
  return 0;
}