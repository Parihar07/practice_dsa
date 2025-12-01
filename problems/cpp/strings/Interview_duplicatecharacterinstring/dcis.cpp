#include<iostream>
#include<string>
#include<unordered_set>
/*
Write a function in C++ to check duplicate letters. It must accept a string, i.e., a sentence.
The function should return True if the sentence has any word with duplicate letters,
else return False.
*/
using namespace std;

// Time complexity  O(MXN)
bool duplicateLetterString(string str)
{
  int i = 0;
  int p = 0;
  while (str[i] != '\0')  // N time
  {
	if (str[i] == ' ') {
	  unordered_set<int> us;
	  int t = i;
	  while (t > p) // M time for each word
	  {
		if (us.find(str[t]) != us.end())
		{
		  return true;
		}
		us.insert(str[t]);
		t--;
	  }
	  p = i;
	}
	i++;
  }
  return false;
}

int main()
{
  cout << "hello dup string\n";
  string s = "Encora is a wo company to work with";
  cout << "Duplicate : " << duplicateLetterString(s) << endl;
  return 0;
}