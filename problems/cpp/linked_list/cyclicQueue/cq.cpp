#include<iostream>
#include<vector>

using namespace std;

class quu {
private:
  int s;
  int f, r;
  int arr[5];
  const int N;
public:
  quu() :s(0), f(-1), r(-1), N(5) {
  }
  int enquu(int val);
  int dquu();
  bool empty();
  int front();
  int size();

};
int main()
{
  quu myq;
  myq.enquu(1);
  myq.enquu(2);
  myq.enquu(3);
  myq.enquu(4);
  myq.enquu(5);
  //myq.enquu(6);
  cout << myq.front() << endl;
  myq.dquu();
  cout << myq.front() << endl;

  while (!myq.empty())
  {
	cout << myq.front() << " ";
	myq.dquu();
  }
  cout << endl;

  return 0;
}

int quu::enquu(int val)
{
  if (s < N)
  {
	int ind = 0;
	r++;
	ind = r % N;
	arr[ind] = val;
	s++;
  }
  else {
	cout << "Queue full\n";
  }
  return r % N;
}

int quu::dquu()
{
  if (s > 0)
  {
	int ind = 0;
	f++;
	ind = f % N;
	s--;
	return arr[ind];
  }
  else {
	cout << "Queu is empty!\n";
  }
  return -1;
}

bool quu::empty()
{
  return (s>0) ? false : true;
}

int quu::front()
{
  if (s > 0)
	return arr[f+1];
  else
	return -1;
}

int quu::size()
{
  return s;
}
