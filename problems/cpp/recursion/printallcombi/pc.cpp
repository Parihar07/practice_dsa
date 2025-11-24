#include <iostream>
#include <vector>

/**
 * @brief Recursively finds and prints all subsequences of a vector of integers.
 *
 * @param input The input vector of integers (read-only).
 * @param currentSubsequence The subsequence being built in the current recursive path.
 * @param index The current index in the input vector to consider.
 */
void printAllSubsequences(const std::vector<int> &input, std::vector<int> &currentSubsequence, int index)
{
    // Base case: If we have considered all elements, print the current subsequence.
    if (index == input.size())
    {
        for (int num : currentSubsequence)
        {
            std::cout << num << " ";
        }
        std::cout << "\n";
        return;
    }

    // Decision 1: Include the current element in the subsequence.
    currentSubsequence.push_back(input[index]);
    printAllSubsequences(input, currentSubsequence, index + 1);

    // Backtrack: Remove the current element to explore the other path.
    currentSubsequence.pop_back();

    // Decision 2: Do not include the current element in the subsequence.
    printAllSubsequences(input, currentSubsequence, index + 1);
} 

/**
 * @brief Iteratively finds and prints all subsequences using bit manipulation.
 *
 * @param nums The input vector of integers.
 */
void printAllSubsequencesIterative(const std::vector<int> &nums)
{
    int n = nums.size();
    // There are 2^n possible subsequences. We iterate from 0 to 2^n - 1.
    // (1 << n) is a fast way to compute 2^n.
    for (int i = 0; i < (1 << n); ++i)
    {
        // For each number 'i', we check its bits to form a subsequence.
        for (int j = 0; j < n; ++j)
        {
            // If the j-th bit is set in 'i', include nums[j] in the subsequence.
            // (i >> j) & 1 checks if the j-th bit is 1.
            if ((i >> j) & 1)
            {
                std::cout << nums[j] << " ";
            }
        }
        std::cout << "\n";
    }
}

int main()
{
    std::cout << "Printing all subsequences (subsets) of {1, 2, 3}:\n";
    std::vector<int> nums{1, 2, 3};
    std::vector<int> emptySubset;
    // printAllSubsequences(nums, emptySubset, 0); // Recursive way
    printAllSubsequencesIterative(nums); // Iterative way

    std::cout << "\nTest 1: {1,2,3}" << std::endl;
    std::vector<int> A{1, 2, 3};
    std::vector<int> b;
    printAllSubsequences(A, b, 0);

    std::cout << "\nTest 2: {5}" << std::endl;
    std::vector<int> C{5};
    b.clear();
    printAllSubsequences(C, b, 0);

    std::cout << "\nTest 3: {7,8}" << std::endl;
    std::vector<int> D{7, 8};
    b.clear();
    printAllSubsequences(D, b, 0);

    std::cout << "\nTest 4: {} (empty input)" << std::endl;
    std::vector<int> E;
    b.clear();
    printAllSubsequences(E, b, 0);

    std::cout << "\nTest 5: {1,2,3,4}" << std::endl;
    std::vector<int> F{1, 2, 3, 4};
    b.clear();
    printAllSubsequences(F, b, 0);

    return 0;
}