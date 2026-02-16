
/*
Problem Statement:
------------------
Given an array A of N integers and a window size k, find the maximum number of "peaks" in any window of size k.
A "peak" is an element that is strictly greater than its immediate neighbors.
Return the maximum number of peaks in any such window.

Time Complexity: O(N)
Space Complexity: O(1) (excluding input array)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &A, int k)
{
  int N = A.size();
  if (k <= 2)
    return 0;

  int l = 0, r = k;
  int peak = 0;
  // Calculate peaks for the first window [0...k-1]
  // A peak must have two neighbors, so we only check [1...k-2]
  for (int i = l + 1; i < k - 1; i++)
  {
    if (A[i] > A[i - 1] && A[i] > A[i + 1])
    {
      peak++;
    }
  }
  int maxPeak = peak;

  while (r < N)
  {
    // The window is sliding FROM [l, r-1] TO [l+1, r]

    // A peak is leaving the scannable area at the left side (index l+1)
    if (A[l + 1] > A[l] && A[l + 1] > A[l + 2])
    {
      peak--;
    }

    // A new peak might be forming on the right side (index r-1)
    if (A[r - 1] > A[r - 2] && A[r - 1] > A[r])
    {
      peak++;
    }

    // Update maxPeak with the count for the new window's peak set
    maxPeak = max(maxPeak, peak);

    // Slide the window
    l++;
    r++;
  }
  return maxPeak;
}

void run_test(const vector<int> &A, int k, int expected)
{
  vector<int> arr = A;
  int result = solve(arr, k);
  cout << "A = [";
  for (size_t i = 0; i < arr.size(); ++i)
  {
    cout << arr[i];
    if (i + 1 < arr.size())
      cout << ", ";
  }
  cout << "], k = " << k << ", Max peaks = " << result;
  if (expected != -1)
    cout << ", Expected = " << expected << (result == expected ? " [PASS]" : " [FAIL]");
  cout << endl;
}

int main()
{
  cout << "Solving the peak element problem\n";
  // Test cases
  run_test({2, 5, 3, 2, 5, 3, 2, 5}, 6, 2);    // Example
  run_test({1, 2, 3, 4, 5}, 3, 0);             // No peaks
  run_test({1, 3, 2, 4, 1, 5, 2}, 4, 2);       // Multiple peaks
  run_test({5, 4, 3, 2, 1}, 3, 0);             // Descending
  run_test({1, 2, 1, 2, 1, 2, 1}, 5, 2);       // Alternating peaks
  run_test({1, 2, 3, 2, 1, 2, 3, 2, 1}, 5, 2); // Peaks in the middle
  run_test({1, 2}, 2, 0);                      // Too small for peaks
  run_test({1}, 1, 0);                         // Single element
  run_test({2, 1, 2, 1, 2, 1, 2}, 3, 1);       // Small window
  run_test({10, 20, 15, 25, 10, 30, 5}, 7, 3); // Full window
  return 0;
}