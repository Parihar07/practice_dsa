#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

vector<int> solve(int A, vector<vector<int> >& B) {
  vector<int> ans;
  list<int>* al = new list<int>[B.size() + 1];
  for (int i = 0; i < B.size(); i++)
  {
	al[B[i][0]].push_back(B[i][1]);
  }

  vector<int> depen(A + 1, 0);
  vector<int> vis(A + 1, 0);


  for (int i = 1; i <= A; i++)
  {
	for (auto a = al[i].begin(); a != al[i].end(); a++)
	{
	  depen[*a]++;
	}
  }
  queue<int> Q;

  while (1)
  {
	for (int i = 1; i < depen.size(); i++)
	{
	  if (vis[i] != 1 && depen[i] == 0 )
	  {
		Q.push(i);
		vis[i] = 1;
		ans.push_back(i);
	  }
	}

	while (!Q.empty())
	{
	  int t = Q.front();
	  Q.pop();

	  for (auto a = al[t].begin(); a != al[t].end(); a++)
	  {
		depen[*a]--;
	  }
	}

	int cnt = 0;
	for (int i = 0; i < vis.size(); i++)
	{
	  if (vis[i] == 1) cnt++;
	}
	if (cnt == A) break;
  }
  
  return ans;
}


int main()
{
  int A = 6;
  vector<vector<int>> B = { {6,3},{6,1},{5,1},{5,2},{3,4},{4,2} };
  vector<int> ans = solve(A, B);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  return 0;
}