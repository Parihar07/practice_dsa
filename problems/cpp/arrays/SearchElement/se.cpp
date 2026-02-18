/*
Problem: Linear Search in Array
Description: Find the index of a target element in an array using linear search.
Time Complexity: O(n) - where n is the size of the array
Space Complexity: O(1) - excluding the input array storage
*/

#include <iostream>
#include <cstdlib> // For EXIT_SUCCESS/FAILURE

using namespace std;

int main()
{
  int target = 0;
  cout << "Enter element to search: ";
  cin >> target;

  int size = 0;
  cout << "Enter array size: ";
  cin >> size;

  // Validate size
  if (size <= 0)
  {
    cerr << "Error: Array size must be positive." << endl;
    return EXIT_FAILURE;
  }

  // Allocate memory
  int *arr = new int[size];
  if (!arr)
  {
    cerr << "Error: Memory allocation failed." << endl;
    return EXIT_FAILURE;
  }

  // Read array elements
  cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  // Linear search
  int foundIndex = -1; // Use -1 to indicate "not found"
  for (int i = 0; i < size; i++)
  {
    if (target == arr[i])
    {
      foundIndex = i;
      break; // Stop searching once found
    }
  }

  // Output result
  if (foundIndex != -1)
  {
    cout << "Element " << target << " found at index " << foundIndex << endl;
  }
  else
  {
    cout << "Element " << target << " not found in the array." << endl;
  }

  // Clean up memory
  delete[] arr;

  return EXIT_SUCCESS;
}

/*
Test Cases (TC's):
---------------
Test Case 1: Element found at beginning
Input: target = 5, size = 5, arr = [5, 2, 8, 1, 9]
Output: "Element 5 found at index 0"

Test Case 2: Element found at end
Input: target = 9, size = 5, arr = [5, 2, 8, 1, 9]
Output: "Element 9 found at index 4"

Test Case 3: Element found in middle
Input: target = 8, size = 5, arr = [5, 2, 8, 1, 9]
Output: "Element 8 found at index 2"

Test Case 4: Element not found
Input: target = 10, size = 5, arr = [5, 2, 8, 1, 9]
Output: "Element 10 not found in the array."

Test Case 5: Single element array (found)
Input: target = 7, size = 1, arr = [7]
Output: "Element 7 found at index 0"

Test Case 6: Single element array (not found)
Input: target = 7, size = 1, arr = [3]
Output: "Element 7 not found in the array."

Test Case 7: Empty array (invalid input)
Input: target = 5, size = 0
Output: "Error: Array size must be positive."

Test Case 8: Duplicate elements (finds first occurrence)
Input: target = 5, size = 6, arr = [1, 5, 3, 5, 7, 5]
Output: "Element 5 found at index 1"

Test Case 9: Negative numbers
Input: target = -3, size = 4, arr = [1, -3, 5, -7]
Output: "Element -3 found at index 1"

Test Case 10: Large array
Input: target = 999, size = 1000, arr = [0..999]
Output: "Element 999 found at index 999"

Time Complexity Analysis:
- Best Case: O(1) - Element found at first position
- Average Case: O(n/2) ≈ O(n) - Element found in the middle
- Worst Case: O(n) - Element not found or found at last position

Space Complexity Analysis:
- Input storage: O(n) for the array
- Auxiliary space: O(1) - only using a few variables (target, size, i, foundIndex)
*/
