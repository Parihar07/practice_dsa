#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Solution {
public:
  vector<int> solve(int A, vector<vector<int> >& B);
};
vector<int> Solution::solve(int A, vector<vector<int> >& B)
{
  //Answer array for returning
  vector<int> ans(A, 0);
  //Create AL;
  list<int>* al = new list<int>[A + 1];
  for (int i = 0; i < B.size(); i++)
	al[B[i][0]].push_back(B[i][1]);
  //create dependancy list
  vector<int> d(A + 1, 0);
  for (int i = 1; i <= A; i++)
  {
	for (auto a : al[i])
	  d[a]++;
  }
  //using queue process
  int ind = 0;
  vector<int> vis(A + 1, 0);
  //queue<pair<int, int>> q;
  priority_queue < int, vector < int >, greater < int > > q;
  for (int i = 1; i <= A; i++)
  {
	if (d[i] == 0)
	{
	  q.push(i);
	  vis[i] = 1;
	}
  }
  while(!q.empty())
  {
	int t = q.top();
	q.pop();
	ans[ind]=t; ind++;

	for (auto a = al[t].begin(); a != al[t].end(); a++)
	{
	  d[*a]--;
	  if (d[*a] == 0)
	  {
		q.push(*a);
	  }
	}
  }
  if (ind != A) {
	ans.clear();
  }

  return ans;
}
int main()
{
  int A = 6;
  vector<vector<int>> B = { {6,3},{6,1},{5,1},{5,2},{3,4},{4,2} };
  Solution so;
  vector<int> ans = so.solve(A, B);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  return 0;
  return 0;
}