#include<iostream>
#include<unordered_map>
using namespace std;

struct LRUCache {
    LRUCache(int capacity);
    int get(int key);
    void set(int key, int value);
  };

//struct Node {
//  int data;
//  int key;
//  Node* next;
//  Node(int key, int val) : key(key), data(val) { next = NULL; };
//};
//
//int c;
//int cntr;
//Node* head;
//unordered_map<int, Node*> umap;
//
//struct LRUCache {
//  LRUCache(int capacity);
//  int get(int key);
//  void set(int key, int value);
//};
//
//LRUCache::LRUCache(int capacity) {
//  c = capacity;
//  cntr = 0;
//  head = NULL;
//}
//
//int LRUCache::get(int key) {
//  Node* t = head;
//  while (t != NULL)
//  {
//	if (t->key == key)
//	  return t->data;
//	t = t->next;
//  }
//  return -1;
//}
//
//void LRUCache::set(int key, int value) {
//  Node* node = new Node(key, value);
//  Node* h = head;
//  Node* t = head;
//
//  if (c < 2)
//  {
//	head = node;
//  }
//  else if (cntr < c)
//  {
//	if (h == NULL)
//	{
//	  head = node;
//	  umap[key] = head;
//	  cntr++;
//	}
//	else {
//	  if (umap.find(key) != umap.end())
//	  {
//		t = umap[key];
//		t->data = value;
//	  } else{
//		node->next = head;
//		head = node;
//		umap[key] = head;
//	  }
//	  cntr++;
//	}
//  }
//  else {
//	t = head;
//	Node* p = NULL;
//	Node* r = NULL;
//
//	while (t!=NULL) {
//	  if (t->next != NULL)
//		p = t;
//	  t = t->next;
//	}
//	if (umap.find(key) != umap.end())
//	{
//	  r = umap[key];
//	  r->data = value;
//	  if(r!=head){
//		r->next = head;
//		head = r;
//	  }
//	}
//	else {
//	  p->next = NULL;
//	  node->next = head;
//	  head = node;
//	  umap[key] = head;
//	}
//  }
//}

class Node {

public:

  int key;

  int val;

  Node* prev;

  Node* next;

  Node(int key, int val) {

	this->key = key;

	this->val = val;

	this->prev = NULL;

	this->next = NULL;

  }

};

Node* head;

Node* tail;

int N;

int MAX;

unordered_map<int, Node*> mMap;

void updateAccessList(Node* node) {

  if (node == head) {

	return;

  }

  if (node == tail) {

	tail = node->prev;

  }
  else {

	node->next->prev = node->prev;

  }


  node->prev->next = node->next;

  node->next = head;

  head->prev = node;

  head = node;

  node->prev = NULL;

}

LRUCache::LRUCache(int capacity) {

  head = NULL;

  tail = NULL;

  MAX = capacity;

  N = 0;

  mMap.clear();

}

int LRUCache::get(int key) {

  if (mMap.find(key) != mMap.end()) {

	Node* node = mMap[key];

	updateAccessList(node);

	return node->val;

  }

  return -1;

}

void LRUCache::set(int key, int value) {

  if (mMap.find(key) != mMap.end()) {

	Node* node = mMap[key];

	node->val = value;

	updateAccessList(node);

  }
  else {

	Node* node = new Node(key, value);

	mMap[key] = node;

	if (N == MAX) {

	  mMap.erase(tail->key);

	  if (tail == head) {

		tail = NULL;

		head = NULL;

	  }
	  else {

		tail = tail->prev;

		tail->next->prev = NULL;

		tail->next = NULL;

	  }

	}
	else if (N < MAX) {

	  N++;

	}

	if (head == NULL) {

	  head = node;

	  tail = node;

	}
	else {

	  node->next = head;

	  head->prev = node;

	  head = node;

	}

  }

}
int main()
{
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
  //7 2 - G 2 -S 2 6 -G 1 -S 1 5 -S 1 2 -G 1 -G 2
  LRUCache* cache = new LRUCache(2);
  cout << "get: " << cache->get(2) << endl;
  cache->set(2, 6);
  cout << "get: " << cache->get(1) << endl;
  cache->set(1, 5);
  cache->set(1, 2);
  cout << "get: " << cache->get(1) << endl;
  cout << "get: " << cache->get(2) << endl;
  //cache->set(1, 1);
  //cout << "get: " << cache->get(1) << endl;
  //cout << "get: " << cache->get(5) << endl;
  //cout << "get: " << cache->get(1) << endl;
  //cache->set(1, 1);
  /*cache->set(4, 1);
  cout << "get: " << cache->get(2) << endl;*/


  return 0;
}