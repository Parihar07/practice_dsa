#include<iostream>
#include<vector>

using namespace std;

int majorityElement(const vector<int>& A) {
  int ans = 0;
  for (int i = 0; i < A.size(); i++)
  {
	if (A[i] > (A.size()) / 2)
	{
	  ans = A[i];
	}
  }
  return ans;
}

int main()
{
  vector<int> A = { 2, 1, 2 };
  cout << "Mojoarity element : " << majorityElement(A) << endl;
  return 0;
}