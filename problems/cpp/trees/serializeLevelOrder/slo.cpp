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


int main()
{
  cout << "hello Serliazing in level order\n";
  createTree();
  TreeNode* t = root;
  printLevelOrder(t);
  vector<int> ans = serializeLevelOrder(t);
  for (auto a = ans.begin(); a != ans.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  return 0;
}