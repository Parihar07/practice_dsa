#include<iostream>

using namespace std;
/*
char retRepeatedChar(char a[], int sze)
{
 int s[26] = {0};
 int t =0;
 for(int i=0;i<sze;i++)
 {
  if(a[i] >=65 || a[i]<= 91)
   t = A[i]-65;
  else
   t = a[i]-97;

  if(s[t] == 1)
    return a[i];
  s[t]++;
 }
 return -1;
}
*/

int retRepeatedChar(const char a[], int sze)
{
  int A[26] = { 0 };
  int t = 0;
  for (int i = 0; i < sze; i++)
  {
    if (a[i] >= 'A' && a[i] <= 'Z')
      t = a[i] - 'A';
    else
    {
      t = a[i] - 32;
      t = t - 'A';
    }

    if (A[t] == 1)
      return i;

    A[t]++;
  }
  return -1;
}

int main()
{
  const char* str = "hello";
  
  cout << retRepeatedChar(str, 6);

  return 0;
}