#include<iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int x) { val = x; next = NULL; }
} *head;

void insertNode(int data, int pos);
void deleteNode(int pos);
void print_ll();

void deleteNode(int pos)
{
  if (head == NULL)
  {
	return;
  }
  if (head->next == NULL && pos == 1)
  {
	delete(head);
	head = NULL; //TO avoid Dangliing Pointer
  }
  Node* t = head, *p=NULL;
  int cnt = 0;
  while (t->next != NULL)
  {
	p = t;
	cnt++;
	t = t->next;
	if (cnt == (pos - 1))
	{
	  break;
	}
  }
  if (p != NULL)
  {
	Node* del = NULL;
	p->next = t->next;
	del = t;
	delete(del);
	t = NULL;
  }
 
}

void insertNode(int data, int pos)
{
  Node* nw = new Node(data);
  Node* t = head, * p = NULL;
  int cnt = 0;
  if (head == NULL && pos == 1)
  {
	head = nw;
  }
  else {
	while (t != NULL)
	{
	  cnt++;
	  p = t;
	  t = t->next;
	  if (cnt == pos-1)
	  {
		break;
	  }
	}
	if (cnt <= pos)
	{
	  p->next = nw;
	  nw->next = t;
	}
  }
  return;
}

void print_ll() {
  // Output each element followed by a space
  Node* t = head;
  while (t != NULL)
  {
	cout << t->val << " ";
	t = t->next;
  }
}

int main()
{
  Node* t = head;
  insertNode(240, 1);
  insertNode(241, 2);
  insertNode(242, 3);
  insertNode(243, 4);
  insertNode(244, 5);
  insertNode(245, 6);
  insertNode(246, 7);
  insertNode(247, 8);
  insertNode(248, 4);
  print_ll();
  cout << endl;
  print_ll();
  cout << endl;
  deleteNode(6);
  print_ll();
  cout << endl;
  cout << "printing form main" << endl;
  t = head;
  while (t)
  {
	cout << t->val << " ";
	t = t->next;
  }
  cout << endl;
  return 0;
}