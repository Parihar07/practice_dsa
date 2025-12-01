#include<iostream>
#include<vector>
using namespace std;

int maxProduct(const vector<int>& A);
int maxProductNaive(const vector<int>& A);
int maxSubarrayProduct(const vector<int>& A);

int maxProduct(const vector<int>& A) {
  vector<int> PS(A.size(), 0);
  PS[0] = A[0];
  int t = A[0];
  int ans = t;

  for (int i = 1; i < A.size(); i++)
  {
	int k = t * A[i];
	if (k >= A[i])
	{
	  t = k;
	  PS[i] = k;
	}
	else {
	  PS[i] = A[i];
	  t = PS[i];
	}
	ans = max(ans, t);    
  }
  return ans;
}
int maxProductNaive(const vector<int>& A)
{
  int ans = A[0];
  for (int i = 0; i < A.size(); i++)
  {
	int res = A[i];
	int p = A[i];
	for (int j = i + 1; j < A.size(); j++)
	{
	  p *= A[j];
	  res = max(res, p);
	}
	ans = max(ans, res);
  }
  return ans;
}

int maxSubarrayProduct(const vector<int>& A)
{
  // max positive product
  // ending at the current position
  int max_ending_here = A[0];

  // min negative product ending
  // at the current position
  int min_ending_here = A[0];

  // Initialize overall max product
  int max_so_far = A[0];
  /* Traverse through the array.
  the maximum product subarray ending at an index
  will be the maximum of the element itself,
  the product of element and max product ending previously
  and the min product ending previously. */
  for (int i = 1; i < A.size(); i++) {
    int temp = max({ 
	  A[i], 
	  A[i] * max_ending_here,
	  A[i] * min_ending_here 
	  });
    min_ending_here = min({ 
	  A[i], 
	  A[i] * max_ending_here,
	  A[i] * min_ending_here 
	  });
    max_ending_here = temp;
    max_so_far = max(max_so_far, max_ending_here);
  }
  return max_so_far;
}
int main()
{
  vector<int> A = { 3,2,4,-2,8,-7,-10,30 }; //, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  cout << "max Product : " << maxSubarrayProduct(A) << endl;
  return 0;
}