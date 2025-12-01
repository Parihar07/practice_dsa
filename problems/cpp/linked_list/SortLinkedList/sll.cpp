#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* A, ListNode* B);
ListNode* sortList(ListNode* A);
ListNode* CreateLinkedList(vector<int> A);
ListNode* getMiddleNode(ListNode* A);

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

ListNode* getMiddleNode(ListNode* A) {
  ListNode* s = A, * f = A;
  while (f != NULL && f->next != NULL && f->next->next != NULL)
  {
	s = s->next;
	f = f->next->next;
  }
  return s;
}

ListNode* sortList(ListNode* A)
{
  ListNode* L = A;
  ListNode* p1 = NULL, * p2 = NULL, * t = NULL;

  if (A == NULL)
	return A;
  if (A->next == NULL)
	return A;
  p1 = A;
  t = getMiddleNode(A);
  p2 = t->next;
  t->next = NULL;
  t = p1;
 /* while (t != NULL)
  {
	cout << t->val << " ";
	t = t->next;
  }
  cout << endl;
  t = p2;
  while (t != NULL)
  {
	cout << t->val << " ";
	t = t->next;
  }
  cout << endl;*/
  p1 = sortList(p1);
  p2 = sortList(p2);

  L = mergeTwoLists(p1, p2);

  return L;
}

int main()
{
  vector<int> vA = { 3};
  ListNode* All = CreateLinkedList(vA);
  ListNode* t = sortList(All);
  while (t != NULL)
  {
	cout << t->val << " ";
	t = t->next;
  }
  cout << endl;
  return 0;
}