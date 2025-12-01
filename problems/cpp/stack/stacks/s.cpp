#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>;
using namespace std;

int main()
{
  stack<int> stk;
  cout << "Hello stack stuff\n";

  vector<int> v;

  v.push_back(10);
  v.push_back(11);
  v.push_back(12);


  uint32_t val = 0x12345678;

  printf("%08x\n", val);


  return 0;
}