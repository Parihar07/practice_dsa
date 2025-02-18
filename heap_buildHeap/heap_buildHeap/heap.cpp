//
//  heap.cpp
//  heap_heapQuery
//
//  Created by CodeBreaker on 16/02/25.
//

#include "heap.h"

void MinHeap::insert(int val)
{
    list.push_back(val);
    auto c=list.size()-1;
    while(c!=0)
    {
        auto p = (c-1)/2;
        if(list[p]>list[c])
        {
            int t = list[p];
            list[p]=list[c];
            list[c]=t;
            c=p;
        } else {
            break;
        }
    }
}

vector<int> MinHeap::getList()
{
    return list;
}


int MinHeap::pop()
{
    if(list.size()==0) return -1;
    int rt = list[0];
    list[0] = list[list.size()-1];
    list.pop_back();
    int p = 0;
    while(((2*p)+1)<list.size()){ // atleset one child for the parent
        int lc = (2*p)+1, rc = (2*p)+2;
        int mi = lc;
        if(rc<list.size() && list[mi]>list[rc]) mi=rc; // if right child is availble then compare
        if(list[p]>list[mi])
        {
            swap(list[p],list[mi]);
            p=mi;
        } else {
            break;
        }
    }
    return rt;
}

void MinHeap::heapifiy(const vector<int> &v)
{
    list = v;
    auto N = list.size();
    for(auto c = N-1;c>=0;c--)
    {
        auto p=c;
        while((2*p+1)<N){
            auto lc = 2*p+1, rc = 2*p+2, mi = lc; //left child rc, right child rc, minimum index mi
            if(rc<N && list[mi]>list[rc]) mi = rc;
            if(list[mi]<list[p]){
                swap(list[mi],list[p]);
                p=mi;
            } else {
                break;
            }
        }
    }
}
