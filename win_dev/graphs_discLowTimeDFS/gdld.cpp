#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<int>> &G, vector<int>& disc, vector<int>& low, 
  vector<int>& vis, vector<int>& par, int v, int p)
{
  static int t = 0; t++;
  vis[v] = 1;
  disc[v] = t;
  low[v] = t;
  par[v] = p;

  for (auto i : G[v])
  {
	if (vis[i] == 0)
	{
	  DFS(G, disc, low, vis, par, i, v);
	}
	else {
	  if (par[v] != i)
	  {
		low[v] = min(low[v], low[i]);
	  }
	}
  }
  return;
}

void getDiscoveryLowTime(vector<int>& U, vector<int>& V, const int N)
{
  //creating adjacency list
  auto E = U.size();
  vector<vector<int>> G(N+1);
  for (int i = 0; i < E; i++)
  {
	G[U[i]].push_back(V[i]);
	G[V[i]].push_back(U[i]);//undirected graph
  }

  //creating discovery, low discovery, visited and parent list
  vector<int> disc(N + 1, 0), low(N + 1, 0), vis(N + 1, 0), par(N + 1, 0);

  DFS(G, disc, low, vis, par, 1, 0);

  for (int i = 0; i <= N; i++)
  {
	cout << i << "-" << disc[i] << "-" << low[i] << endl;
  }

  return;
}

int main() {
  cout << "Hello, graphs get discovery time and low time DFS\n";
  vector<int> U{ 1,2,2,2,3,3,4,6,8,8,8 }, V{ 2,3,8,4,4,6,5,7,9,10,11 };
  getDiscoveryLowTime(U, V, 11);
  return 0;
}