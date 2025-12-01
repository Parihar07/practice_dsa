#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} *root;

void createTree();
void printLevelOrder(TreeNode* R);
vector<int> serializeLevelOrder(TreeNode* A);
TreeNode* deserializeLevelOrder(vector<int> A);
void printPreOrder(TreeNode* R);
vector<int> serializeLevelOrder(TreeNode* A);

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
vector<int> serializeLevelOrder(TreeNode* A) {
  queue<TreeNode*> Q;
  vector<int> ans;
  Q.push(A);
  while (!Q.empty())
  {
	TreeNode* t = Q.front();
	if (t != NULL)
	{
	  ans.push_back(t->val);
	  if (t->left == NULL) Q.push(NULL);
	  else Q.push(t->left);

	  if (t->right == NULL) Q.push(NULL);
	  else Q.push(t->right);

	  Q.pop();
	}
	else {
	  ans.push_back(-1);
	  Q.pop();
	}
  }
  return ans;
}

//struct TreeDesInfo {
//  TreeNode* P;
//  TreeNode* R;
//  TreeDesInfo(TreeNode* p, TreeNode* r) :P(p), R(r) {}
//};
void printPreOrder(TreeNode* R)
{
  if (R == NULL)
	return;
  cout << R->val << " ";
  printPreOrder(R->left);
  printPreOrder(R->right);
}

TreeNode* deserializeLevelOrder(vector<int> A)
{
  TreeNode* root = NULL;
  queue<TreeNode*> Q;
  for (int i = 0; i < A.size();)
  {
	if (Q.empty())
	{
	  root = new TreeNode(A[i]);
	  Q.push(root);
	  i += 1;
	}
	else {
	  TreeNode* t = Q.front();
	  Q.pop();
	  int li = i, ri = i + 1;
	  if (A[li] != -1)
	  {
		TreeNode* cur = new TreeNode(A[li]);
		if (t != NULL)
		  t->left = cur;
		Q.push(cur);
	  }
	  else {
		if (t != NULL)
		{
		  t->left = NULL;
		}
	  }

	  if (A[ri] != -1)
	  {
		TreeNode* cur = new TreeNode(A[ri]);
		if (t != NULL)
		{
		  t->right = cur;
		}
		Q.push(cur);
	  }
	  else {
		if (t != NULL)
		{
		  t->right = NULL;
		}
	  }
	  i = ri + 1;
	}
  }
  return root;
}

int main()
{
  cout << "hello Serliazing in level order\n";
  createTree();
  TreeNode* t = root;
  printLevelOrder(t);
  cout << endl;
  printPreOrder(t);
  cout << endl;
  vector<int> ans = serializeLevelOrder(t);
  for (auto i = ans.begin(); i != ans.end(); i++)
  {
	cout << *i << ",";
  }
  cout << endl;

  vector<int> LV = { 2,3,4,5,6,8,7,9,10,-1,-1,-1,-1,13,14,-1,-1,-1,-1,-1,-1,15,-1,-1,-1 };

  TreeNode* tt = deserializeLevelOrder(LV);
  printLevelOrder(tt);
  printPreOrder(tt);
  cout << endl;
  return 0;
}