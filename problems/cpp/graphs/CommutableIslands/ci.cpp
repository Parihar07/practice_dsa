#include<iostream>
#include<vector>
//#include<utility>
#include<algorithm>

using namespace std;

class Solution {
public:
  int find(vector<int>& c,int n);
  int solve(int A, vector<vector<int> >& B);
};

int Solution::find(vector<int> &c, int n)
{
  if (n == c[n]) return n;
  return c[n] = find(c,c[n]);
}

int Solution::solve(int A, vector<vector<int> >& B) {
  vector<pair<int, pair<int, int>>> al;
  int ans = 0;
  vector<int> c(A + 1, 0);

  for (int i = 0; i <= A; i++) c[i] = i;

  for (int i = 0; i < B.size(); i++)
  {
	al.push_back({ B[i][2], { B[i][0], B[i][1]} });
  }

  sort(al.begin(), al.end());

  for (int i = 0; i < al.size(); i++)
  {
	int u = find(c, al[i].second.first);
	int v = find(c, al[i].second.second);
	if (u != v)
	{
	  ans += al[i].first;
	  c[max(u, v)] = c[min(u, v)];
	}
  }

  return ans;
}

int main()
{
  cout << "Hello commutable islands\n";
  int A = 4;
  vector<vector<int>> B = { {1,2,1},{2,3,4},{1,4,3},{4,3,2},{1,3,10} };
  vector<vector<int>> C = { {1,2,1},{2,3,2},{3,4,4},{1,4,3} };
  vector<vector<int>> D = { {4,6,1},{3,4,3},{7,8,5},{2,7,5},{3,2,6},{6,8,8},{9,6,10},{1,5,11},{7,9,12},{5,10,14} };

  Solution so;

  cout<< "Minimum cimmutable cost : "<<so.solve(10, D)<<endl;
  return 0;
}