#include<iostream>

using namespace std;

struct ListNode {
  int tmp;
  int val;
  ListNode* next;
  ListNode(int v) :val(v), next(NULL) {}
};

class Solution
{
  ListNode* head;
  ListNode* topNode;
  ListNode* tailNode;
  int size;
public:
  Solution():head(NULL), topNode(NULL), tailNode(NULL), size(0){
  }
  void push(int value){
	ListNode* nw = new ListNode(value);
	if (head == NULL)
	{
	  head = nw;
	}
	else {
	  ListNode* t = head;
	  nw->next = t;
	  head = nw;
	  topNode = head;
	  tailNode = t;
	  size += 1;
	}
  }
  int top() {
	if (size == 0)return 0;
	else return topNode->val;
  }
  void pop(){
	if (size > 0)
	{
	  ListNode* t = head;
	  head = head->next;
	  topNode = head;
	  delete t;
	  t = NULL;
	  size -= 1;
	}
  }
  void begin(){}
  bool rollback(){}
  bool commit(){}
};

int main()
{
  cout << "MyStack\n";
  Solution sol;
  sol.push(2);
  sol.push(5);
  cout << sol.top() << endl;;
  sol.pop();
  cout << sol.top() << endl;
  return 0;
}