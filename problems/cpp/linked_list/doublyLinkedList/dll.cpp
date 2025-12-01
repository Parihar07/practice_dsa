#include<iostream>
#include<vector>
using namespace std;

struct DoubleLinkList {
  int v;
  DoubleLinkList* prev;
  DoubleLinkList* next;
  DoubleLinkList(int val) : v(val), prev(NULL), next(NULL) {}
}*head;

void createDL(vector<int>& A);
DoubleLinkList* reverseDL(DoubleLinkList* r);
DoubleLinkList* reverseDL2(DoubleLinkList* r);

void createDL(vector<int>& A)
{
  DoubleLinkList* t = NULL, * h = NULL;

  for (int i = 0; i < A.size(); i++)
  {
	DoubleLinkList* nw = new DoubleLinkList(A[i]);
	if (t == NULL)
	{
	  t = nw;
	  h = t;
	}
	else {
	  while (t->next != NULL)
		t = t->next;
	  nw->prev = t;
	  t->next = nw;
	}
	head = h;
  }
  return;
}

DoubleLinkList* reverseDL(DoubleLinkList* r)
{
  if (r == NULL) return NULL;
  DoubleLinkList* p = r, * N = NULL, * P = NULL, *t=NULL;
  while (p->next != NULL)
	p = p->next;
  t = p;
  while (t != NULL)
  {	
	N = t->next;
	t->next = t->prev;
	t->prev = N;
	t = t->next;
  }
  head = p;
  return p;
}

DoubleLinkList* reverseDL2(DoubleLinkList* r)
{
  if (r == NULL) return NULL;
  DoubleLinkList * P = NULL, * t = NULL;
  t = r;
  while (t != NULL)
  {
	P = t;
	t = t->next;
	P->next = P->prev;
	P->prev = t;
  }
  head = P;
  return P;
}

int main()
{
  vector<int> A = { 1,2,3,4,5,6,7,8,9 };
  createDL(A);
  DoubleLinkList* t = head;

  while (t != NULL)
  {
	cout << t->v << " ";
	t = t->next;
  }

  cout << endl;
  t = reverseDL2(head);

  while (t != NULL)
  {
	cout << t->v << " ";
	t = t->next;
  }
  cout << endl;
  return 0;
}