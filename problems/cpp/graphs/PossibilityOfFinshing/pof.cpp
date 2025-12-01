#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<utility>
using namespace std;

class Solution
{
  list<int>* al;
  vector<int> d;
  priority_queue<pair<int, int>> pq;
public:
  int solve(int A, vector<int>& B, vector<int>& C);
};

int Solution::solve(int A, vector<int>& B, vector<int>& C) {
  al = new list<int>[A + 1];
  d = vector<int>(A + 1, 0);
  for (int i = 0; i < B.size(); i++)
  {
	al[B[i]].push_back(C[i]);
  }

  for (int i = 1; i <= A; i++)
  {
	for (auto a = al[i].begin(); a != al[i].end(); a++)
	{
	  d[*a]++;
	}
  }

  for (int i = 1; i <= A; i++)
  {
	pq.push({ -d[i], i });
  }

  while (!pq.empty())
  {
	pair<int, int> t = pq.top();
	pq.pop();
	for (auto a = al[t.second].begin(); a != al[t.second].end(); a++)
	{
	  if (abs(t.first) < d[*a])
	  {
		d[*a] -= 1;
		pq.push({ -d[*a], *a });
	  }
	}
  }

  for (int i = 0; i <= A; i++)
  {
	if (d[i] != 0) return 0;
  }

  return 1;
}

int main()
{
  Solution so;
  vector<int> B = { 1,2 };
  vector<int> C = { 2,1 };
  int A = 3;

  cout << "Possibility Of finishing: " << so.solve(A, B, C) << endl;

  return 0;
}