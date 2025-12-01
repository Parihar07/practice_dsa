#include<iostream>
#include<vector>
#include"../common/common.h"

using namespace std;
int getFactorCount(int i);
vector<int> solve(vector<int>& A);
int getDivisors(int A);

int getFactorCount(int A)
{
  int ans = 0;
  for (int i = 1; i * i <= A; i++)
  {
	if (A % i == 0)
	{
	  if (i * i == A)
		ans += 1;
	  else
		ans += 2;
	}
  }
  return ans;
}

int getDivisors(int N)
{

  //Create array of smallest prime factor array
  vector<int> spf(50, 0);
  for (int i = 2; i < spf.size(); i++)
  {
	spf[i] = i;
  }

  //filling the spf array with smallest prime factor 
  for (int i = 2; i * i < spf.size(); i++)
  {
	for (int j = i * i; j < spf.size(); j += i)
	{
	  if ((spf[j] % i) == 0)
	  {
		spf[j] = i;
	  }
	}
  }

  int ans = 1;
  while (N > 1)
  {
	int cnt = 0;
	int x = spf[N];
	while (!(N % x))
	{
	  cnt++;
	  N /= x;
	}
	ans *= (cnt + 1);
  }
  return ans;
}


vector<int> solve(vector<int>& A) {

  vector<int> div(A.size(), 0);

  for (int i = 0; i < A.size(); i++)
  {
	div[i] = getDivisors(A[i]);
  }
  return div;
}

int main()
{
  cout << "Hello divisors\n";
  vector<int> Divisors;
  vector<int> A = { 2, 3, 4, 5 };

  vector<int> B = { 8,9,10 };

  Divisors = solve(A);

  for (int i = 0; i < Divisors.size(); i++)
  {
	cout << Divisors[i] << " ";
  }
  cout << endl;

  Divisors = solve(B);

  for (int i = 0; i < Divisors.size(); i++)
  {
	cout << Divisors[i] << " ";
  }
  cout << endl;

  return 0;
}