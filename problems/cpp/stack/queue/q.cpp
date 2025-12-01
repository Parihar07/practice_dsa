#include<iostream>
#include<queue>

using namespace std;

int main()
{
  queue<int> mq;
  mq.push(2);
  mq.push(3);
  mq.push(4);
  mq.push(5);
  mq.push(6);

  cout << "Front : " << mq.front() << endl;
  mq.pop();
  cout << "Front : " << mq.front() << endl;
  mq.pop();
  cout << "Front : " << mq.front() << endl;

  while (!mq.empty())
  {
	cout << mq.front() << " ";
	mq.pop();
  }
  return 0;
}