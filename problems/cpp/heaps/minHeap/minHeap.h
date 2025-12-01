#ifndef _DSA_MINHEAP_H_
#define _DSA_MINHEAP_H_

#include<iostream>
#include<vector>

using namespace std;

class minHeap {
  vector<int> mH;
public:
  void insert(int val);
  int getMin();
  int pop();
  int getSize();
};

#endif // !_DSA_MINHEAP_H_
