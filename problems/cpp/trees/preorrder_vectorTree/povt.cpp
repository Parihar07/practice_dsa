#include<iostream>
#include<vector>
#include<queue>

#include"../common/common.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} *root;


void createTree();
TreeNode* createTreeNode(int val);
vector<int> inorderTraversal(TreeNode* A);
void createTree();
void printPreOrder(TreeNode* R);
void printInOrder(TreeNode* R);
void printPostOrder(TreeNode* R);
void createVectorInOrder(TreeNode* R, vector<int>& vA);
int getHieghtTree(TreeNode* R);
void printLevelOrder(TreeNode* R);
vector<vector<int> > levelOrderVector1(TreeNode* root);
vector<vector<int> > levelOrderVector(TreeNode* root);

TreeNode* createTreeNode(int val)
{
  return new TreeNode(val);
}

void createVectorInOrder(TreeNode* R, vector<int>& vA)
{
  if (R == NULL)
	return;
  createVectorInOrder(R->left, vA);
  vA.push_back(R->val);
  createVectorInOrder(R->right, vA);
}

vector<int> inorderTraversal(TreeNode* A)
{
  vector<int> ans;
  createVectorInOrder(A, ans);
  return ans;
}

void createTree()
{
  TreeNode* tn = new TreeNode(2);

  tn->left = createTreeNode(3);
  tn->right = createTreeNode(4);
  tn->left->left = createTreeNode(5);
  tn->left->right = createTreeNode(6);
  tn->left->left->left = createTreeNode(9);
  tn->left->left->right = createTreeNode(10);
  tn->right->left = createTreeNode(8);
  tn->right->right = createTreeNode(7);
  tn->right->right->left = createTreeNode(13);
  tn->right->right->right = createTreeNode(14);
  tn->right->right->right->left = createTreeNode(15);

  root = tn;
}

void printPreOrder(TreeNode* R)
{
  if (R == NULL)
	return;
  cout << R->val << " ";
  printPreOrder(R->left);
  printPreOrder(R->right);
}

void printInOrder(TreeNode* R)
{
  if (R == NULL)
	return;
  printInOrder(R->left);
  cout << R->val << " ";
  printInOrder(R->right);
}

void printPostOrder(TreeNode* R)
{
  if (R == NULL)
	return;
  printPostOrder(R->left);
  printPostOrder(R->right);
  cout << R->val << " ";
}

int getHieghtTree(TreeNode* R)
{
  int hr = 0, hl = 0;
  if (R == NULL)
  {
	return 0;
  }
  hr = getHieghtTree(R->left);
  hl = getHieghtTree(R->right);
  return 1 + _max(hr, hl);
}

void printLevelOrder(TreeNode* R)
{
  queue<TreeNode*> q;
  q.push(R);
  while (!q.empty())
  {

	TreeNode* t = q.front();
	cout << t->val << " ";
	if (t->left != NULL)
	  q.push(t->left);
	if (t->right != NULL)
	  q.push(t->right);
	q.pop();
  }
  cout << endl;
}

struct TreeInfo {
  TreeNode* R;
  int level;
  TreeInfo(int l, TreeNode* r) :level(l), R(r) {};
};

/*
void buildVector(TreeNode *root, int depth, vector<vector<int> > &ret) {
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());

    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1, ret);
    buildVector(root->right, depth + 1, ret);
}

vector<vector<int> > Solution::levelOrder(TreeNode* root) {
    vector<vector<int> > ret;
    buildVector(root, 0, ret);
    return ret;
}
*/

vector<vector<int> > levelOrderVector1(TreeNode* root) {
  queue<TreeInfo*> q;
  int level = getHieghtTree(root);
  vector<vector<int>> list(level,vector<int>());
  TreeInfo* ti = new TreeInfo(0, root);
  q.push(ti);
  while (!q.empty())
  {
	TreeInfo* t = q.front();
	list[t->level].push_back(t->R->val);

	if (t->R->left != NULL)
	{
	  TreeInfo* L = new TreeInfo(t->level + 1, t->R->left);
	  q.push(L);
	}
	if (t->R->right != NULL)
	{
	  TreeInfo* R = new TreeInfo(t->level + 1, t->R->right);
	  q.push(R);
	}
	q.pop();
  }
  return list;
}

vector<vector<int> > levelOrderVector(TreeNode* root)
{
  queue<TreeNode*> q;
  vector<vector<int>> ans;
  return ans;
}
int main()
{
  cout << "hello tree world\n";
  vector<int> ans;
  createTree();
  TreeNode* t = root;
  printLevelOrder(t);
  vector<vector<int>>L;
  L = levelOrderVector(t);
  for (auto a = L.begin(); a != L.end(); a++)
  {
	for (auto b = a->begin(); b != a->end(); b++)
	{
	  cout << *b << " ";
	}
	cout << endl;
  }
  return 0;
}