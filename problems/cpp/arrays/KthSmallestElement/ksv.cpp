#include<iostream>
#include<vector>
#include"../common/common.h"
using namespace std;

int kthsmallest(const vector<int>& A, int B) {

  vector<int> T = A;
  int f = 0;
  for (int i = 0; i < B; i++)
  {
	int minInd = i;
	int minVal = A[i];
	for (int j = i + 1; j < A.size(); j++)
	{
	  if (T[j] < minVal)
	  {
		minVal = T[j];
		minInd = j;
	  }
	} 
	  _swap(T[i], T[minInd]);
	
  }

  return T[B - 1];
}

int main()
{
  vector<int> A = { 94,87,100,11,23,98,17,35,43,66,34,53,72,80,5,34,64,71,9,16,41,66,96 };
  vector<int> B = { 60,94,63,3,86,40,93,36,56,48,17,10,23,43,77,1,1,93,79,4,10,47,1,99,91,53,99,18,52,61,84,10,13,52,3,9,78,16,7,62 };
  vector<int> C = { 1 };
  cout << "Kth smallest integer : " << kthsmallest(A, 19) << endl;
  cout << "Kth smallest integer : " << kthsmallest(B, 22) << endl;
  cout << "Kth smallest integer : " << kthsmallest(C, 1) << endl;
  return 0;
}