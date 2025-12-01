#include<iostream>
#include<vector>

using namespace std;

int fib(int n);
int fibDPHelper(int n, vector<int>& A);
int fibDP(int n);
int fibIt(int n);
int fibItOp(int n);

int fib(int n)
{
  if (n <= 1)return n;
  return fib(n - 1) + fib(n - 2);
}

int fibDPHelper(int n, vector<int>& A)
{
  if (n <= 1) return n;
  if (A[n] == -1)
  {
	A[n] = fibDPHelper(n - 1, A) + fibDPHelper(n - 2, A);
  }
  return A[n];
}

int fibDP(int n)
{
  vector<int> A(n+1, -1);
  return fibDPHelper(n, A);
}

int fibIt(int n) //Iterative Code TC- O(n) and SC - O(n)
{
  int* A = new int[n];
  A[0] = 0; A[1] = 1;
  for (int i = 2; i <= n; i++)
  {
	A[i] = A[i - 1] + A[i - 2];
  }
  return A[n];
}

int fibItOp(int n) //Iterative Code TC- O(n) and SC - O(1)
{
  int a = 0, b = 1, c = 0;
  if (n <= 1)return n;
  for (int i = 2; i <= n; i++)
  {
	c = a + b;
	a = b; b = c;
  }
  return c;
}

int main()
{
  cout << "Fibonacci : " << fibItOp(7) << endl;
  return 0;
}