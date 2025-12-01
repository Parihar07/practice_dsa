#include<iostream>

using namespace std;

int nearestSquareNum(int A)
{
  int i = 0;
  if (A == 0) return 0;
  for (i = 1; i*i <= A; i++);
  return i * i == A ? i : i - 1;
}

int main()
{
  cout << "Hello nearest square\n";

  cout << "Nearest Square: " << nearestSquareNum(25) << endl;
  cout << "Nearest Square: " << nearestSquareNum(23) << endl;
  cout << "Nearest Square: "<<nearestSquareNum(99) << endl;
  return 0;
}