#include<iostream>
using namespace std;

int uniqueCnt(const char ar[], int sz);
int UniqCntOpt(const char ar[], int sz);

int UniqCntOpt(const char ar[], int sz)
{
  int freqTable[27] = { 0 };
  int ans = 0;
  for (int i = 0; i < 27; i++)
  {
	int ch = ar[i];
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
	  if ( ch >= 'a' && ch <= 'z')
	  {
		ch = ch - 32;
		freqTable[ch - 65] += 1;
	  }
	  else
		freqTable[ch - 65] += 1;
	}
  }

  for (int i = 0; i < 27; i++)
  {
	if (freqTable[i] == 1)
	{
	  ans += 1;
	}
  }
  return ans;
}

int uniqueCnt(const char ar[], int sz)
{
  int a = 0, ans = 0, flag = 0;
  for (int i = 0; i < sz; i++)
  {
	flag = 0;
	for (int j = i+1; j < sz; j++)
	{
	  if (ar[i] == ar[j])
	  {
		flag = 0;
		break;
	  }
	  else
		flag = 1;
	}
	if (flag)
	  ans += 1;
  }
  return ans;
}

int main()
{
  const char* str = "aaddffaaooppffw";

  cout << "UniqueCount-" << uniqueCnt(str, 17)<<endl;
  cout << "UniqueCount Optimal-" << UniqCntOpt(str, 17);

  return 0;
}