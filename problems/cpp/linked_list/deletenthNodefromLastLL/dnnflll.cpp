#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
  
} *head;

ListNode* CreateLinkedList(vector<int> A);
void printLL();
ListNode* removeNthFromEnd(ListNode* A, int B);

ListNode* removeNthFromEnd(ListNode* A, int B) {
  ListNode* t = head, * p = NULL, * d = NULL;
  int c = 0;
  while (t != NULL)
  {
	c++;
	if (c >= B)
	{
	  if (d == NULL)
	  {
		d = head;
	  }
	  else {
		p = d;
		d = d->next;
	  }
	}
	t = t->next;
  }
  if (c < B)
  {
	d = head;
	head = head->next;
	delete(d);
	d = NULL;

  } else if (p != NULL)
  {
	p->next = d->next;
	delete(d);
	d = NULL;
  }
  else if(d!=NULL){
	head = d->next;
	delete(d);
	d = NULL;
  }
  return head;
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

void printLL()
{
  ListNode* t = head;
  while (t != NULL)
  {
	cout << t->val << " ";
	t = t->next;
  }
  cout << endl;
}
int main()
{
  vector<int> A = { 20,380,349,322,389,424,429,120,64,691,677,58,327,631,916,203,484,918,596,252,509,644,33,460 };
  head = CreateLinkedList(A);
  printLL();
  
 head = removeNthFromEnd(head, 26);
  printLL();
  return 0;
}