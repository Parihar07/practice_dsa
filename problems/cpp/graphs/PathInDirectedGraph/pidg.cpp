#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

int solve(int A, vector<vector<int> >& B);
int pathDirectedGraph(vector<vector<int>>& B, int A, int src, int dest); //BFS
void DepthFirstSearch(list<int>* al, int vis[], int N);


void DepthFirstSearch(list<int>* al, int vis[], int N) //DFS
{
  if (vis[N] == 1) return;
  vis[N] = 1;
  for (auto a = al[N].begin(); a != al[N].end(); a++)
  {
	DepthFirstSearch(al, vis, *a);
  }
  return;
}

int pathDirectedGraph(vector<vector<int>>& B, int A, int src, int dest)
{
  list<int>* al = new list<int>[A + 1];
  for (int i = 0; i < B.size(); i++)
  {
	for (int j = 1; j < B[0].size(); j++)
	{
	  al[B[i][0]].push_back(B[i][j]);
	}
  }
  for (int i = 1; i <= A; i++)
  {
	cout << i << " - ";
	for (auto a = al[i].begin(); a != al[i].end(); a++)
	{
	  cout << *a << " ";
	}
	cout << endl;
  }

  int* vis = new int[A + 1];
  for (int i = 0; 
	i <= A; 
	vis[i++] = 0);

  queue<int> Q;
  Q.push(src);
  vis[src] = 1;

  while(!Q.empty())
  {
	int t = Q.front();
	if (t == dest) return 1;
	for (auto a = al[t].begin(); a != al[t].end(); a++)
	{
	  if (vis[*a] == 0)
	  {
		Q.push(*a);
		vis[*a] = 1;
	  }
	}
	Q.pop();
  }
  return 0;
}
int solve(int A, vector<vector<int> >& B) 
{
  //return pathDirectedGraph(B, A, 1, 5);
  list<int>* al = new list<int>[A + 1];
  for (int i = 0; i < B.size(); i++)
  {
	for (int j = 1; j < B[0].size(); j++)
	{
	  al[B[i][0]].push_back(B[i][j]);
	}
  }
 /* for (int i = 0; i <= A; i++)
  {
	cout << i << "-";
	for (auto a = al[i].begin(); a != al[i].end(); a++)
	{
	  cout << *a << " ";
	}
	cout << endl;
  }*/

  int* V = new int[A + 1];
  for (int i = 0;
	i <= A;
	V[i++] = 0);

  DepthFirstSearch(al, V, 1);
  return V[A];
}

int main()
{
  cout << "Breadth first search over Directed Graph\n";
  int A = 5;
  vector<vector<int>> B = { {1,2},{4,1},{2,4},{3,4},{5,2},{1,3} }; //[{1,2},{2,3},{3,4}]
  vector<vector<int>> C = { {1, 2}, { 2,3 }, { 3,4 }, {4,5 } };
  cout << "Path found : " << solve(A, C) << endl;
  //cout << "Path found : " << solve(5,C) << endl;

  return 0;
}