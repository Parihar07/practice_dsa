#include "minHeap.h"

void minHeap::insert(int val)
{
  mH.push_back(val);
  int i = (int)mH.size() - 1;
  while (i > 0)
  {
	int p = (i - 1) / 2;
	if (mH[i] < mH[p])
	{
	  int t = mH[i];
	  mH[i] = mH[p];
	  mH[p] = t;
	}
	i = p;
  }
}

int minHeap::getMin()
{
  return ((mH.size()) > 0) ? mH[0] : -1;
}

int minHeap::pop()
{
  if ((mH.size()) > 0)
  {
	swap(mH[0], mH[mH.size() - 1]);
	mH.pop_back();

	int s = 0;
	int L = (2 * s) + 1;
	int R = (2 * s) + 2;
	while (1)
	{
	  int largest = s;

	  if (L<mH.size() && mH[L] < mH[largest])
	  {
		largest = L;
	  }
	  if (R<mH.size() && mH[R] < mH[largest]) {
		largest = R;
	  }
	  
	  if (largest != s)
		swap(mH[s], mH[largest]);
	  else
		break;

	  s = largest;
	  L = (2 * s) + 1;
	  R = (2 * s) + 2;
	}
  }
  return mH.size();
}

int minHeap::getSize()
{
  return (int)mH.size();
}
