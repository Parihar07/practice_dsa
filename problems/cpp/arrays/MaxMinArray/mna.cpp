#include<iostream>
#include<vector>

using namespace std;

int main()
{
  int sa = 0;
  cin >> sa;
  vector<int> A(sa, 0);
  for (int i = 0; i < sa; i++)
  {
	cin >> A[i];
  }
  int max = A[0], min = A[0];
  for (int i = 0; i < sa; i++)
  {
	if (A[i] > max)
	  max = A[i];
	if (A[i] < min)
	{
	  min = A[i];
	}
  }
  cout << max << " " << min;
  return 0;
}