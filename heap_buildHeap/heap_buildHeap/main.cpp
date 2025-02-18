//
//  main.cpp
//  heap_buildHeap
//
//  Created by CodeBreaker on 16/02/25.
//

#include <iostream>
#include "heap.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Building min Heap!\n";
    
    vector<int> A= {5,13,-2,11,27,31,0,19};
    auto mh = MinHeap();
    mh.heapifiy(A);
    
    auto ans = mh.getList();
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
