#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}*root;

void printLevelOrder(TreeNode* R);
void createTree();
void createBSTTree();
int checkforBST(TreeNode* r, long mini, long maxi);
int countNode(TreeNode* r);
int largestBSTSubtreeHelper(TreeNode* a, int mini, int maxi, int &c);
int largestBSTSubtree(TreeNode* A);

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
int countNode(TreeNode* r)
{
  if (r == NULL)return 0;
  int lc = countNode(r->left);
  int rc = countNode(r->right);
  return lc + rc + 1;
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

int largestBSTSubtreeHelper(TreeNode* r, int mini, int maxi, int &cnt)
{
  static int c = 0;
  if (r == NULL) return 1;
  if (r->val <mini || r->val> maxi) {
	return 0;
  }
  else {
	c++;
  }
  cnt = max(cnt, c);

  int lt = largestBSTSubtreeHelper(r->left, mini, r->val,cnt);
  int rt = largestBSTSubtreeHelper(r->right, r->val, maxi,cnt);
  return lt & rt;
}

int largestBSTSubtree(TreeNode* A)
{
  int cnt = 0;
  largestBSTSubtreeHelper(A, INT_MIN, INT_MAX,cnt);
  return cnt;
}
int main()
{
  cout << "Largert BST in a tree\n";
  createBSTTree();
  TreeNode* t = root;
  printLevelOrder(t);
  cout << "Largert BST: " << largestBSTSubtree(t) << endl;

  return 0;
}