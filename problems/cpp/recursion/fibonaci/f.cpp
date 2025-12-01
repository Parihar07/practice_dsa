#include<iostream>

using namespace std;

// 0 1 2 3 4 5 6
// 0 1 1 2 3 5 8 

int findAthFibonacci(int A) {
  if (A <= 2)
	return 1;
  return findAthFibonacci(A - 1) + findAthFibonacci(A - 2);
}

int main()
{
  cout << "hello fibo\n";
  cout << findAthFibonacci(1) << endl;
  cout << findAthFibonacci(3) << endl;
  cout << findAthFibonacci(6) << endl;
  return 0;
}