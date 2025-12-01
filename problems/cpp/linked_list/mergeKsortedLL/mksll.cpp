#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode():val(0),next(NULL) {};
} *head;

class heap {
  int slSize;
  int nodeCount;
  vector<ListNode*> nodeList;
  vector<int> SL;
public:                           
  heap(int k) :nodeCount(k) {};
  ListNode* getMin();
  void insertdata(ListNode* d);
  void insertHeapData(int v);
  void popMin();

};

ListNode* heap::getMin()
{
  return nodeList[0];
}
void heap::insertdata(ListNode* d)
{
  nodeList.push_back(d);
  return;
}
void heap::insertHeapData(int v)
{
  SL.push_back(v);
  slSize = SL.size() - 1;
  int i = slSize;
  int p = ((i - 1) / 2);
  while (p >= 0 && SL[i] < SL[p])
  {
	swap(SL[i], SL[p]);
	i = p;
	p = ((i - 1) / 2);
  }
}
void heap::popMin()
{

  return;
}

ListNode* CreateLL(vector<int> A);
ListNode* mergeSortedList(ListNode* A, ListNode* B);
ListNode* CreateLL(vector<int> A)
{
  ListNode* t = NULL, * h = NULL;
  for (int i = 0; i < A.size(); i++)
  {
	ListNode* nw = new ListNode(A[i]);
	if (t == NULL) {
	  t = nw;
	  h = t;
	}
	else {
	  while (t->next != NULL)
		t = t->next;
	  t->next = nw;
	}
  }
  head = h;
  return h;
}
ListNode* mergeSortedList(ListNode* A, ListNode* B)
{
  if (A == NULL || B == NULL)
  {
	return A ? B : A;
  }

  ListNode* H1 = NULL, * H2 = NULL, * t = NULL, * ML = NULL;
  if (A->val < B->val)
  {
	H1 = A; H2 = B;
  }
  else {
	H1 = B; H2 = A;
  }
  t = H1; ML = H1; H1 = H1->next;
 
  while (H1 != NULL && H2 != NULL)
  {
	if (H1->val < H2->val)
	{
	  t->next = H1;
	  H1 = H1->next;
	  t = t->next;
	}
	else {
	  t->next = H2;
	  H2 = H2->next;
	  t = t->next;
	}
  }
  if (H1 == NULL)
	t->next = H2;
  if (H2 == NULL)
	t->next = H1;
  return ML;
}
void printtLL(ListNode* r)
{
  ListNode* t = r;
  while (t != NULL)
  {
	cout << t->val << " ";
	t = t->next;
  }
  return;
}
int main()
{
  vector<int> A = { 2,4,7,9,11 };
  ListNode* aLL = CreateLL(A);
  vector<int> B = { 3,5,10,12,14 };
  ListNode* bLL = CreateLL(B);
  vector<int> C = { 6,8,13,15 };
  ListNode* cLL = CreateLL(C);

  vector<ListNode*> LL = { cLL,bLL,aLL };
  heap* H = new heap((int)LL.size());
  for (int i = 0; i < LL.size(); i++)
  {
	H->insertdata(LL[i]);
  }

  return 0;
}