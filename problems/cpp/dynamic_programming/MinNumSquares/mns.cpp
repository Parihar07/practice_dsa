#include<iostream>
using namespace std;
int nearestSquare(int A);
int setBits(int A);
int minNumSquares(int A);
int minNumSquares2(int A);
int minNumSquaresDP(int A);


int setBits(int A) //Failed for condition 41
{
  int ans = 0;
  for (int i = 0; i < 32; i++)
  {
	if (A & (1 << i)) ans++;
  }
  return ans;
}

int nearestSquare(int A)
{
  int i = 0;
  if (A == 0) return 0;
  for (i = 1; i*i <= A; i++);
  return i * i == A ? i : i - 1;
}

int minNumSquares2(int A)
{
  int ans = 0, minVal = A;
  while (A)
  {
	for (int i = 1; i <= A; i++)
	{
	  if ((A - i * i) >= 0)
	  {
		minVal = min(minVal, (A - i * i));
	  }
	  else 
	  {
		break;
	  }
	}
	A = minVal;
	ans++;
  }
  return ans;
}

int minNumSquaresDP(int A)
{
  int* DP = new int[A + 1];
  DP[0] = 0;
  for (int i = 1; i <= A; i++)
  {
	int ans = i;
	for (int j = 1; j * j <= i; j++)
	{
	  ans = min(ans, (DP[i - j * j] + 1));
	}
	DP[i] = ans;
  }
  return DP[A];
}


int countMinSquaresHINT(int A) 
{
  int dp[20];

  // simple base case assignment
  dp[0] = 0;
  dp[1] = 1;

  //finding optimal answer for every 2<=i<=N in bottom-up manner
  for (int i = 2; i <= A; i++) {

	//for i answer will be always less than equal to i.
	//maximum possible number of squares : i = (1^1+1^1+1^1+.....+1^1, i times)
	dp[i] = i;

	//Now identify from which number we have to make a direct jump to N so that the required answer is minimised.
	//do this by considering every possible direct jump
	//number of iterations will be <= sqrt(i)
	for (int x = 1; x * x <= i; x++) {
	  dp[i] = min(dp[i], 1 + dp[i - x * x]);
	}
  }
  return dp[A];
}

int minNumSquares(int A) //Failed for condition 41
{
  int x = nearestSquare(A);
  int cnt = 1;
  while (x)
  {
	A -= x * x;
	x = nearestSquare(A);
	if (x)cnt++;
  }
  return cnt;
}

int main()
{
  cout << "hello minimum square sum\n";
  cout << "Minimum Square Sum: " << minNumSquaresDP(41) << endl;
  return 0;
}