#include<iostream>
#include<list>
#include<queue>

using namespace std;

int checkDestSrc(vector<int>& A, vector<int>& B, int src, int dest) //BFS = breadth First Search
{
  int N = (int)A.size(), E = (int)B.size();
  list<int> *Al = new list<int>[N+1];
  int* va = new int[N + 1];
  for (int i = 0; i <= N; va[i++] = 0);
  for (int i = 0; i < N; i++)
  {
	Al[A[i]].push_back(B[i]);
	Al[B[i]].push_back(A[i]);
  }
 /* for (int i = 1; i < N; i++)
  {
	cout << i << "-";
	for (auto a = Al[i].begin(); a != Al[i].end(); a++)
	{
	  cout << * a << " ";
	}
	cout << endl;
  }*/

  queue<int> Q;
  Q.push(src);
  va[src] = 1;

  for (int i = 0; i < N; i++)
  {
	if (!Q.empty())
	{
	  int t = Q.front();
	  if (dest == t) return 1;
	  for (auto a = Al[t].begin(); a != Al[t].end(); a++)
	  {
		if (va[*a] == 0)
		{
		  Q.push(*a);
		  va[*a] = 1;
		}
	  }
	  Q.pop();
	}
  }
  return 0;
}

int main()
{
  vector<int> A = { 1,1,2,2,3,5,4 };
  vector<int> B = { 2,4,4,3,5,6,5 };

  cout << "Duestinition: " << checkDestSrc(A, B, 1, 7) << endl;
  return 0;
}