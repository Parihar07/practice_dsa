#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class heap {
  int maxi;
  int mini;
  vector<int> HL;
public:
  heap() :maxi(0), mini(0) {};
  int getMax();
  int getMin();
  void insertVal(int val);
  void popMax();
  void popMin();
};

int nchocBF(int A, vector<int>& B) {

  long ans = 0;
  int mod = 1000000007;
  for (int i = 0; i < A; i++)
  {
	sort(B.begin(), B.end());
	ans += B[B.size() - 1];
	B[B.size() - 1] /= 2;
  }
  return ans % mod;
}

int nchoc(int A, vector<int>& B) {

  long ans = 0;
  int mod = 1000000007;
  heap H;
  for (auto a : B) H.insertVal(a);
  for (int i = 0; i < A; i++)
  {
	int t = H.getMax();
	ans += t;
	H.popMax();
	H.insertVal(t / 2);
  }
  return ans % mod;
}
int heap::getMax()
{
  return HL[0];
}
int heap::getMin()
{
  return HL[mini];
}
void heap::insertVal(int val)
{
  HL.push_back(val);
  maxi = (int)HL.size() - 1;
  int i = maxi;
  int p = (i - 1) / 2;
  while (i>0 && HL[i] > HL[p])
  {
	swap(HL[i], HL[p]);
	i = p;
	p = (i - 1) / 2;
  }
}
void heap::popMax()
{
  if (HL.size() > 0)
  {
	int i = 0;
	swap(HL[0], HL[HL.size() - 1]);
	int largest_val = i;
	HL.pop_back(); //Poping last elemetnt form HL vector
	if(HL.size()>0)
	{
	  while(1)
	  {
		int L = (2 * i) + 1;
		int R = (2 * i) + 2;

		if (L < HL.size() && HL[L] > HL[largest_val])
		  largest_val = L;
		if (R < HL.size() && HL[R] > HL[largest_val])
		  largest_val = R;

		if (largest_val != i)
		{
		  swap(HL[i], HL[largest_val]);
		  i = largest_val;
		}
		else {
		  break;
		}
	  }

	  /*while (L <= (HL.size() - 1) && HL[i] < HL[L])
	  {
		swap(HL[i], HL[L]);
		i = L;
		L = (2 * i) + 1;
	  }
	  i = 0;
	  while (R <= (HL.size() - 1) && HL[i] < HL[R])
	  {
		swap(HL[i], HL[R]);
		i = R;
		R = (2 * i) + 2;
	  }*/


	}
  }
}
void heap::popMin()
{
}

int main()
{
  vector<int> A = { 78,46,53,43,79,46,79,80,65,81,39,84,63,24,54,42,99,15,86,45,51,47,94,35,15,30,23 };
  cout << "Choco Kid Ate : "<<nchoc(45,A)<<endl;
  return 0;
}
