#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int solve(string A, string B);
int lssHelperRecursive(string A, string B, vector<vector<int>>& dp, int Ae, int Be);
int lssHelperBF(string A, string B, int Ae, int Be);
int lssHelper(string A, string B, int Ae, int Be);

int lssHelperBF(string A, string B, int Ae, int Be)
{
  if (Ae == 0 || Be == 0) return 0;
  if (A[Ae] == B[Be])
  {
	int a = (1 + lssHelperBF(A, B, Ae - 1, Be - 1));
	return a;
  }
  return max(lssHelperBF(A, B, Ae, Be - 1), lssHelperBF(A, B, Ae - 1, Be));
}

int lssHelperRecursive(string A, string B, vector<vector<int>>& dp, int Ae, int Be)
{
  if (Ae == 0 || Be == 0) return -1;
  if (dp[Ae][Be] == -1)
  {
	if (A[Ae] == B[Be])
	{
	  dp[Ae][Be] = (1 + lssHelperRecursive(A, B, dp, Ae - 1, Be - 1));
	}
	else {
	  int a = lssHelperRecursive(A, B, dp, Ae, Be - 1);
	  int b = lssHelperRecursive(A, B, dp, Ae - 1, Be);
	  dp[Ae][Be] = max(a, b);
	}
  }
  return dp[Ae][Be];
}
int lssHelper(string A, string B, int Ae, int Be)
{
  int Al = A.size(), Bl = B.size();
  vector<vector<int>> DP(Al + 1, vector<int>(Bl + 1, 0));
  for (int i = 1; i <= Al; i++) {
	for (int j = 1; j <= Bl; j++) {
	  if (A[i - 1] == B[j - 1]) {
		DP[i][j] = 1 + DP[i - 1][j - 1];
	  }
	  else {
		DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
	  }
	}
  }
  return DP[Al][Bl];
}
int solve(string A, string B)
{
  int Al = (int)A.size(), Bl = (int)B.size();
  vector<vector<int>> DP(Al + 1, vector<int>(Bl + 1, -1));

  cout << "Longest SubSequence: " << lssHelper(A, B, DP, Al, Bl) << endl;
  //cout << "Longest SubSequence: " << lssHelperBF(A, B, Al, Bl) << endl;

  for (auto a = DP.begin(); a != DP.end(); a++)
  {
	for (auto b = a->begin(); b != a->end(); b++)
	{
	  cout << setw(5) <<*b << " ";
	}
	cout << endl;
  }
  return 0;
}
int main()
{
  cout << "Longest subsequence string hello \n";
  string A = "abbcdgf";
  string B = "bbadcgf";
  solve(A, B);
  return 0;
}