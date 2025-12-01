#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution
{
public:
  //Function to find the shortest distance of all the vertices
  //from the source vertex S.
  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
	vector<int> ans(V + 1, INT_MAX);
	ans[S] = 0; // Source node from where we want to het minimum distance
	priority_queue<pair<int, int>> pq;

	//for (int i = 0; i < V; i++)
	//{
	//  for (auto a = adj[i].begin(); a != adj[i].end(); a++)
	//  {
	//	cout << i << " ";
	//	//for (auto b = a->begin(); b != a->end(); b++)
	//	for(int j=0;j<2;j++)
	//	{
	//	  cout << a->begin()[j] << " ";
	//	}
	//	cout << endl;
	//  }
	//  //cout << endl;
	//}
	// 
	//cout << endl;
	//// Code here
	pq.push({ -(0),S });
	while (!pq.empty())
	{
	  pair<int, int> t = pq.top();
	  pq.pop();
	  int w = abs(t.first);
	  int u = t.second;

	  for (int i = 0; i < adj[u].size(); i++)
	  {
		vector<int> tv = adj[u][i];
		int nu = tv[0], nw = tv[1] + w;
		if (nw < ans[nu])
		{
		  ans[nu] = nw;
		  pq.push({ -(nw),nu });
		}
	  }
	}
	return ans;
  }
};


int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj[3] = {
	{
	  {1, 1}, { 2, 6 }
	},
	{
	  {2, 3}, {0, 1}
	},
	{
	  {1, 3}, {0, 6}
	}
  };
  int i = 0;
  /*while (i++ < E) {
	int u, v, w;
	cin >> u >> v >> w;
	vector<int> t1, t2;
	t1.push_back(v);
	t1.push_back(w);
	adj[u].push_back(t1);
	t2.push_back(u);
	t2.push_back(w);
	adj[v].push_back(t2);
  }*/
  int S;
  cin >> S;

  Solution obj;
  vector<int> res = obj.dijkstra(V, adj, S);

  for (int i = 0; i < V; i++)
	cout << res[i] << " ";
  cout << endl;

  return 0;
}