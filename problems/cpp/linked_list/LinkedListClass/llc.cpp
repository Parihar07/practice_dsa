#include<iostream>
#include<vector>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

class CLinkedList
{
  Node* head;
public:
  CLinkedList(vector<int>& A) { head = createLinkedList(A); };
  CLinkedList() { head = NULL; }
  void InsertItem(int a)
  {}
  void Display();
  CLinkedList(CLinkedList& other) {
  }
  Node* createLinkedList(vector<int> A);
};
void CLinkedList::Display()
{
  Node* t = head;
  while (t != NULL)
  {
	cout << t->data << " ";
	t = t->next;
  }
}

Node* CLinkedList::createLinkedList(vector<int> A)
{
  Node* t = NULL;
  Node* h = NULL;
  for (int i = 0; i < A.size(); i++)
  {
	Node* nw = new Node();
	nw->data = A[i];
	nw->next = NULL;

	if (t == NULL)
	{
	  t = nw;
	  h = t;
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

int main()
{
  vector<int> A = { 1,2,3,4,5,6,7,8,9 };
  CLinkedList linkedlis(;

  cout << "hello Linked\n";
  return 0;
}