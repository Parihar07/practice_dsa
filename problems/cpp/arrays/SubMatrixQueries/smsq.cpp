#include<iostream>
#include<vector>

using namespace std;

vector<int> solve(vector<vector<int> >& A, 
  vector<int>& B, 
  vector<int>& C, 
  vector<int>& D, 
  vector<int>& E) {

  
  vector<int> ansQuery(B.size(), 0);
  long long modFactor = 10000000007;


  int M = A.size(), N = A[0].size();
  vector<vector<long long>> psq(M,vector<long long>(N,0));
  for (int i = 0; i < M; i++)
  {
	for (int j = 0; j < N; j++)
	{
	  psq[i][j] = A[i][j];
	}
  }

  for (int i = 0; i < M; i++)
  {
	for (int j = 1; j < N; j++)
	{
	  psq[i][j] = (A[i][j] % modFactor + psq[i][j - 1] % modFactor) % modFactor;
	}
  }

  for (int i = 0; i < N; i++)
  {
	for (int j = 1; j < M; j++)
	{
	  psq[j][i] = (psq[j][i] % modFactor + psq[j - 1][i] % modFactor) % modFactor;
	}
  }

  for (int i = 0; i < M; i++)
  {
	for (int j = 0; j < N; j++)
	{
	  cout << psq[i][j] << " ";
	}
	cout << endl;
  }

  int TR, TC, BR, BC;
  long long ans = 0;

  for (int q = 0; q < B.size(); q++)
  {
	TR = B[q] - 1;
	TC = C[q] - 1;
	BR = D[q] - 1;
	BC = E[q] - 1;

	if (TR == 0 && TC == 0)
	{
	  ans = psq[BR][BC] % modFactor;
	}
	else if (TR == 0)
	{
	  ans = (psq[BR][BC] % modFactor - psq[BR][TC - 1] % modFactor) % modFactor;
	}
	else if (TC == 0)
	{
	  ans = (psq[BR][BC] % modFactor - psq[TR - 1][BC] % modFactor) % modFactor;
	}
	else
	{
	  ans = psq[BR][BC]  - psq[BR][TC - 1]  - psq[TR - 1][BC]  + psq[TR - 1][TC - 1];
	}

	ansQuery[q] = (ans % modFactor + modFactor) % modFactor;;
  }

  return ansQuery;
}
int main()
{
  cout << "Hello sum of sub matrix queries\n";
  vector<int> vAns;

  vector<vector<int>> A = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
  vector<int> B = { 1, 2 }, C = { 1, 2 }, D = { 2, 3 }, E = { 2, 3 };

  vector<vector<int>> K = { {5, 17, 100, 11},{0, 0, 2, 8} };
  vector<int> L = { 1, 1 }, M = { 1, 4 }, N = { 2, 2 }, O = { 2, 4 };

  vAns = solve(A, B, C, D, E);
  for (int i = 0; i < vAns.size(); i++) {
	cout << vAns[i] << " ";
  }
  cout << endl;

  vAns = solve(K, L, M, N, O);
  for (int i = 0; i < vAns.size(); i++) {
	cout << vAns[i] << " ";
  }
  cout << endl;

  return 0;
}