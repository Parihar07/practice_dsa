#include<iostream>
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
bool binarySearchTree(TreeNode* r, int k);

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
void createTree()
{
  TreeNode* R = new TreeNode(12);
  R->left = new TreeNode(10);
  R->right = new TreeNode(14);
  R->left->left = new TreeNode(7);
  R->left->right = new TreeNode(11);
  R->left->left->left = new TreeNode(6);
  R->left->left->right = new TreeNode(8);
  R->right->left = new TreeNode(13);
  R->right->right = new TreeNode(17);
  R->right->right->left = new TreeNode(15);
  R->right->right->right = new TreeNode(19);
  R->right->right->right->left = new TreeNode(18);
  root = R;
}
bool binarySearchTree(TreeNode* r, int k)
{
  if (r == NULL)
  {
	return false;
  }
  if (r->val == k)
  {
	return true;
  }
  int al = 0, ar = 0;
  if (k < r->val) {
	al = binarySearchTree(r->left, k);
  }
  else {
	ar = binarySearchTree(r->right, k);
  }
  return al | ar;
}
int main()
{
  cout << "Binary search tree\n";
  createTree();
  TreeNode* t = root;
  printLevelOrder(t);
  cout << "Result : " << binarySearchTree(t, 14) << endl;
  return 0;
}