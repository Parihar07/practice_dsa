#include<iostream>
#include<vector>
using namespace std;

class maxHeap {
  vector<int> maxH;
public:
  int getMax();
  void insert(int v);
  int pop();
  int getSize();
};
int main()
{
  maxHeap maxheap;
  vector<int> A = {23, 4, 3, 2, 5, 7, 9, 76, 34, 23};

  for (int i = 0; i < A.size(); i++)
	maxheap.insert(A[i]);

  while (maxheap.getSize())
  {
	cout << maxheap.pop() << " ";
	//bmaxheap.pop();
  }
  cout << endl;
  return 0;
}

int maxHeap::getMax()
{
  return (maxH.size() > 0) ? maxH[0] : -1;
}

void maxHeap::insert(int v)
{
  maxH.push_back(v);
  if (maxH.size() > 1)
  {
	int e = (int)maxH.size() - 1;
	while (e > 0)
	{
	  int p = (e - 1) / 2;
	  if (maxH[e] > maxH[p])
	  {
		swap(maxH[e], maxH[p]);
		e = p;
	  }
	  else {
		break;
	  }
	}
  }
}

int maxHeap::pop()
{
  int t = -1;
  if (maxH.size() > 0)
  {
	swap(maxH[0], maxH[maxH.size() - 1]);
	t = maxH[maxH.size() - 1];
	maxH.pop_back();

	int s = 0, L = (2 * s) + 1, R = (2 * s) + 2;

	while (1)
	{
	  int largest = s;
	  if (L < maxH.size() && maxH[largest] < maxH[L]) largest = L;
	  if (R < maxH.size() && maxH[largest] < maxH[R]) largest = R;

	  if (largest != s) swap(maxH[largest], maxH[s]);
	  else break;

	  s = largest;
	  L = 2 * s + 1; R = 2 * s + 2;
	}
  }
  return t;
}

int maxHeap::getSize()
{
  return (int)maxH.size();
}
