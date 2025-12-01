#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
  unordered_map<char, int> umap;
  cout << "Unordered Maps\n";
  
  umap['b'] = 201;
  umap['d'] = 202;
  umap['a'] = 203;
  umap['e'] = 205;
  umap['f'] = 206;
  umap['h'] = 208;
  for (auto i = umap.begin(); i != umap.end(); i++)
  {
	cout << i->first << " " << i->second << endl;
  }

  cout << "get g"<< umap['g'] << endl;
  if (umap.find(203) != umap.end())
  {
	cout << "found" << endl;
  }
  else {
	cout << "Not found" << endl;
  }


  if (umap.find(210) != umap.end())
  {
	cout << "found" << endl;
  }
  else {
	cout << "Not found" << endl;
  }
  return 0;
}