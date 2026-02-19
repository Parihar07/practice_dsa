#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Binary Search Algorithm
Time Complexity: O(log n)
Space Complexity: O(1)
Returns: Index of target if found, -1 otherwise
*/
int binarySearch(const vector<int> &arr, int target)
{
    // Handle empty array
    if (arr.empty())
    {
        return -1;
    }

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        // Prevent integer overflow
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid; // Target found
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // Search right half
        }
        else
        {
            right = mid - 1; // Search left half
        }
    }

    return -1; // Target not found
}

// Test function to verify binary search
void runTests()
{
    cout << "Running Binary Search Tests...\n";

    struct TestCase
    {
        vector<int> arr;
        int target;
        int expected;
        string description;
    };

    vector<TestCase> testCases = {
        {{-1, 0, 3, 5, 9, 12}, 9, 4, "Target found in middle"},
        {{-1, 0, 3, 5, 9, 12}, 2, -1, "Target not found"},
        {{-1, 0, 3, 5, 9, 12}, -1, 0, "Target at beginning"},
        {{-1, 0, 3, 5, 9, 12}, 12, 5, "Target at end"},
        {{}, 5, -1, "Empty array"},
        {{5}, 5, 0, "Single element array (found)"},
        {{5}, 3, -1, "Single element array (not found)"},
        {{1, 3, 5, 7, 9, 11, 13}, 7, 3, "Odd-sized array"},
        {{1, 3, 5, 7, 9, 11}, 3, 1, "Even-sized array"},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6, 5, "Large array"}};

    int passed = 0;
    int total = testCases.size();

    for (const auto &tc : testCases)
    {
        int result = binarySearch(tc.arr, tc.target);
        bool success = (result == tc.expected);

        cout << "\nTest: " << tc.description << endl;
        cout << "  Array: [";
        for (size_t i = 0; i < tc.arr.size(); i++)
        {
            cout << tc.arr[i];
            if (i < tc.arr.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
        cout << "  Target: " << tc.target << endl;
        cout << "  Expected: " << tc.expected << endl;
        cout << "  Result: " << result << endl;
        cout << "  Status: " << (success ? "PASS" : "FAIL") << endl;

        if (success)
            passed++;
    }

    cout << "\n=== Test Summary ===" << endl;
    cout << "Passed: " << passed << "/" << total << endl;
    cout << "Success Rate: " << (passed * 100 / total) << "%" << endl;
}

int main()
{
    cout << "Binary Search Implementation\n";
    cout << "============================\n";

    // Run automated tests
    runTests();

    // Example usage
    cout << "\nExample Usage:\n";
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int result = binarySearch(arr, target);

    cout << "Searching for " << target << " in array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    cout << "Result: " << (result != -1 ? "Found at index " + to_string(result) : "Not found") << endl;

    return 0;
}
