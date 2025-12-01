#include<iostream>
using namespace std;

int solve(int A) {
  if (A == 1) return 1;
  if (!(A % 2)) return 2;
  else return 3;
}


int main()
{
  cout << "Hello coloring world\n";

  cout << "Colors required : " << solve(2) << endl;
  cout << "Colors required : " << solve(3) << endl;
  cout << "Colors required : " << solve(4) << endl;
  cout << "Colors required : " << solve(5) << endl;
  cout << "Colors required : " << solve(7) << endl;
  return 0;
}