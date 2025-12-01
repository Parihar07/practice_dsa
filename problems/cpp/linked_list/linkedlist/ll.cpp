#include<iostream>

using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int val) :val(val), next(NULL) {};
  Node() {};
};

class LinkedList {
private:
  Node node;
public:
  LinkedList() {};

};
int main()
{
  Node* head = NULL;

  for (int i = 1; i < 12; i++)
  {
	Node* newNode = new Node(i);

	if (head == NULL)
	{
	  head = newNode;
	}
	else {
	  Node* tmp = head;
	  while (tmp->next != NULL)
	  {
		tmp = tmp->next;
	  }
	  tmp->next = newNode;
	}
  }
  Node* tmp = head;
  cout << "Temp isis data : " << tmp->val << endl;
  while (tmp)
  {
	cout << tmp->val << " ";
	tmp = tmp->next;
  }
  cout << endl;

  Node* p = NULL, * q = NULL, * r = NULL;
  p = q = head;
  q = q->next;
  while (q != NULL)
  {
	r = q->next;
	q->next = p;
	p = q;
	q = r;
  }
  head->next = NULL;
  head = p;

  tmp = head;
  while (tmp)
  {
	cout << tmp->val << " ";
	tmp = tmp->next;
  }

  cout << endl;
  return 0;
}