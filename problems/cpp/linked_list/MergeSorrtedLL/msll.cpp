#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
} *head;

ListNode* CreateLinkedList(vector<int> A);
ListNode* mergeTwoLists(ListNode* A, ListNode* B);

ListNode* CreateLinkedList(vector<int> A)
{
  ListNode* h = NULL;
  ListNode* t = h;
  for (auto a = A.begin(); a != A.end(); a++)
  {
	ListNode* nw = new ListNode(*a);
	if (t == NULL) {
	  h = nw;
	  t = h;
	}
	else {
	  while (t->next != NULL)
	  {
		t = t->next;
	  }
	  t->next = nw;
	}
  }
  return h;
}

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
  ListNode* H1 = NULL, * H2 = NULL, * t = NULL, * h = NULL;;
  if (A == NULL || B == NULL)
	return A ? A : B;

  if (A->val < B->val)
  {
	H1 = A;
	H2 = B;
  }
  else {
	H1 = B;
	H2 = A;
  }
  h = t = H1;
  H1 = H1->next;
  while (H1 != NULL && H2 != NULL)
  {
	if (H1->val < H2->val) {
	  t->next = H1;
	  H1 = H1->next;
	}
	else {
	  t->next = H2;
	  H2 = H2->next;
	}
	t = t->next;
  }
  if (H1 == NULL)
  {
	t->next = H2;
  }
  else {
	t->next = H1;
  }
  return h;
}

int main()
{
  vector<int> A = { 5 };
  vector<int> B = { 4 };

  ListNode* All = NULL, * Bll = NULL, * t = NULL;

  All = CreateLinkedList(A);
  Bll = CreateLinkedList(B);
  t = mergeTwoLists(NULL, Bll);
  while (t != NULL)
  {
	cout << t->val << " ";
	t = t->next;
  }
  cout << endl;
  return 0;
}