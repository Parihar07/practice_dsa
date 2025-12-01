#include<iostream>
#include<vector>
#include<algorithm>
#include"../common/common.h"

using namespace std;

int findMinXor(vector<int>& A);
int findMinXorOpt(vector<int>& A);
int findMinXorOpt2(vector<int>& A);

int findMinXor(vector<int>& A) {
  int N = A.size(), minXor = A[0] ^ A[1];
  for (int x = 0; x < N; x++)
  {
	for (int y = x + 1; y < N; y++)
	{
	  minXor = _min((A[x] ^ A[y]), minXor);
	}
  }
  return minXor;
}

int findMinXorOpt(vector<int>& A) {
  int N = A.size();
  vector<int> PXOR(N, 0);
  PXOR[0] = A[0]^A[1];
  for (int x = 1; x < N; x++)
  {
	PXOR[x] = _min(PXOR[x - 1], A[x]);
  }
  long minXor = PXOR[0];

  for (int i=1;i<N;i++)
  {
	minXor = _min(minXor, PXOR[i]);
  }
  return minXor;
}

int findMinXorOpt2(vector<int>& A) {
  int N = A.size();

  vector<int> SA(N, 0);
  for (int i = 0; i < N; i++)
  {
	SA[i] = A[i];
  }
  sort(SA.begin(), SA.end());
  long minXor = SA[0] ^ SA[1];

  for (int i = 0; i+1 < N; i++)
  {
	minXor = _min(minXor, (SA[i] ^ SA[i + 1]));
  }
  return minXor;
}

int main()
{
  cout << "hello min XOR";
  vector<int> A = { 492416,275153,684032,319360,543232,804480,525824,671825,1036753,940625,909521,405120,1076689,80081,57856,1000145,13649 };
  vector<int> C = { 0, 2, 5, 7 ,1};
  vector<int> B = { 0, 4, 7, 9 };

  cout << "minXor : " << findMinXorOpt2(A) << endl;
  cout << "minXor : " << findMinXorOpt2(B) << endl;
  cout << "minXor : " << findMinXorOpt2(C) << endl;
  return 0;
}