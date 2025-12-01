#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
}*head;

ListNode* solve(ListNode* A) {
  ListNode* s = A, * f = A, *h = A;

  if (s == NULL || s->next == NULL)
  {
	return s;
  }

  if (s == s->next->next)
  {
	s->next->next = NULL;
  }

  while (f->next!=NULL)
  {
	s = s->next;
	f = f->next->next;
	if (f == NULL)
	  return A;
	if (s == f)
	  break;
  }
  if (f->next == NULL)
  {
	return A;
  }

  f = A;
  while (s->next != f->next)
  {
	s = s->next;
	f = f->next;
  }

  s->next = NULL;
       
  return A;
}

int main()
{
  vector<int> vA = { 1,2,3,4,5,6,7,8,9,10,11 };
  ListNode* h = NULL;
  ListNode* t = NULL;
  for (auto a = vA.begin(); a != vA.end(); a++)
  {
	t = h;
	ListNode* nw = new ListNode(*a);
	if (t == NULL)
	{
	  h = nw;
	}
	else {
	  while (t->next != NULL)
	  {
		t = t->next;
	  }
	  t->next = nw;
	}
  }
  head = h;
  t = head;

  ListNode* c = NULL;
  int cn = 0;
  while (t->next != NULL)
  {
	cout << t->val << " ";
	t = t->next;
	if ((cn++) == 5)
	{
	  c = t;
	}
  }

  t->next = c;

 // t = head;
 // while (t != NULL)
 // {
	//cout << t->val << " ";
	//t = t->next;
 // }

  t = solve(head);

  while (t != NULL)
  {
	cout << t->val << " ";
	t = t->next;
  }
  cout << endl;

  return 0;
}