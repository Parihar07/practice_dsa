#include<iostream>
#include<vector>
#include"../common/common.h"
using namespace std;
int maxSubArray(const vector<int>& A);
int maxSubArrayOpt(const vector<int>& A);

int maxSubArray(const vector<int>& A) {
  int ans = A[0];
  vector<int> PS(A.size(), 0);
  PS[0] = A[0];
  for (int i = 1; i < A.size(); i++)
  {
	PS[i] = A[i] + PS[i - 1];
  }

  for (int i = 0; i < A.size(); i++)
  {
	cout << PS[i] <<" ";
  }
  cout << endl;

  for (int s = 0; s < A.size(); s++)
  {
	for (int e = s; e < A.size(); e++)
	{
	  if (s == 0)
	  {
		ans = _max(ans, PS[e]);
	  }
	  else 
	  {
		ans = _max(ans, (PS[e] - PS[s-1]));
	  }
	}
  }
  return ans;
}

int maxSubArrayOpt(const vector<int>& A)
{
  int max_sum = INT_MIN;
  int cur_sum = 0;
  for (int i = 0; i < A.size(); i++)
  {
	cur_sum += A[i];
	max_sum = _max(cur_sum, max_sum);
	if (cur_sum < 0)
	  cur_sum = 0;
  }
  return max_sum;
}

int main()
{
  cout << "max sub array\n";
  vector<int> A = { 1, 2, 3, 4, -10 };
  vector<int>B = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  cout << "Max sum sub array : " << maxSubArrayOpt(A) << endl;
  cout << "Max sum sub array : " << maxSubArrayOpt(B) << endl;
  return 0;
}