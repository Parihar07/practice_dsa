#include<iostream>
#include<vector>
#include<algorithm>
/*Farmer John has built a new long barn with N stalls. Given an array of integers 
* A of size N where each element of the array represents the location of the stall 
* and an integer B which represents the number of cows.
* His cows don't like this barn layout and become aggressive towards each other once 
* put into a stall. To prevent the cows from hurting each other, John wants to assign the cows 
* to the stalls, such that the minimum distance between any two of them is as large as possible. 
* What is the largest minimum distance?
* A = [1, 2, 3, 4, 5]
* B = 3
* Ans 2
*/
using namespace std;
int solve(vector<int>& A, int B);
bool check(vector<int>& A, int m, int B);

bool check(vector<int>& A, int m, int B)
{
  long p = A[0];
  long cows = 1;
  for (int s = 1; s < A.size(); s++)
  {
	if ((A[s] - p) >= m)
	{
	  cows++;
	  p = A[s];
	}
	if (cows == B && s == (A.size() - 1))
	{
	  return true;
	}
  }
  return false;
}
int solve(vector<int>& A, int B) {
  //Maximum Distance between two cows be A.size() - A[0], thats is we can shelter two cows far
  //Minimum be beside each other A[1]-A[0]
  //Hence we will pass 1-> 4 distance range to check if cows can be allocated in there shelters
  vector<int> sa(A.size(), 0);
  for (int i = 0; i < A.size(); i++)
  {
	sa[i] = A[i];
  }
  sort(sa.begin(), sa.end());

  int s = 0, e = sa.size() - 1, mid = -1;
  int ans = -1;
  while (s <= e)
  {
	mid = (s + e) / 2;
	if (true == check(sa, mid, B))
	{
	  ans = mid;
	  s = mid + 1;
	}
	else {
	  e = mid - 1;
	}
  }
 // for (int d = 0; d <= (A[A.size() - 1] - A[0]); d++)
 // {
	//if (true == check(A, d, B))
	//{
	//  return d;
	//}
 // }
  return ans;
}


int main()
{
  vector<int> A = { 1, 2, 3, 4, 5 };
  vector<int> B = { 1, 2 };
  vector<int> C = { 0,1000000000 };
  cout << "Hello aggressive cows\n";
  cout << "Aggresive Cows : " << solve(A, 3) << endl;
  cout << "Aggresive Cows : " << solve(B, 2) << endl;
  cout << "Aggresive Cows : " << solve(C, 2) << endl;

  return 0;
}