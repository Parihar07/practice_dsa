#include<iostream>
#include<vector>
using namespace std;

int isSorted(vector<int> &A)
{
    if(A.empty() || (A.size()==1))
        return 1;
    for (size_t i = 0; i < A.size() - 1; i++){
        if(A[i] > A[i+1])  // If current element is greater than next, array is NOT sorted
            return 0;
    }
    return 1;
}
int main(){
    cout << "Testing Array Sorted Checker\n";
    cout << "=============================\n\n";
    
    // Test 1: Unsorted array
    vector<int> test1{1, 4, 6, 3, 9, 7};
    cout << "Test 1 - Unsorted [1,4,6,3,9,7]: ";
    cout << (isSorted(test1) == 0 ? "✓ PASS (Not sorted)" : "✗ FAIL") << "\n";
    
    // Test 2: Sorted array
    vector<int> test2{1, 2, 3, 4, 5};
    cout << "Test 2 - Sorted [1,2,3,4,5]: ";
    cout << (isSorted(test2) == 1 ? "✓ PASS (Sorted)" : "✗ FAIL") << "\n";
    
    // Test 3: Sorted with duplicates
    vector<int> test3{1, 2, 2, 3, 3, 4};
    cout << "Test 3 - Sorted with duplicates [1,2,2,3,3,4]: ";
    cout << (isSorted(test3) == 1 ? "✓ PASS (Sorted)" : "✗ FAIL") << "\n";
    
    // Test 4: All same elements
    vector<int> test4{5, 5, 5, 5};
    cout << "Test 4 - All same [5,5,5,5]: ";
    cout << (isSorted(test4) == 1 ? "✓ PASS (Sorted)" : "✗ FAIL") << "\n";
    
    // Test 5: Empty array
    vector<int> test5{};
    cout << "Test 5 - Empty []: ";
    cout << (isSorted(test5) == 1 ? "✓ PASS (Sorted)" : "✗ FAIL") << "\n";
    
    // Test 6: Single element
    vector<int> test6{42};
    cout << "Test 6 - Single element [42]: ";
    cout << (isSorted(test6) == 1 ? "✓ PASS (Sorted)" : "✗ FAIL") << "\n";
    
    // Test 7: Decreasing order
    vector<int> test7{5, 4, 3, 2, 1};
    cout << "Test 7 - Decreasing [5,4,3,2,1]: ";
    cout << (isSorted(test7) == 0 ? "✓ PASS (Not sorted)" : "✗ FAIL") << "\n";
    
    // Test 8: Negative numbers
    vector<int> test8{-5, -3, -1, 0, 2};
    cout << "Test 8 - Negative nums [-5,-3,-1,0,2]: ";
    cout << (isSorted(test8) == 1 ? "✓ PASS (Sorted)" : "✗ FAIL") << "\n";
    
    cout << "\n=============================\n";
    cout << "All tests completed!\n";
    
    return 0;
}