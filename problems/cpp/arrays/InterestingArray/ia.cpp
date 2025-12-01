/*You have an array A with N elements. We have two types of operation available on this array :
We can split an element B into two elements, C and D, such that B = C + D.
We can merge two elements, P and Q, to one element, R, such that R = P ^ Q i.e., XOR of P and Q.
You have to determine whether it is possible to convert array A to size 1, containing a single element equal to 0 after several splits and/or merge?
*/

#include<iostream>
#include<vector>

using namespace std;
string solve(vector<int>& A) {
  int N = A.size();
  int oddCnt = 0;
  
  for (int i = 0; i < N; i++)
  {
	if (A[i] % 2)
	  oddCnt += 1;
  }
  if (oddCnt == 0)
	return "No";
  if(oddCnt%2)
	  return "No";
	else
	  return "Yes";
}

int main()
{
  vector<int> A = { 9, 17 };
  vector<int> B = { 0 };

  cout << solve(A);
  cout << solve(B);

  return 0;
}