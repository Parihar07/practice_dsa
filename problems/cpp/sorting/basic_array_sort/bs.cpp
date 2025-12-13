/*
===============================================================================
PROBLEM: Basic Sorting (Selection-Style) with Custom Comparators
-------------------------------------------------------------------------------
Implement a basic O(n^2) sorting routine (selection-style) and support custom
comparators for ascending/descending ordering. Verify behavior with sample
arrays including negatives and duplicates.

APPROACH
- Two nested loops; for each position i, place the smallest (or largest) of the
  remaining elements at position i via swaps.
- Complexity: O(n^2) time, O(1) extra space.
===============================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Comparator: returns true when first should come AFTER second (ascending)
bool greaterCmp(int i, int j) { return i > j; }
// Comparator: returns true when first should come AFTER second (descending)
bool smallerCmp(int i, int j) { return i < j; }

// Selection-sort using a comparator (default: ascending via greaterCmp)
void basicsort_usingcomp(vector<int> &a, bool (*cmp)(int, int) = greaterCmp)
{
    if (a.empty()) return;
    for (size_t i = 0; i + 1 < a.size(); ++i)
    {
        for (size_t j = i + 1; j < a.size(); ++j)
        {
            if (cmp(a[i], a[j]))
            {
                swap(a[i], a[j]);
            }
        }
    }
}

// Simple ascending selection-sort without custom comparator
void basic_sort(vector<int> &a)
{
    if (a.empty()) return;
    for (size_t i = 0; i + 1 < a.size(); ++i)
    {
        for (size_t j = i + 1; j < a.size(); ++j)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

// Utility to print vectors
void print_vec(const vector<int>& v, const string& label)
{
    cout << label << ": ";
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int main()
{
    cout << "==== Basic Sorting Tests ====" << '\n';

    // Test case 1: mixed values
    vector<int> t1{23, 1, 4, 6323, 46, -12};
    auto asc1 = t1;
    auto asc2 = t1;
    basic_sort(asc1);
    basicsort_usingcomp(asc2);
    print_vec(t1,  "Input t1" );
    print_vec(asc1, "basic_sort asc" );
    print_vec(asc2, "comp asc" );
    cout << '\n';

    // Test case 2: duplicates
    vector<int> t2{5, 3, 5, 3, 5};
    auto asc3 = t2;
    auto desc3 = t2;
    basic_sort(asc3);
    basicsort_usingcomp(desc3, smallerCmp); // descending
    print_vec(t2,   "Input t2" );
    print_vec(asc3, "basic_sort asc" );
    print_vec(desc3,"comp desc" );
    cout << '\n';

    // Test case 3: already sorted ascending
    vector<int> t3{-5, -2, 0, 3, 9};
    auto asc4 = t3;
    auto desc4 = t3;
    basic_sort(asc4);
    basicsort_usingcomp(desc4, smallerCmp);
    print_vec(t3,   "Input t3" );
    print_vec(asc4, "basic_sort asc" );
    print_vec(desc4,"comp desc" );
    cout << '\n';

    // Test case 4: empty
    vector<int> t4{};
    basic_sort(t4);
    print_vec(t4, "Input/Output t4 (empty)" );
    cout << '\n';

    // Test case 5: single element
    vector<int> t5{42};
    basic_sort(t5);
    print_vec(t5, "Input/Output t5 (single)" );

    return 0;
}