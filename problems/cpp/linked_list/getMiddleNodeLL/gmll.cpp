#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

int solve(ListNode* A) {
  ListNode* s = A, * f = A;
  while (f != NULL && f->next != NULL)
  {
	s = s->next;
	f = f->next->next;
  }
  return s->val;
}

int main()
{
  return 0;
}