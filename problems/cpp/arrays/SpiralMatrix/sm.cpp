#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > generateMatrix(int A) {
  vector<vector<int>> sm(A, vector<int>(A,0));

  int r = 0, c = 0, N = A, data = 0;
  while (N > 1)
  {
	//TOP
	for (int i = 1; i < N; i++)
	{
	  sm[r][c] = ++data;
	  c++;
	}
	//RIGHT
	for (int i = 1; i < N; i++)
	{
	  sm[r][c] = ++data;
	  r++;
	}
	//BOTTOM
	for (int i = 1; i < N; i++)
	{
	  sm[r][c] = ++data;
	  c--;
	}
	//LEFT
	for (int i = 1; i < N; i++)
	{
	  sm[r][c] = ++data;
	  r--;
	}
	r++; c++; N -= 2;
  }
  if (N) {
	sm[r][c] = ++data;
  }
  return sm;
}

int main()
{
  cout << "Hello Spiral matrix\n";

  vector<vector<int>> sm = generateMatrix(5);

  for (int r = 0; r < sm[0].size(); r++)
  {
	for (int c = 0; c < sm.size(); c++)
	{
	  cout << sm[r][c]<<"   ";
	}
	cout << endl;
  }

  return 0;
}