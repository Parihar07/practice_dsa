#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} *root;

void printLevelOrder(TreeNode* R);
void createTree();
void printPreOrder(TreeNode* R);
vector<int> topViewTree(TreeNode* A);
vector<int> topViewTreeIterative(TreeNode* A);
void topViewRecursive(TreeNode* r, int d, int& s, int& e);

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
void printPreOrder(TreeNode* R)
{
  if (R == NULL)
	return;
  cout << R->val << " ";
  printPreOrder(R->left);
  printPreOrder(R->right);
}

struct TreeInfo {
  TreeNode* R;
  int axis;
  TreeInfo(TreeNode* r, int x) :R(r), axis(x) {};
};

vector<int> topViewTreeIterative(TreeNode* A)
{
  vector<int> ans;
  unordered_map<int, int> um;
  queue<TreeInfo*> Q;
  Q.push(new TreeInfo(A, 0));
  int maxi = INT_MIN, mini = INT_MAX;

  while (!Q.empty())
  {
	TreeInfo* t = Q.front();
	if (um.find(t->axis) == um.end())
	{
	  um[t->axis] = t->R->val;
	  maxi = max(maxi, t->axis);
	  mini = min(mini, t->axis);
	}

	if (t->R->left != NULL)
	{
	  Q.push(new TreeInfo(t->R->left, t->axis - 1));
	}
	if (t->R->right != NULL)
	{
	  Q.push(new TreeInfo(t->R->right, t->axis + 1));
	}

	Q.pop();
  }
  for (int i = mini; i <= maxi; i++)
  {
	ans.push_back(um[i]);
  }
  return ans;
}

unordered_map<int, int>gUM;

void topViewRecursive(TreeNode* r, int d, int& s, int& e)
{
  if (r == NULL)
	return;
  if (gUM.find(d) == gUM.end())
  {
	gUM[d] = r->val;
	s = max(s, d);
	e = min(e, d);
  }
  topViewRecursive(r->left, d - 1, s, e);
  topViewRecursive(r->right, d + 1, s, e);
}

vector<int> topViewTree(TreeNode* A)
{
  int maxi = INT_MIN, mini = INT_MAX;
  vector<int> ans;
  topViewRecursive(A, 0, maxi, mini);
  for (int i = mini; i <= maxi; i++)
  {
	ans.push_back(gUM[i]);
  }
  return ans;
}
int main()
{
  cout << "Hello top view\n";
  createTree();
  TreeNode* t = root;
  //printLevelOrder(t);
  vector<int> ans = topViewTree(t);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  return 0;
}