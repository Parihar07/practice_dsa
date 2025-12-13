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
void createBSTTree();
bool binarySearchTree(TreeNode* r, int k);
int isValidBST(TreeNode* A);
int findMax(TreeNode* r);
int findMin(TreeNode* r);
int checkforBST(TreeNode* r, long mini, long maxi);

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
  R->left->left->left = new TreeNode(89); // actual 5
  R->left->left->right = new TreeNode(12);

  R->right = new TreeNode(36);
  R->right->left = new TreeNode(30);
  R->right->left->left = new TreeNode(28);
  R->right->right = new TreeNode(40);
  R->right->right->right = new TreeNode(48);
  R->right->right->left = new TreeNode(38);
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

int findMax(TreeNode* r)
{
  if (r == NULL) return INT_MIN;
  int lm = findMax(r->left);
  int rm = findMax(r->right);
  return max(r->val, max(lm, rm));
}

int findMin(TreeNode* r)
{
  if (r == NULL) return INT_MAX;
  int lm = findMin(r->left);
  int rm = findMin(r->right);
  return min(r->val, min(lm, rm));
}

int checkforBST(TreeNode* r, long mini, long maxi)
{
  if (r == NULL) return 1;
  if (r->val <= mini || r->val >= maxi)
	return 0;
  int lm = checkforBST(r->left, mini, r->val);
  int rm = checkforBST(r->right, r->val, maxi);
  return lm & rm;
}
int isValidBST(TreeNode* A)
{
  return checkforBST(A, LONG_MIN, LONG_MAX);
}
int main()
{
  cout << "Binary search tree\n";
  TreeNode* t = root;
  printLevelOrder(t);
  cout << "Max : " << findMax(t) << endl;
  cout << "Min : " << findMin(t) << endl;
  cout << "if BST : " << isValidBST(t) << endl;
  return 0;
}