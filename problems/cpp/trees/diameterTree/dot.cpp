#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} *root;

void createBalancedTree();
void printPreOrder(TreeNode* R);
void printLevelOrder(TreeNode* R);
int diameterTree(TreeNode* r);
int diameterTreeHelper(TreeNode* r, int& m);
int heightTree(TreeNode* r);
int heightTree(TreeNode* r)
{
  if (r == NULL)return -1;
  int lh = heightTree(r->left);
  int rh = heightTree(r->right);
  return max(lh, rh) + 1;
}
void createBalancedTree()
{
  TreeNode* R = new TreeNode(2);

  R->left = new TreeNode(3);
  R->right = new TreeNode(4);

  R->left->left = new TreeNode(5);
  R->left->right = new TreeNode(6);

  R->right->right = new TreeNode(7);
  R->right->left = new TreeNode(8);
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

int diameterTreeHelper(TreeNode* r, int& m)
{
  if (r == NULL) return -1;
  int lh = diameterTreeHelper(r->left, m);
  int rh = diameterTreeHelper(r->right, m);
  int h = max(lh, rh) + 1;
  m = max((lh + rh + 2), m);
  return h;
}


int diameterTree(TreeNode* r)
{
  int d = INT_MIN;
  diameterTreeHelper(r, d);
  return d;
}


int main()
{
  cout << "hello Diameter of tree\n";
  createBalancedTree();
  TreeNode* t = root;
  printLevelOrder(t);
  cout << "height of tree :" << heightTree(t) << endl;
  cout << "Diameter of tree :" << diameterTree(t) << endl;
  return 0;
}