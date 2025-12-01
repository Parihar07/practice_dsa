#include<iostream>
#include<vector>
#include"../common/common.h"
using namespace std;

int maxSubArray(const vector<int>& A);
int maxSubArrayOpt(const vector<int>& A);

/*
* Return an integer representing the maximum possible sum of the contiguous subarray.
* Explanatins: The subarray [1, 2, 3, 4] has the maximum possible sum of 10. 
*/
int maxSubArray(const vector<int>& A) {
  vector <int> PS = A, SS = A;
  int ans = 0;
  PS[0] = A[0];
  for (int i = 1; i < A.size(); i++)
  {
	PS[i] = PS[i - 1] + A[i];
  }

  int n = A.size();
  SS[n-1] = A[n-1];
  for (int i = n - 2; i >= 0; i--)
  {
	SS[i] = SS[i + 1] + A[i];
  }

  for (int i=0; i < A.size(); i++)
  {
	ans = max(PS[i], SS[i]);
  }

  return ans;
}

int maxSubArrayOpt(const vector<int>& A)
{
  int curr = 0;
  int ans = INT_MIN;
  for(int i=0;i<A.size();i++)
  {
	curr += A[i];
	ans = _max(ans, curr);
	if (curr < 0)  /////Kadence algorithm
	  curr = 0;
  }
  return ans;
}

int main()
{
  cout << "MaxSumArray" << endl;
  vector <int>A = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  vector <int>B = { 1,2,3,4,-10 };

  cout << "Max Sub array 1 " << maxSubArrayOpt(A)<<endl;
  cout << "Max Sub array 2 " << maxSubArrayOpt(B)<<endl;
  return 0;
}