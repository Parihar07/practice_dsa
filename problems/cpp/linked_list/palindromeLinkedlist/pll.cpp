#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
} *A;

int lPalin(ListNode* A);
int lPalinBF(ListNode* A);
ListNode* reverseLL(ListNode* h);
int lPalinBF(ListNode* A) {
  ListNode* p = A, * q = A, * t = NULL;
  if (A == NULL)
  {
	return 0;
  }

  while (q->next != NULL)
  {
	q = q->next;
  }

  while (1)
  {
	t = p;
	if (p->val != q->val) return 0;
	p = p->next;

	//if (p == NULL || p->next == q || p == q) break;
	while (t->next != q)
	{
	  t = t->next;
	}
	q = t;
  }
  return 1;
}

ListNode* reverseLL(ListNode* h)
{
  ListNode* p = h, * q = h, * r = NULL;
  q = q->next;

  while (q != NULL)
  {
	r = q->next;
	q->next = p;
	p = q;
	q = r;
  }
  h->next = NULL;
  return p;
}

int lPalin(ListNode* A) {
  ListNode* s = A, * f = A;

  if (A->next == NULL)
  {
	return 1;
  }
  if (A->next->next == NULL)
  {
	if (A->val == A->next->val)
	  return 1;
	else
	  return 0;
  }

  while (f != NULL && f->next != NULL && f->next->next != NULL)
  {
	s = s->next;
	f = f->next->next;
  }

  ListNode* h1 = A, * h2 = s->next;
  s->next = NULL;

  h2 = reverseLL(h2);

  while (h1 != NULL && h2 !=NULL)
  {
	if (h1->val != h2->val)
	  return 0;
	h1 = h1->next;
	h2 = h2->next;
  }
  int cnt = 0;
  while (h1 != NULL)
  {
	cnt++;
	h1 = h1->next;
  }
  if (cnt >= 2)
	return 0;

  cnt = 0;
  while (h2 != NULL)
  {
	cnt++;
	h2 = h2->next;
  }
  if (cnt >= 2)
	return 0;
  return 1;
  // ListNode* t = h1;
// while (t)
// {
   //cout << t->val << " ";
   //t = t->next;
// }
// cout << endl;
// t = h2;
// while (t)
// {
   //cout << t->val << " ";
   //t = t->next;
// }
// cout << endl;
}

int main()
{
  vector<int> vA = { 3 , 1 };
  ListNode* head = NULL;
  ListNode* t = NULL;
  A = head;
  for (auto i = vA.begin(); i != vA.end(); i++)
  {
	t = head;
	ListNode* nw = new ListNode(*i);
	if (head == NULL)
	{
	  head = nw;
	}
	else {
	  while (t->next != NULL)
	  {
		t = t->next;
	  }
	  t->next = nw;
	}
  }
  A = head;
  t = A;
  while (t != NULL)
  {
	cout << t->val << " ";
	t = t->next;
  }
  cout << endl;
  cout << "Palindrome status : " << lPalin(A) << endl;

  return 0;
}