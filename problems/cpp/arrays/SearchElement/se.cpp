#include<iostream>

using namespace std;

int main()
{
  int ele = 0;
  cin >> ele;
  int sze = 0;
  cin >> sze;
  int* A = new int[sze];
  for (int i = 0; i < sze; i++)
  {
	cin >> A[i];
  }

  for (int i = 0; i < sze; i++)
  {
	if (ele == A[i]) return i;
  }

  return 0;
}