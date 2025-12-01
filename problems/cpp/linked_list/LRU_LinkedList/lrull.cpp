#include<iostream>

using namespace std;

struct Node {
  int data;
  int key;
  Node* next;
  Node(int key, int val) : key(key), data(val) { next = NULL; };
};

int c;
int cntr;
Node* head;

struct LRUCache {
  LRUCache(int capacity);
  int get(int key);
  void set(int key, int value);
};

LRUCache::LRUCache(int capacity) {
  c = capacity;
  cntr = 0;
  head = NULL;
}

int LRUCache::get(int key) {
  Node* t = head;
  while (t != NULL)
  {
	if (t->key == key)
	  return t->data;
	t = t->next;
  }
  return -1;
}

void LRUCache::set(int key, int value) {
  Node* node = new Node(key, value);
  Node* h = head;
  Node* t = head;
  if (c < 2)
  {
	head = node;
  }
  else if (cntr < c)
  {
	if (h == NULL)
	{
	  head = node;
	  cntr++;
	}
	else {
	  node->next = head;
	  head = node;
	  cntr++;
	}
  }
  else {
	int flag = 0;
	t = head;
	Node* p = NULL;
	Node* r = NULL;
	while (t != NULL) {
	  if (t->key == key)
	  {
		t->data = value;
		flag = 1;
		r = t;
	  }
	  if (t->next != NULL)
		p = t;
	  t = t->next;
	}
	if (flag==0) {
	  p->next = NULL;
	  node->next = head;
	  head = node;
	}
	else {
	  r->next = head;
	  head = r;
	  p->next = NULL;
	}
  }
}


int main()
{
  //7 2 - G 2 -S 2 6 -G 1 -S 1 5 -S 1 2 -G 1 -G 2
  //6 1 - S 2 1 - S 2 2 - G 2 -S 1 1 -S 4 1 -G 2
  //6 2 
   //S 2 1 
   //S 1 1 
   //S 2 3 
   //S 4 1 
   //G 1 
   //G 2
  //Ans shuld be -1 3
  //6 2 -S 2 1- S 1 1 -S 2 3 -S 4 1 G 1 G 2
  LRUCache* cache = new LRUCache(1);
  //cache->set(2, 1);
  //cache->set(1, 1);
  //cache->set(2, 3);
  //cache->set(4, 1);
  //cout << "get: " << cache->get(1) << endl;
  cout << "get: " << cache->get(5) << endl;
  //cout << "get: " << cache->get(2) << endl;
  //cout << "get: " << cache->get(1) << endl;
  //cache->set(1, 1);
  //cache->set(4, 1);
  //cout << "get: " << cache->get(2) << endl;


  return 0;
}