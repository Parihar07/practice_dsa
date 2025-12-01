#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
  int solve(int A, vector<vector<int> >& B) {
	vector<int> bb(A + 1, 0);
	vector<int>* al = new vector<int>[A + 1];
	for (int i = 0; i < B.size(); i++)
	{
	  al[B[i][0]].push_back(B[i][1]);
	  al[B[i][1]].push_back(B[i][0]);
	}
	queue<int> Q;
	for (int i = 0; i < A; ++i) {
	  if (bb[i] != 0) continue;
	  Q.push(i);
	  bb[0] = 1;
	  while (!Q.empty())
	  {
		int t = Q.front(); Q.pop();
		for (auto a = al[t].begin(); a != al[t].end(); a++)
		{
		  if (bb[*a] == 0)
		  {
			Q.push(*a);
			if (bb[t] == 1)
			{
			  bb[*a] = 2;
			}
			else {
			  bb[*a] = 1;
			}
		  }
		  else if (bb[*a] == bb[t])
		  {
			return 0;
		  }
		}
	  }
	}
	return 1;
  }
};

int main()
{
  int A = 3;
  vector<vector<int>> B = { {0,1},{0,2},{1,2} };
  vector<vector<int>> C = { {1,2},{3,5},{1,5},{3,2},{3,6},{4,5},{7,6} };
  vector<vector<int>> D = { {0,1} };
  vector<vector<int>> E = { {},{},{},{},{},{}, };

  Solution so;

  cout << "Result: " << so.solve(2, D) << endl;
  return 0;
}