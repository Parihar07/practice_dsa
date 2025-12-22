#include <iostream>
#include <vector>

using namespace std;

/*
PS: Kth Smallest Element
Given an array A of size N and an integer B (1 <= B <= N),
find the Bth smallest element in the array.

Example 1:
Input: A = [2, 1, 4, 3, 2], B = 3
Output: 2
Explanation: The 3rd smallest element is 2

Example 2:
Input: A = [1, 2], B = 2
Output: 2
*/

// Approach: Brute Force using Selection Sort
// TC: O(N * B) where N = array size, B = kth position
//     - Outer loop runs B times
//     - Inner loop scans remaining elements (N-i) times
// SC: O(N) for creating a copy of the array
int kthsmallest(const vector<int> &A, int B)
{
  // Edge case: invalid B
  if (B < 1 || B > A.size())
    return -1;

  vector<int> T = A; // Create a copy to avoid modifying original array

  // Selection Sort: Find the B smallest elements
  for (int i = 0; i < B; i++)
  {
    int minInd = i;
    int minVal = T[i]; 

    // Find the minimum element in remaining unsorted array
    for (int j = i + 1; j < T.size(); j++)
    {
      if (T[j] < minVal)
      {
        minVal = T[j];
        minInd = j;
      }
    }

    // Swap the minimum element with the current position
    swap(T[i], T[minInd]);
  }

  // After B iterations, T[B-1] contains the Bth smallest element
  return T[B - 1];
}

int main()
{
  cout << "=== Kth Smallest Element - Brute Force ===\n\n";

  // Test Case 1
  vector<int> A = {94, 87, 100, 11, 23, 98, 17, 35, 43, 66, 34, 53, 72, 80, 5, 34, 64, 71, 9, 16, 41, 66, 96};
  cout << "Test 1: Array size = " << A.size() << ", k = 19" << endl;
  cout << "Result: " << kthsmallest(A, 19) << "\n\n";

  // Test Case 2
  vector<int> B = {60, 94, 63, 3, 86, 40, 93, 36, 56, 48, 17, 10, 23, 43, 77, 1, 1, 93, 79, 4, 10, 47, 1, 99, 91, 53, 99, 18, 52, 61, 84, 10, 13, 52, 3, 9, 78, 16, 7, 62};
  cout << "Test 2: Array size = " << B.size() << ", k = 22" << endl;
  cout << "Result: " << kthsmallest(B, 22) << "\n\n";

  // Test Case 3
  vector<int> C = {1};
  cout << "Test 3: Array size = " << C.size() << ", k = 1" << endl;
  cout << "Result: " << kthsmallest(C, 1) << "\n\n";

  // Test Case 4: Simple example
  vector<int> D = {2, 1, 4, 3, 2};
  cout << "Test 4: [2, 1, 4, 3, 2], k = 3" << endl;
  cout << "Result: " << kthsmallest(D, 3) << " (Expected: 2)\n\n";

  // Test Case 5: Edge case - k = 1 (smallest)
  vector<int> E = {10, 5, 20, 15};
  cout << "Test 5: [10, 5, 20, 15], k = 1" << endl;
  cout << "Result: " << kthsmallest(E, 1) << " (Expected: 5)\n\n";

  // Test Case 6: Edge case - k = n (largest)
  cout << "Test 6: [10, 5, 20, 15], k = 4" << endl;
  cout << "Result: " << kthsmallest(E, 4) << " (Expected: 20)\n\n";

  // Test Case 7: Invalid k
  cout << "Test 7: [1, 2, 3], k = 10 (invalid)" << endl;
  cout << "Result: " << kthsmallest({1, 2, 3}, 10) << " (Expected: -1)\n";

  return 0;
}