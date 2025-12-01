#include<iostream>
#include<vector>

using namespace std;

int getPivot(const vector<int>& A);
int search(const vector<int>& A, int B);


int getPivot(const vector<int>& A)
{
  int p = -1;
  int s = 1, e = A.size() - 1, mid = -1;
  while (s <= e)
  {
	mid = (s + e) / 2;
	if (A[mid] > A[0])
	{
	  s = mid + 1;
	}
	else {
	  p = mid;
	  e = mid - 1;
	}
	
  }
  cout << "Pivot : " << p ;
  return p;
}

int search(const vector<int>& A, int B) {
  int ind = -1;
  int p = getPivot(A);
  if (p < 0) {
	p = A.size() - 1;
  }
  int s = 0, e = 0, mid = 0;

  if (B >= A[0]) {
	//first part of aray
	s = 0; e = p-1; mid = -1;
	while (s <= e)
	{
	  mid = (s + e) / 2;
	  if (A[mid] == B)
	  {
		ind = mid;
	  }

	  if (A[mid] > B)
	  {
		e = mid - 1;
	  }
	  else {
		s = mid + 1;
	  }
	}
  }
  else {
	//second part of array
	s = p; e = A.size()-1; mid = -1;
	while (s <= e)
	{
	  mid = (s + e) / 2;
	  if (A[mid] == B)
	  {
		ind = mid;
	  }

	  if (A[mid] > B)
	  {
		e = mid - 1;
	  }
	  else {
		s = mid + 1;
	  }
	}
  }

  return ind;
}

int main()
{
  vector<int> A = { 4, 5, 6, 7, 0, 1, 2, 3 };
  vector<int> B = { 9, 10, 3, 5, 6, 8 };
  vector<int> C = { 1, 7, 67, 133, 178 };
  vector<int> D = { 192, 194, 197, 198, 199, 200, 201, 203, 204,
	2, 3, 4, 7, 9, 10, 11, 14, 15, 16, 17, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
	33, 34, 35, 36, 39, 40, 42, 43, 46, 47, 50, 51, 52, 53, 55, 57, 59, 60, 64, 66, 68, 70, 71,
	72, 75, 76, 78, 85, 86, 87, 91, 92, 94, 95, 96, 99, 102, 105, 106, 107, 109, 111, 113, 114, 115,
	119, 120, 121, 123, 125, 129, 130, 131, 133, 134, 137, 138, 139, 140, 141, 142, 143, 145, 146, 149,
	151, 152, 156, 160, 161, 165, 167, 168, 170, 171, 176, 177, 178, 179, 180, 181, 182, 185, 186, 190 };
  vector<int> E = { 5, 1, 3 };
  vector<int> F = { 194, 195, 196, 197, 198, 199, 201, 203, 204, 
	1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 
	31, 32, 33, 34, 35, 36, 37, 39, 40, 42, 43, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 
	60, 61, 63, 65, 66, 68, 69, 70, 71, 73, 74, 76, 77, 79, 80, 81, 82, 83, 84, 86, 87, 88, 89, 91, 92, 
	93, 94, 95, 97, 98, 99, 101, 103, 104, 105, 106, 107, 108, 109, 110, 113, 114, 115, 117, 118, 120, 
	121, 122, 123, 124, 127, 128, 130, 131, 133, 134, 135, 136, 137, 139, 140, 141, 142, 143, 144, 146,
	147, 148, 149, 150, 151, 152, 153, 154, 155, 158, 159, 160, 161, 162, 163, 164, 166, 167, 169, 170, 
	171, 172, 174, 175, 177, 178, 179, 181, 182, 184, 185, 187, 189, 190, 192, 193 };
  //cout << "pivot : " << getPivot(A) << endl;
  //cout << "pivot : " << getPivot(B) << endl;
  cout << " Ans A: " << search(A, 4) << endl;
  cout << " Ans B: " << search(B, 5) << endl;
  cout << " Ans B: " << search(B, 7) << endl;
  cout << " Ans C: " << search(C, 1) << endl;
  cout << " Ans D: " << search(D, 70) << endl;
  cout << " Ans F: " << search(F,1) << endl;
  cout << " Ans E: " << search(E, 5) << endl;
  return 0;
} 