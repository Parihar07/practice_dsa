#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} *root;

struct TreeInfo {
  int M;
  TreeNode* R;
  TreeInfo(TreeNode* r, int m) :R(r), M(m) {};
};

void createTree();
void printPreOrder(TreeNode* R);
void printInOrder(TreeNode* R);
void printPostOrder(TreeNode* R);
void printLevelOrder(TreeNode* R);
vector<int> rightTreeView(TreeNode* R);
vector<vector<int> > verticalOrderTraversal(TreeNode* A);
vector<int> leftViewTree(TreeNode* r);

void createTree()
{
  TreeNode* R = new TreeNode(2);
  R->left = new TreeNode(3);
  R->right = new TreeNode(4);
  R->left->left = new TreeNode(5);
  R->left->right = new TreeNode(6);
  R->left->left->left = new TreeNode(9);
  R->left->left->right = new TreeNode(10);
  R->right->left = new TreeNode(8);
  R->right->right = new TreeNode(7);
  R->right->right->left = new TreeNode(13);
  R->right->right->right = new TreeNode(14);
  R->right->right->right->left = new TreeNode(15);
  root = R;
}
void printPreOrder(TreeNode* R)
{
  if (R == NULL)
	return;
  cout << R->val << " ";
  printPreOrder(R->left);
  printPreOrder(R->right);
}
void printInOrder(TreeNode* R)
{
  if (R == NULL)
	return;
  printInOrder(R->left);
  cout << R->val << " ";
  printInOrder(R->right);
}
void printPostOrder(TreeNode* R)
{
  if (R == NULL)
	return;
  printPostOrder(R->left);
  printPostOrder(R->right);
  cout << R->val << " ";
}
void printLevelOrder(TreeNode* R)
{
  queue<TreeNode*> Q;
  Q.push(R);
  while (!Q.empty())
  {
	int N = Q.size();
	for (int i = 0; i < N; i++)
	{
	  TreeNode* t = Q.front();
	  cout << t->val << " ";
	  if (t->left != NULL) Q.push(t->left);
	  if (t->right != NULL) Q.push(t->right);
	  Q.pop();
	}
	cout << endl;
  }
}
vector<int> rightTreeView(TreeNode* R)
{
  queue<TreeNode*> Q;
  vector<int> ans;
  Q.push(R);
  while (!Q.empty())
  {
	vector<int> L;
	int N = Q.size();
	for (int i = 0; i < N; i++)
	{
	  TreeNode* t = Q.front();
	  L.push_back(t->val);
	  if (t->left != NULL) Q.push(t->left);
	  if (t->right != NULL) Q.push(t->right);
	  Q.pop();
	}
	ans.push_back(L[(L.size()-1)]);
  }
  return ans;
}
vector<vector<int> > verticalOrderTraversal(TreeNode* A)
{
  queue<TreeInfo*> Q;
  Q.push(new TreeInfo(A, 0));
  unordered_map<int, vector<int>> umap;
  while (!Q.empty())
  {
	TreeInfo* t = Q.front();
	umap[t->M].push_back(t->R->val);
	if (t->R->left != NULL)
	{
	  Q.push(new TreeInfo(t->R->left, t->M - 1));
	}
	if (t->R->right != NULL)
	{
	  Q.push(new TreeInfo(t->R->right, t->M + 1));
	}
	Q.pop();
  }
  int maxi = INT_MIN, mini = INT_MAX;
  for (auto a = umap.begin(); a != umap.end(); a++)
  {
	maxi = max(maxi, a->first);
	mini = min(mini, a->first);
  }
  int k = 0;
  int N = maxi - mini + 1;
  vector<vector<int>> ans(N, vector<int>());
  for (int i = mini; i <= maxi; i++)
  {
	for (auto a = umap[i].begin(); a != umap[i].end(); a++)
	{
	  ans[k].push_back(*a);
	}
	k++;
  }
  return ans;
}
vector<int> leftViewTree(TreeNode* r)
{
  vector<int> ans;
  queue<TreeNode*> Q;
  Q.push(r);
  while (!Q.empty())
  {
	int s = Q.size();
	for (int i = 0; i < s; i++)
	{
	  TreeNode* t = Q.front();
	  if (i == 0) ans.push_back(t->val);
	  if (t->left != NULL) Q.push(t->left);
	  if (t->right != NULL) Q.push(t->right);
	  Q.pop();
	}
  }
  return ans;
}

int main()
{
  cout << "Left/Right/Top/Bottom View of tree\n";
  createTree();
  TreeNode* t = root;
  printLevelOrder(t);
  cout << endl;
  vector<int> ans = leftViewTree(t);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  return 0;
}