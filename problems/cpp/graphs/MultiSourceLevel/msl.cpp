#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<iomanip>

using namespace std;

struct minDistance {
  int node;
  int minDist;
  minDistance() :node(0), minDist(0) {}
  minDistance(int n, int mn) :node(n), minDist(mn) {}
};


void solve(vector<vector<int>>& A, int B, int C);
int BFS(list<int>* al, vector<int>& vis, vector<int>& level, int src);
int distanceWithinNodes(list<int>* al, vector<int>& vis, vector<int>& level, int src, int end);
int minDistanceNodes(list<int>* al, vector<int>& vis, vector<int>& level, int src, int end);

int minDistanceNodes(list<int>* al, vector<int>& vis, vector<int>& level, int src, int end)
{
  minDistance md[14];
  for (int i = 0; i <= 13; i++)
  {
	md[i].node = i;
	int a = distanceWithinNodes(al, vis, level, i, 11);
	int b = distanceWithinNodes(al, vis, level, i, 7);
	int c = distanceWithinNodes(al, vis, level, i, 2);
	md[i].minDist = min(a, min(b, c));
  }

  for (int i = 0; i <= 13; i++)
  {
	cout << md[i].node << " - " << md[i].minDist << endl;
  }

  return 0;
}

int distanceWithinNodes(list<int>* al, vector<int>& vis, vector<int>& level, int src, int end)
{
  queue<int> Q;
  Q.push(src);
  vis[src] = 1; level[src] = 0;
  while (!Q.empty())
  {
	int t = Q.front();
	for (auto a = al[t].begin(); a != al[t].end(); a++)
	{
	  if (vis[*a] != 1)
	  {
		vis[*a] = 1;
		level[*a] = 1 + level[t];
		Q.push(*a);
	  }
	  if (end == *a) return level[*a];
	}
	Q.pop();
  }
  return 0;
}

int MultipleSourceBFS(list<int>* al, vector<int>& vis, vector<int>& level, int src1, int src2, int src3)
{
  queue<int> Q;
  Q.push(src1);
  Q.push(src2);
  Q.push(src3);
  vis[src1] = 1; level[src1] = 0;
  vis[src2] = 1; level[src2] = 0;
  vis[src3] = 1; level[src3] = 0;

  while (!Q.empty())
  {
	int t = Q.front();
	for (auto a = al[t].begin(); a != al[t].end(); a++)
	{
	  if (vis[*a] != 1)
	  {
		vis[*a] = 1;
		level[*a] = 1 + level[t];
		Q.push(*a);
	  }
	}
	Q.pop();
  }
  return 0;
}

int BFS(list<int>* al, vector<int>& vis, vector<int>& level, int src)
{
  queue<int> Q;
  Q.push(src);
  vis[src] = 1; level[src] = 0;
  while (!Q.empty())
  {
	int t = Q.front();
	for (auto a = al[t].begin(); a != al[t].end(); a++)
	{
	  if (vis[*a] != 1)
	  {
		vis[*a] = 1;
		level[*a] = 1 + level[t];
		Q.push(*a);
	  }
	}
	Q.pop();
  }
  return 0;
}

void solve(vector<vector<int>>& A, int B, int C)
{
  vector<int> vis(B + 1, 0), level(B + 1, 0);
  list<int>* al = new list<int>[B + 1];
  for (int i = 0; i < A.size(); i++)
  {
	al[A[i][0]].push_back(A[i][1]);
  }

  //minDistanceNodes(al, vis, level, 0, 0);
  MultipleSourceBFS(al, vis, level, 11, 7, 2);

  /* for (int i = 0; i <=B; i++)
   {
	 cout << i << " - ";
	 for (auto a = al[i].begin(); a != al[i].end(); a++)
	 {
	   cout << *a << " ";
	 }
	 cout << endl;
   }*/
   //BFS(al, vis, level,2);
  cout << "Node | Level | Visited\n";
  for (int i = 0; i <= B; i++)
  {
	cout << i << " "<< level[i] << " " << vis[i] << "\n";
  }
  /*cout << "Disatance between Node : " << distanceWithinNodes(al, vis, level, 3, 8) << endl;
  cout << endl;*/

  return;
}



int main()
{
  int N = 13;
  vector<vector<int>> A = { {1,11},{2,3},{2,5},{3,2},{3,9},{3,12},{4,5},{4,8},{5,2},{5,4},{5,11},
	{6,11},{7,8},{7,10},{8,4},{8,7},{9,3},{9,13},{10,7},{10,13},
	{11,1},{11,5},{11,6},{12,3},{13,9},{13,10} };

  solve(A, N, 2);
  return 0;
}