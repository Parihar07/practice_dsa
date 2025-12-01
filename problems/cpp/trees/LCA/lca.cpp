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
void createTree();
int lca(TreeNode* A, int B, int C);
int lcaHelper(TreeNode* A, int B, int C);
int findNode(TreeNode* r,int k);

void createBalancedTree()
{
  TreeNode* R = new TreeNode(2);

  R->left = new TreeNode(3);
  R->right = new TreeNode(4);

  R->left->left = new TreeNode(5);
  R->left->right = new TreeNode(6);

  //R->right->right = new TreeNode(7);
  R->right->left = new TreeNode(8);
  root = R;
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

int findNode(TreeNode* r, int k)
{
  if (r == NULL) return NULL;
  if (r->val == k) return 1;
  int lf = findNode(r->left, k);
  int rf = findNode(r->right, k);
  return lf||rf;
}


int lcaHelper(TreeNode* A, int B, int C)
{
  int val1 = B;
  int val2 = C;
  TreeNode* root = A;
  if (!findNode(root, val1) || !findNode(root, val2))
	return -1;
  int ans = lcaHelper(root, val1, val2);
  if (!ans)
	return -1;
  return ans->val;
  /*if (A == NULL) return NULL;
  
  if (A->val == B || A->val == C) return A;

  TreeNode *lp = lcaHelper(A->left, B,C);
  TreeNode *rp = lcaHelper(A->right, B,C);

  if (lp!=NULL && rp!=NULL )
  {
	return A;
  }
  return lp ? lp : rp;*/
}

int lca(TreeNode* A, int B, int C)
{
  TreeNode* t = lcaHelper(A, B, C);
  return t?t->val:-1;
}


int main()
{
  cout << "hello LCA\n";
  createTree();
  TreeNode* t = root;
  printLevelOrder(t);
  cout << "Found : "<<findNode(t, 17) << endl;
  cout << "LCA: " << lca(t, 90, 19);
  cout << endl;
  return 0;
}