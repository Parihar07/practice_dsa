#include<iostream>
#include<vector>

using namespace std;
void rotateArray(vector<int>& A, int B)
{
  int ind = 0;
  vector<int> R(A.size(), 0);
  for (int i = 0; i < A.size(); i++)
  {
	ind = (i + B) % A.size();
	R[ind] = A[i];
  }
  for (int i = 0; i < R.size(); i++)
  {
	cout << R[i] << " ";
  }
  return;
}
int main()
{
  int sa = 0;
  cin >> sa;
  vector<int> A(sa, 0);
  for (int i = 0; i < sa; i++)
  {
	cin >> A[i];
  }
  int B = 0;
  cin >> B;

  rotateArray(A, B);
  return 0;
}