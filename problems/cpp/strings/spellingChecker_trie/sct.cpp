#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
struct node {
  int isEnd;
  node* ch[26];
  node():isEnd(0),ch{0}{}
};

struct nodeUM {
  int isEnd;
  unordered_map<char, nodeUM*> ch;
};
vector<int> spellingChecker(vector<string>& A, vector<string>& B);
void addString(node* r, string s);
void addStringUM(nodeUM* r, string s);
int findString(node* r, string s);
int findStringUM(nodeUM* r, string s);

void addString(node* r, string s)
{
  if (r == NULL) return;
  node* t = r;
  for (int i = 0; i < s.length(); i++)
  {
	char c = s[i];
	if (t->ch[c - 'a'] != NULL)
	{
	  t = t->ch[c - 'a'];
	}
	else {
	  t->ch[c - 'a'] = new node();
	  t = t->ch[c - 'a'];
	}
  }
  t->isEnd = 1;
  return;
}
int findString(node* r, string s)
{
  node* t = r;
  for (int i = 0; i < s.length(); i++)
  {
	char c = s[i];
	if (t->ch[c - 'a'] != NULL)
	{
	  t = t->ch[c - 'a'];
	}
	else {
	  return 0;
	}
  }
  return t->isEnd ? 1 : 0;
}

void addStringUM(nodeUM* r, string s)
{
  nodeUM* t = r;
  for (int i = 0; i < s.length(); i++)
  {
	int c = s[i];
	if (t->ch.find(c - 'a') == t->ch.end())
	{
	  t->ch[c - 'a'] = new nodeUM();
	  t = t->ch[c - 'a'];
	}
	else {
	  t = t->ch[c - 'a'];
	}
  }
  t->isEnd = 1;
}

int findStringUM(nodeUM* r, string s)
{
  nodeUM* t = r;
  for (int i = 0; i < s.length(); i++)
  {
	char c = s[i];
	if (t->ch.find(c - 'a') != t->ch.end())
	{
	  t = t->ch[c - 'a'];
	}
	else {
	  return 0;
	}
  }
  return t->isEnd ? 1 : 0;
}

vector<int> spellingChecker(vector<string>& A, vector<string>& B)
{
  vector<int> ans;
  nodeUM* root = new nodeUM();
  for (int i = 0; i < A.size(); i++)
  {
	addStringUM(root, A[i]);
  }
  for (int i = 0; i < B.size(); i++)
  {
	ans.push_back(findStringUM(root, B[i]));
  }
  return ans;
}
int main()
{
  cout << "hello spellig checker\n";
  vector<string> A = { "hello","world" };
  vector<string> B = { "hello","w" };
  vector<int> ans = spellingChecker(A, B);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  return 0;
}