#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<int>& A) {

  sort(A.begin(), A.end());
  return A[(A.size() - 1)];
}

int main()
{
  vector<int> A = { 1, 2, 3, 4, 5 };
  vector<int> B = { 5, 17, 100, 11 };

  cout << solve(A) << endl;
  cout << solve(B) << endl;
  return 0;
}