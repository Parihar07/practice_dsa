#include<iostream>

using namespace std;

int gcd(int A, int B) {
  if (A == 0) return B;
  return gcd((B % A), A);
}

int main()
{
  cout << "Hello GCD\n";
  cout << "gcd of " << gcd(4, 6) << endl;
  return 0;
}