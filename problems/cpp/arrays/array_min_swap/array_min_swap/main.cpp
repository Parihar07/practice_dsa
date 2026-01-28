//
//  main.cpp
//  array_min_swap
//
//  Created by CodeBreaker on 19/08/1946 Saka.
//

#include <algorithm> // For std::min, std::count_if
#include <iostream>
#include <vector>

// Standard namespace is avoided in global scope for professional C++ style
// using namespace std;

/**
 * @brief Solves the Minimum Swaps problem using the Sliding Window technique.
 *
 * System View:
 * - Time Complexity: O(N) - Two passes over the array.
 * - Space Complexity: O(1) - No extra allocation proportional to N.
 * - Memory Access: Sequential scan, cache-friendly (spatial locality).
 *
 * @param A The input array (passed by const reference to avoid copy and ensure
 * immutability).
 * @param B The threshold value.
 * @return int The minimum number of swaps required.
 */
int solveOpt(const std::vector<int> &A, int B) {
  size_t N = A.size();
  if (N <= 1)
    return 0;

  // Step 1: Count total elements <= B. This determines our window size 'T'.
  // Modern C++: Use std::count_if for readability and potential parallelization
  // execution policies (C++17).
  int T = static_cast<int>(
      std::count_if(A.begin(), A.end(), [B](int x) { return x <= B; }));

  if (T == 0)
    return 0; // No elements to group

  // Step 2: Initialize current window [0, T-1]
  // count 'bad' elements (elements > B) in the first window.
  // 'bad' elements are the ones we need to swap out.
  int bad_count = 0;
  for (int k = 0; k < T; k++) {
    if (A[k] > B) {
      bad_count++;
    }
  }

  int min_swaps = bad_count;

  // Step 3: Slide the window across the array
  // Window moves from [0, T-1] -> [1, T] ... -> [N-T, N-1]
  // We update bad_count incrementally.
  //
  // [FIX] Loop condition changed from i < N-T to i <= N-T
  // Original Code: i < N-T missed the last window starting at N-T.
  for (int i = 1; i <= N - T; i++) {
    // Remove element leaving the window: A[i-1]
    if (A[i - 1] > B) {
      bad_count--;
    }

    // Add element entering the window: A[i+T-1]
    if (A[i + T - 1] > B) {
      bad_count++;
    }

    min_swaps = std::min(min_swaps, bad_count);
  }

  return min_swaps;
}

void test_runner() {
  struct TestCase {
    std::vector<int> A;
    int B;
    int expected;
  };

  std::vector<TestCase> tests = {
      {{1, 12, 10, 3, 14, 10, 5}, 8, 2},
      {{5, 17, 100, 11}, 20, 1},
      {{1, 10, 10, 1}, 1, 1}, // Edge case: Optimization at the end
  };

  std::cout << "Running diagnostics...\n";
  for (const auto &test : tests) {
    int result = solveOpt(test.A, test.B);
    std::cout << "Input Size: " << test.A.size() << ", B: " << test.B
              << " | Got: " << result << " | Expected: " << test.expected;

    if (result == test.expected) {
      std::cout << " [PASS]\n";
    } else {
      std::cout << " [FAIL]\n";
    }
  }
}

int main(int argc, const char *argv[]) {
  std::cout << "Hello, Array minimum swaps!\n";
  std::cout << "------------------\n";

  // Run verification tests
  test_runner();

  // Original quick check
  // std::vector<int> A = {6414, -750, ...}; // Removed large junk data for
  // clarity std::cout << "Minimum Swaps : " << solveOpt(A, 45) << std::endl;

  return 0;
}
