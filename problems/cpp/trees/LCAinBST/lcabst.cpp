#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*root;

void createBSTTree();
void printLevelOrder(TreeNode* R);

TreeNode* LCAinBSTHelper(TreeNode* A, int B, int C);
int LCAinBST(TreeNode* A, int B, int C);
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
TreeNode *LCAinBSTHelper(TreeNode* A, int B, int C)
{
  if (A == NULL)  return NULL;
  if (B < A->val && C < A->val) return LCAinBSTHelper(A->left, B, C);
  else if (B > A->val && C > A->val) return LCAinBSTHelper(A->right, B, C);
  return A;
}

int LCAinBST(TreeNode* A, int B, int C)
{
  TreeNode* t = LCAinBSTHelper(A, B, C);
  return t?t->val:-1;
}

int main()
{
  cout << "LCA in BST\n";
  createBSTTree();
  TreeNode* t = root;
  printLevelOrder(t);
  cout << "Root: " << LCAinBST(t, 30,40) << endl;
  return 0;
}