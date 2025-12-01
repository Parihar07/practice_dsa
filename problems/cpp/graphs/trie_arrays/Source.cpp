#include<iostream>
#include<string>

using namespace std;
class node {
public:
  int isEnd;
  node* ch[26];
  node() : isEnd(0), ch{ 0 } {}
};

void addString(node* r, string s)
{
  node* pre = NULL;
  for (int i = 0; i < s.length(); i++)
  {
	char c = s[i];
	node* t = new node();
	if (pre == NULL)
	{
	  pre = t;
	  r->ch[c - 'a'] = t;
	}
	else {
	  pre->ch[c - 'a'] = t;
	  pre = t;
	}
  }
  pre->isEnd = 1;
}

int findStr(node* r, string s)
{
  node* nxt = r; //hello
  for (int i = 0; i < s.length(); i++)
  {
	char c = s[i];
	if (nxt->ch[c - 'a'] != NULL)
	{
	  nxt = nxt->ch[c - 'a'];
	}
	else {
	  return 0;
	}
  }
  return 1;
}
int main()
{
  node* root = new node();

  string s = "hello";
  addString(root, s);
  addString(root, "world");
  addString(root, "apple");
  addString(root, "cat");
  addString(root, "dog");
  addString(root, "buffalo");
  cout << findStr(root, "hell00") << endl;
  cout << findStr(root, "xyz") << endl;
  cout << findStr(root, "buff") << endl;
  cout << findStr(root, "wor") << endl;

  return 0;
}