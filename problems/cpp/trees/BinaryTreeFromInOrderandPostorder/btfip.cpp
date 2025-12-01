#include<iostream>
#include<unordered_map>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} *root;

unordered_map<int, int> map;

TreeNode* buildTree(vector<int>& A, vector<int>& B);
TreeNode* constructTree(vector<int>& A, vector<int>& B, int s, int e);

TreeNode* constructTree(vector<int>& A, vector<int>& B, int s, int e)
{
  int ind = 0;
  if (s>e)
	return NULL;
  TreeNode* R = new TreeNode(B[e]);
  ind = map[B[e]];
  R->left = constructTree(A, B, s, ind-1);
  R->right = constructTree(A, B, ind-1, e-1);
  return R;
}

TreeNode* buildTree(vector<int>& A, vector<int>& B) {
  int s = 0, e = (B.size() - 1);
  int i = 0;
  for (auto a : A)
	map[a] = i++;
  return  constructTree(A, B, 0, e);
}

int main()
{
  cout << "hello tree creation\n";
  vector<int> A = { 4,2,5,1,6,3,7 };
  vector<int> B = { 4,5,2,6,7,3,1 };
  root = buildTree(A, B);
  return 0;
}