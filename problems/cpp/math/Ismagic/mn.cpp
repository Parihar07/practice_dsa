#include<iostream>

using namespace std;
int sumofdigits(int N);
int isMagicNo(int N);

int isMagicNo(int N)
{
  int ans = sumofdigits(N);
  if (ans % 10 == ans)
  {
	return ans == 1 ? 1 : 0;
  } else {
	return isMagicNo(ans);
  }

}
int sumofdigits(int N)
{
  int ans = 0;
  if (N % 10 == N)
  {
	return N;
  }
  ans += N % 10;

  return ans + sumofdigits(N / 10);
}


int main()
{

  cout << "hello Magic Numner\n";

  cout << "Sum of digits : " << isMagicNo(83557) << endl;

  return 0;
}