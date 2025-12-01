
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} *root;

void printPreOrder(TreeNode* R);
void printLevelOrder(TreeNode* R);
void createTree();
vector<int> InorderTravesal(TreeNode* r);
vector<int> morrisInorderTraversal(TreeNode* A);


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
void InorderTravesalHelper(TreeNode* r, vector<int>& ans)
{
  if (r == NULL) return;
  InorderTravesalHelper(r->left, ans);
  ans.push_back(r->val);
  InorderTravesalHelper(r->right, ans);

}
vector<int> InorderTravesal(TreeNode* r)
{
  vector<int> ans;
  InorderTravesalHelper(r, ans);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  return ans;
}

vector<int> morrisInorderTraversal(TreeNode* A)
{
  vector<int> ans;
  TreeNode* t = NULL, * d = NULL, * c = A;
  if (A == NULL)
	return ans;
  while (c != NULL)
  {
	if (c->left == NULL)
	{
	  ans.push_back(c->val);
	  d = c;
	  c = c->right;
	  d->right = NULL;
	}
	else {
	  if (c->left != t)
	  {
		t = c->left;
		while (t->right != NULL)
		  t = t->right;
		t->right = c;
		c = c->left;
	  }
	  else {
		ans.push_back(c->val);
		t = c;
		c = c->right;
	  }
	}

  }
  cout << A->val << ":printing";
  return ans;
}

vector<int> solve(TreeNode* A) {
  vector<int> ans;
  TreeNode* current, * pre;

  if (A == NULL)
	return ans;

  current = A;
  while (current != NULL) {

	if (current->left == NULL) {
	  ans.push_back(current->val);
	  current = current->right;
	}
	else {

	  // Find the inorder predecessor of current
	  pre = current->left;
	  while (pre->right != NULL && pre->right != current)
		pre = pre->right;

	  // Make current as the right child of its inorder predecessor
	  if (pre->right == NULL) {
		pre->right = current;
		current = current->left;
	  }
	  else {
		pre->right = NULL;
		ans.push_back(current->val);
		current = current->right;
	  }
	}
  }
  return ans;
}
int main()
{
  cout << "Hello Morris InorderTraversel\n";
  createTree();
  TreeNode* t = root;
  printLevelOrder(t);
  cout << endl;
  InorderTravesal(t);
  cout << endl;
  vector<int> ans = morrisInorderTraversal(t);
  for (auto a : ans)
  {
	cout << a << " ";
  }
  cout << endl;
  cout << endl;
  return 0;
}