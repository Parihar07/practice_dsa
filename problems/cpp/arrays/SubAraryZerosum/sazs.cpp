#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(vector<int>& A) {
  // Just write your code below to complete the function. Required input is available to you as the function arguments.
  // Do not print the result or any output. Just return the result via this function.
  size_t N = A.size();
  int sum = 0;
  unordered_map<int, int> umap;

  for (int i = 0; i < N; i++)
  {
	sum += A[i];
	umap[i] = sum;

	if (umap.find(sum) != umap.end())
	{
	  return 1;
	}
  }
  return 0;
}
int main()
{
  vector<int> A = { 1, 2, 3, 4, 5 };
  vector<int> B = {-1,1 };

  cout << "Zero sum array present: " << solve(A) << endl;
  cout << "Zero sum array present: " << solve(B) << endl;
  return 0;
}