#include<iostream>
#include<stack>
#include<vector>
#include"../common/common.h"

using namespace std;
int largestRectangleArea(vector<int>& A);
vector<int> createNSL(vector<int> A);
vector<int> createNSR(vector<int> A);

vector<int> createNSR(vector<int> A)
{
  vector<int> nsr(A.size(), -1);
  stack<int> stk;
  for (int i = (A.size() - 1); i >= 0; i--)
  {
	while (!stk.empty())
	{
	  if (A[stk.top()] < A[i])
	  {
		nsr[i] = stk.top();
		stk.push(i);
		break;
	  }
	  stk.pop();
	}
	if (stk.empty())
	{
	  stk.push(i);
	}
  }
  return nsr;
}

vector<int> createNSL(vector<int> A) 
{
  vector<int> nsl(A.size(),-1);
  stack<int> stk;
  for (int i = 0; i < A.size(); i++)
  {
	while (!stk.empty())
	{
	  if (A[stk.top()] < A[i])
	  {
		nsl[i] = stk.top();
		stk.push(i);
		break;
	  }
	  stk.pop();
	}
	if (stk.empty())
	{
	  stk.push(i);
	}
  }
  return nsl;
}
int largestRectangleArea(vector<int>& A) {
  int area = 0;
  int ans = 0;
  if (A.size() == 1)
	return A[0];
  vector<int> nsr = createNSR(A);  
  cout << "nsr:";
  for (auto a = nsr.begin(); a != nsr.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  cout << "nsl:";

  vector<int> nsl = createNSL(A);
  for (auto a = nsl.begin(); a != nsl.end(); a++)
  {
	cout << *a << " ";
  }
  cout << endl;
  int rightInd = 0, leftInd = 0;
  int length = 0, breadth = 0;
  for (int i = 0; i < A.size(); i++)
  {
	length = A[i];
	if (nsl[i] == -1 && nsr[i] == -1)
	{
	  breadth = A.size();
	}
	else if (nsl[i] == -1)
	{
	  leftInd = -1;
	  rightInd = nsr[i];
	  breadth = rightInd - leftInd - 1;
	}
	else if (nsr[i] == -1)
	{
	  leftInd = i - nsl[i];
	  rightInd = A.size() - i;
	  breadth = rightInd + leftInd - 1;
	}
	else {
	  leftInd = nsl[i];
	  rightInd = nsr[i];
	  breadth = rightInd - leftInd - 1;
	}
	area = length * breadth;
	ans = _max(area, ans);
  }
  return ans;
}
int main()
{
  vector<int> A = { 6,2,5,4,5,1,6 };
  cout << "Largest Area : " << largestRectangleArea(A) << endl;

}