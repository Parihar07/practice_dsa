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

void createBalancedTree()
{
  TreeNode* R = new TreeNode(2);

  R->left = new TreeNode(3);
  //R->right = new TreeNode(4);

  //R->left->left = new TreeNode(5);
  //R->left->right = new TreeNode(6);

  //R->right->right = new TreeNode(7);
  //R->right->left = new TreeNode(8);
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

int heightTree(TreeNode *r)
{
  if (r == NULL)return -1;
  int lv = heightTree(r->left);
  int rv = heightTree(r->right);
 return max(lv, rv) + 1;
}
int isBalanced(TreeNode* A) {
  if (A == NULL)return 1;

  int lh = heightTree(A->left);
  int rh = heightTree(A->right);

  if (abs(lh - rh) > 1)
  {
	return 0;
  }
  return  isBalanced(A->left) && isBalanced(A->right);
}

int main()
{
  createBalancedTree();
  TreeNode* t = root;
  printLevelOrder(t);
  printPreOrder(t);
  cout << endl;
  cout << "Is balanced : " << isBalanced(t) << endl;
  return 0;
}