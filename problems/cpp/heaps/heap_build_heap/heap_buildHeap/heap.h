//
//  heap.h
//  heap_heapQuery
//
//  Created by CodeBreaker on 16/02/25.
//
#ifndef _H_HEAPQUERY_H_
#define _H_HEAPQUERY_H_

#include<vector>
using namespace std;

class MinHeap {
private:
    vector<int> list;
public:
    MinHeap()=default;
    void insert(int val);
    int pop();
    int size();
    vector<int> getList();
    void heapifiy(const vector<int> &v);
};


#endif //_H_HEAPQUERY_H_
