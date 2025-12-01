#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<iomanip>

using namespace std;
struct nData {
  int x;
  int y;
  int vis;
  int lvl;
  nData(int i, int j, int v, int l) :x(i), y(j), vis(v), lvl(l) {}
  nData(nData* other)
  {
	x = other->x;
	y = other->y;
	vis = other->vis;
	lvl = other->lvl;
  }
  nData() :x(0), y(0), vis(0), lvl(0) {}
};
int solve(vector<vector<int> >& A);

int solve(vector<vector<int> >& A)
{
  queue<nData> q;
  int m = (int)A.size(), n = (int)A[0].size();
  vector<vector<nData>> aA(A.size(), vector<nData>(A[0].size(), (new nData())));

  for (int i = 0; i < A.size(); i++)
  {
	for (int j = 0; j < A[0].size(); j++)
	{
	  if (A[i][j] == 2)
	  {
		nData d(i, j, 1, 0);
		aA[i][j] = d;
		q.push(d);
	  }
	}
  }

  while (!q.empty())
  {
	nData t = q.front();
	q.pop();

	if (!((t.x + 1) >= m) && //Boundary check
	  (aA[t.x + 1][t.y].vis != 1) && // Visited
	  (A[t.x + 1][t.y] == 1)) //Checking up
	{
	  nData da(t.x + 1, t.y, 1, t.lvl + 1);
	  q.push(da);
	  aA[t.x + 1][t.y] = da;
	}
	if (!((t.x - 1) < 0) && //Boundary Check
	  (aA[t.x - 1][t.y].vis != 1) && //Visited 
	  (A[t.x - 1][t.y] == 1))   //checking down
	{
	  nData da(t.x - 1, t.y, 1, t.lvl + 1);
	  q.push(da);
	  aA[t.x - 1][t.y] = da;
	}
	if (!((t.y + 1) >= n) && //Boundary Check
	  (aA[t.x][t.y + 1].vis != 1) && // Visited
	  (A[t.x][t.y + 1] == 1)) //checking right
	{
	  nData da(t.x, t.y + 1, 1, t.lvl + 1);
	  q.push(da);
	  aA[t.x][t.y + 1] = da;
	}
	if (!((t.y - 1) < 0) && //Boundary Check
	  (aA[t.x][t.y - 1].vis != 1) && // Visted
	  (A[t.x][t.y - 1] == 1)) // checking down
	{
	  nData da(t.x, t.y - 1, 1, t.lvl + 1);
	  q.push(da);
	  aA[t.x][t.y - 1] = da;
	}
  }

  int ans = -1;
  //Getting maximum path
  for (int i = 0; i < m; i++) 
  {
	for (int j = 0; j < n; j++)
	{
	  ans = max(ans, aA[i][j].lvl);
	}
  }

  //Checking if any mango not rotten
  for (int i = 0; i < m; i++)
  {
	for (int j = 0; j < n; j++)
	{
	  if (A[i][j] == 1 && aA[i][j].vis != 1) ans = -1;
	}
  }

  return ans;
}

int main()
{
  cout << "Hello rotten orange\n";

  vector<vector<int>> A = { {2, 1, 1},{1, 1, 0},{0, 1, 1} };
  vector<vector<int>> B = { {2, 1, 1},{0, 1, 1},{1, 0, 1} };

  cout << "Time required : " << solve(A) << endl;
  cout << "Time required : " << solve(B) << endl;

  return 0;
}