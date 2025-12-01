#include<iostream>
#include<vector>

using namespace std;
/*
Write a function that takes an integer and returns the number of 
1 bits present in its binary representation.
*/
int numSetBits(int A) {
  int setBits = 0;
  for (int b = 31; b >= 0; b--)
  {
	if (A & (1 << b))
	  setBits += 1;
  }
  return setBits;
}

int main()
{
  cout << "hello set bits\n";
  cout << "Count set bits : " << numSetBits(11) << endl;
  cout << "Count set bits : " << numSetBits(17) << endl;
  cout << "Count set bits : " << numSetBits(8) << endl;
  cout << "Count set bits : " << numSetBits(111) << endl;
  return 0;
}