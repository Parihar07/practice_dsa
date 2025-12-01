#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*root;

void printLevelOrder(TreeNode* R);
void createBSTTree();
void createBSTTree()
{
  TreeNode* R = new TreeNode(25);
  R->left = new TreeNode(20);
  R->left->left = new TreeNode(10);
  R->left->right = new TreeNode(22);
  R->left->left->left = new TreeNode(5); // actual 5
  R->left->left->right = new TreeNode(12);

  R->right = new TreeNode(36);
  R->right->left = new TreeNode(30);
  R->right->left->left = new TreeNode(28);
  R->right->right = new TreeNode(40);
  R->right->right->right = new TreeNode(48);
  R->right->right->left = new TreeNode(38);
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

int findDepth(TreeNode* rt, int v)
{
  if (rt == NULL) return -1;
  if (rt->val == v)return 0;
  int l = 0, r = 0;
  if (v < rt->val)
  {
	l = 1 + findDepth(rt->left, v);
  }
  else {
	r = 1 + findDepth(rt->right, v);
  }
  return l | r;
}

int getDistanceNode(TreeNode* A, int B, int C)
{
  if (A == NULL) return 0;
  int l = 0, r = 0;
  if (B<A->val && C>A->val)
  {
	l = findDepth(A, B);
	r = findDepth(A, C);
	return l + r;
  }
  if (B == A->val)
  {
	return findDepth(A, C);
  }
  if (B < A->val && C < A->val)
  {
	l = getDistanceNode(A->left, B, C);
  }
  else
  {
	r = getDistanceNode(A->right, B, C);
  }
  return l | r;
}

int main()
{
  cout << "Distance between Nodes\n";
  createBSTTree();
  TreeNode* t = root;
  printLevelOrder(t);

  int d = 0;
  cout << "Depth: " << findDepth(t, 25) << endl;
  cout << "Depth: " << findDepth(t, 10) << endl;
  cout << "Depth: " << findDepth(t, 28) << endl;
  cout << "Depth: " << findDepth(t, 36) << endl;

  cout << "Distance between node: " << getDistanceNode(t, 10, 22) << endl;
  cout << "Distance between node: " << getDistanceNode(t, 36, 28) << endl;
  cout << "Distance between node: " << getDistanceNode(t, 20, 36) << endl;
  cout << "Distance between node: " << getDistanceNode(t, 10, 5) << endl;
  return 0;
}