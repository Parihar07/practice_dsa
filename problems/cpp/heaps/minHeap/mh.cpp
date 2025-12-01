#include"minHeap.h"

int main()
{
  cout << "Minimum Heap\n";
  minHeap mheap;

  mheap.insert(20);
  mheap.insert(21);
  mheap.insert(2);
  mheap.insert(230);
  mheap.insert(10);
  //mheap.insert(220);
  //mheap.insert(211);
  //mheap.insert(-2);
  //mheap.insert(2340);
  //mheap.insert(0);

  cout << "GetSize: " << mheap.getSize()<<endl;

  while (mheap.getSize())
  {
	cout << mheap.getMin() << " ";
	mheap.pop();
  }

  cout << endl;
  
  return 0;
}