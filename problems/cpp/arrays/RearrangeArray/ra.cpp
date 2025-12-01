#include<iostream>
#include<vector>

using namespace std;

void arrange(vector<int>& A) {
  // Do not write main() function.
  // Do not read input, instead use the arguments to the function.
  // Do not print the output, instead return values as specified
  // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  int index = 0;
  int value = 0;
  int N = A.size();
  for (int i = 0; i < N ; i++)
  {
	A[i] *= N;
  }
  for (int i = 0; i < A.size(); i++)
  {
	index = A[i]/N;
	value = A[index]/N;
	A[i] += value;
  }
  for (int i = 0; i < N; i++)
  {
	A[i] %= N;
  }

}

int main()
{
  cout << "hello rearrange array\n";
  
  return 0;
}