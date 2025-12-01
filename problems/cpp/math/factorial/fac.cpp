#include<iostream>

using namespace std;

int solve(int A) {
  if (A == 0)
	return 1;
  return A * solve(A - 1);
}

int main()
{
  cout << "factorila\n";
  cout << solve(4) << endl;
  cout << solve(1)<< endl;
  return 0;
}