#include<iostream>
#include<string.h>

using namespace std;

string addBinary(string A, string B) {
  int aLen = A.length();
  int bLen = B.length();
  unsigned long long AA = 0, BB = 0;
  unsigned int bp = 0;
  string ans;
  unsigned long long = aLen-1;
  for (int s=0;s<aLen;s++)
  {
	if (A[s] - 48)
	{
	  AA |= (1 << bp);
	}
	bp -= 1;
  }
  bp = bLen - 1;
  for (int s = 0; s < bLen; s++)
  {
	if (B[s] - 48)
	{
	  BB |= (1 << bp);
	}
	bp -= 1;
  }
  bp = AA + BB;
  int start = 0;
  for (int i = 31; i >= 0; i--)
  {
	if ((bp & (1 << i)))
	{
	  start = i;
	  break;
	}
  }
  for (int i = start; i >= 0; i--)
  {
	if ((bp & (1 << i)))
	  ans.append("1");
	else
	  ans.append("0");
  }
  return ans;
}

int main()
{
  cout << "Hello adding binaryh strings\n";

  cout << "Binary String : "<< addBinary("10001100010111000101100010100110001001101010000010011010",
	"101111000100100100111110010010101110101001100100101001111010011000000110") <<endl;

  return 0;
}
