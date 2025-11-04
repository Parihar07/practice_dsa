#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Approach 1: Using pointer arithmetic
int isSortedUsingPtr(int *A, size_t sz){
    // Base case: array with 0 or 1 element is always sorted
    if(sz == 1 || sz == 0)
        return 1;

    // If current element is greater than next, not sorted
    if(*A > *(A+1))
        return 0;

    // Recursively check rest of the array
    return isSortedUsingPtr(A + 1, sz - 1);
}

// Approach 2: Using vector and index
int isSortedUsingVector(const vector<int>& A, size_t index){
    if(A.empty() || index == A.size()-1)
        return 1;
    if(A[index]>A[index+1])
        return 0;
    return isSortedUsingVector(A,index+1);
}

int main(){
    cout << "Testing Array Sorted Checker (Recursive)\n";
    cout << "=========================================\n\n";
    
    // Test 1: Unsorted array
    int test1[] = {1, 4, 6, 3, 9, 7};
    vector<int> v1{1, 4, 6, 3, 9, 7};
    cout << "Test 1 - Unsorted [1,4,6,3,9,7]:\n";
    cout << "  Pointer: " << (isSortedUsingPtr(test1, 6) == 0 ? "✓ PASS" : "✗ FAIL") << "\n";
    cout << "  Vector:  " << (isSortedUsingVector(v1, 0) == 0 ? "✓ PASS" : "✗ FAIL") << "\n";
    
    // Test 2: Sorted array
    int test2[] = {1, 2, 3, 4, 5};
    vector<int> v2{1, 2, 3, 4, 5};
    cout << "\nTest 2 - Sorted [1,2,3,4,5]:\n";
    cout << "  Pointer: " << (isSortedUsingPtr(test2, 5) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    cout << "  Vector:  " << (isSortedUsingVector(v2, 0) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    
    // Test 3: Sorted with duplicates
    int test3[] = {1, 2, 2, 3, 3, 4};
    vector<int> v3{1, 2, 2, 3, 3, 4};
    cout << "\nTest 3 - Sorted with duplicates [1,2,2,3,3,4]:\n";
    cout << "  Pointer: " << (isSortedUsingPtr(test3, 6) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    cout << "  Vector:  " << (isSortedUsingVector(v3, 0) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    
    // Test 4: All same elements
    int test4[] = {5, 5, 5, 5};
    vector<int> v4{5, 5, 5, 5};
    cout << "\nTest 4 - All same [5,5,5,5]:\n";
    cout << "  Pointer: " << (isSortedUsingPtr(test4, 4) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    cout << "  Vector:  " << (isSortedUsingVector(v4, 0) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    
    // Test 5: Single element
    int test5[] = {42};
    vector<int> v5{42};
    cout << "\nTest 5 - Single element [42]:\n";
    cout << "  Pointer: " << (isSortedUsingPtr(test5, 1) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    cout << "  Vector:  " << (isSortedUsingVector(v5, 0) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    
    // Test 6: Empty array
    vector<int> v6{};
    cout << "\nTest 6 - Empty []:\n";
    cout << "  Vector:  " << (isSortedUsingVector(v6, 0) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    
    // Test 7: Decreasing order
    int test7[] = {5, 4, 3, 2, 1};
    vector<int> v7{5, 4, 3, 2, 1};
    cout << "\nTest 7 - Decreasing [5,4,3,2,1]:\n";
    cout << "  Pointer: " << (isSortedUsingPtr(test7, 5) == 0 ? "✓ PASS" : "✗ FAIL") << "\n";
    cout << "  Vector:  " << (isSortedUsingVector(v7, 0) == 0 ? "✓ PASS" : "✗ FAIL") << "\n";
    
    // Test 8: Negative numbers
    int test8[] = {-5, -3, -1, 0, 2};
    vector<int> v8{-5, -3, -1, 0, 2};
    cout << "\nTest 8 - Negative nums [-5,-3,-1,0,2]:\n";
    cout << "  Pointer: " << (isSortedUsingPtr(test8, 5) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    cout << "  Vector:  " << (isSortedUsingVector(v8, 0) == 1 ? "✓ PASS" : "✗ FAIL") << "\n";
    
    cout << "\n=========================================\n";
    cout << "All tests completed!\n";
    
    return 0;
}