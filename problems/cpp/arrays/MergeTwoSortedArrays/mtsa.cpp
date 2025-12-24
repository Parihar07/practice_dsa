#include <iostream>
#include <vector>

using namespace std;

/*
Problem Statement: Merge Two Sorted Arrays
==========================================
Given two sorted arrays A and B of size M and N respectively,
merge them into a single sorted array.

Input:
- A: sorted array of size M
- B: sorted array of size N

Output:
- Return a sorted array containing all elements from A and B

Example:
A = [4, 7, 9]
B = [2, 11, 19]
Output = [2, 4, 7, 9, 11, 19]

Time Complexity: O(M + N)
- We traverse both arrays exactly once

Space Complexity: O(M + N)
- We create a new array of size M + N to store the result
*/

vector<int> solve(const vector<int> &A, const vector<int> &B)
{
  int M = A.size();
  int N = B.size();
  int i = 0, j = 0, k = 0;
  vector<int> sa((M + N), 0);
  while (i < M && j < N)
  {
    if (A[i] < B[j])
    {
      sa[k] = A[i];
      i++;
      k++;
    }
    else
    {
      sa[k] = B[j];
      j++;
      k++;
    }
  }

  while (i < M)
  {
    sa[k] = A[i];
    i++;
    k++;
  }
  while (j < N)
  {
    sa[k] = B[j];
    j++;
    k++;
  }

  return sa;
}

void printArray(const vector<int> &arr)
{
  for (size_t i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  cout << "=== Merge Two Sorted Arrays Test Cases ===\n\n";

  // Test Case 1: Basic merge
  cout << "Test Case 1: Basic merge\n";
  vector<int> A1 = {4, 7, 9};
  vector<int> B1 = {2, 11, 19};
  cout << "A: ";
  printArray(A1);
  cout << "B: ";
  printArray(B1);
  cout << "Result: ";
  printArray(solve(A1, B1));
  cout << "Expected: 2 4 7 9 11 19\n\n";

  // Test Case 2: Empty array B
  cout << "Test Case 2: Empty array B\n";
  vector<int> A2 = {1, 3, 5};
  vector<int> B2 = {};
  cout << "A: ";
  printArray(A2);
  cout << "B: [empty]\n";
  cout << "Result: ";
  printArray(solve(A2, B2));
  cout << "Expected: 1 3 5\n\n";

  // Test Case 3: Empty array A
  cout << "Test Case 3: Empty array A\n";
  vector<int> A3 = {};
  vector<int> B3 = {2, 4, 6};
  cout << "A: [empty]\n";
  cout << "B: ";
  printArray(B3);
  cout << "Result: ";
  printArray(solve(A3, B3));
  cout << "Expected: 2 4 6\n\n";

  // Test Case 4: Both arrays empty
  cout << "Test Case 4: Both arrays empty\n";
  vector<int> A4 = {};
  vector<int> B4 = {};
  cout << "A: [empty]\n";
  cout << "B: [empty]\n";
  cout << "Result: ";
  printArray(solve(A4, B4));
  cout << "Expected: [empty]\n\n";

  // Test Case 5: Single element in each
  cout << "Test Case 5: Single element in each\n";
  vector<int> A5 = {5};
  vector<int> B5 = {3};
  cout << "A: ";
  printArray(A5);
  cout << "B: ";
  printArray(B5);
  cout << "Result: ";
  printArray(solve(A5, B5));
  cout << "Expected: 3 5\n\n";

  // Test Case 6: Negative numbers
  cout << "Test Case 6: Negative numbers\n";
  vector<int> A6 = {-5, -2, 1};
  vector<int> B6 = {-3, 0, 4};
  cout << "A: ";
  printArray(A6);
  cout << "B: ";
  printArray(B6);
  cout << "Result: ";
  printArray(solve(A6, B6));
  cout << "Expected: -5 -3 -2 0 1 4\n\n";

  // Test Case 7: Duplicates
  cout << "Test Case 7: Duplicates\n";
  vector<int> A7 = {1, 3, 5, 5, 7};
  vector<int> B7 = {2, 3, 5, 8};
  cout << "A: ";
  printArray(A7);
  cout << "B: ";
  printArray(B7);
  cout << "Result: ";
  printArray(solve(A7, B7));
  cout << "Expected: 1 2 3 3 5 5 5 7 8\n\n";

  // Test Case 8: All elements in A smaller than B
  cout << "Test Case 8: All elements in A smaller than B\n";
  vector<int> A8 = {1, 2, 3};
  vector<int> B8 = {10, 20, 30};
  cout << "A: ";
  printArray(A8);
  cout << "B: ";
  printArray(B8);
  cout << "Result: ";
  printArray(solve(A8, B8));
  cout << "Expected: 1 2 3 10 20 30\n\n";

  return 0;
}