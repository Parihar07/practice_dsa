#include<iostream>
#include<vector>
#include<list>

using namespace std;

int checkCyclic(list<int>* al, int N, vector<int>& vis, vector<int>& rs);

int checkCyclic(list<int>* al, int N, vector<int> &vis, vector<int> &rs)
{
  if (rs[N] == 1) return 1;
  if (vis[N] == 1) return 0;

  rs[N] = 1;
  vis[N] = 1;

  for (auto a = al[N].begin(); a != al[N].end(); a++)
  {
	if (checkCyclic(al, *a, vis, rs)) return 1;
  }
  rs[N] = 0;
  return 0;
}

int solve(int A, vector<vector<int> >& B) {
 // int* vis = new int[A + 1];
 // for (int i = 0;
	//i <= A;
	//vis[i++] = 0);
 // int* rs = new int[A + 1];
 // for (int i = 0;
	//i <= A;
	//rs[i++] = 0);

  vector<int> vis(A + 1, 0);
  vector<int> rs(A + 1, 0);

  list<int>* al = new list<int>[A + 1];
  for (int i = 0; i < B.size(); i++)
  {
	for (int j = 1; j < B[0].size(); j++)
	{
	  al[B[i][0]].push_back(B[i][j]);
	}
  }

  int ans = checkCyclic(al, 1, vis, rs);
  return ans;
}

int main()
{
  cout << "hello finding cyclic\n";
  vector<vector<int>> B = { {1,2},{4,1},{2,4},{3,4},{5,2},{1,3} }; //[{1,2},{2,3},{3,4}]
  cout << "cyclic: " << solve(5, B) << endl;
  vector<vector<int>> C = { {1, 2}, { 2,3 }, { 3,4 }, {4,5 } };
  cout << "cyclic: " << solve(5, C) << endl;

  return 0;
}