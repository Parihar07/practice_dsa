/*
 * PROBLEM STATEMENT:
 * Find the union of two arrays A and B.
 * Return all unique elements that are present in either array A or array B (or both).
 * The union contains all distinct elements from both arrays.
 * 
 * Example:
 * A = [1, 2, 3, 4, 5, 6]
 * B = [1, 2, 3, 7, 8]
 * Output = [1, 2, 3, 4, 5, 6, 7, 8] (order may vary)
 * 
 * TIME COMPLEXITY: O(m + n)
 * - Where m = size of array A, n = size of array B
 * - Insert all elements from A into set: O(m)
 * - Insert all elements from B into set: O(n)
 * - Copy set to result vector: O(m + n) in worst case
 * 
 * SPACE COMPLEXITY: O(m + n)
 * - Unordered set stores all unique elements from both arrays: O(m + n)
 * - Result vector stores all unique elements: O(m + n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> unionEle(vector<int> &A, vector<int> &B)
{
    unordered_set<int> us;
    
    // Insert all elements from both arrays into the set
    for (int x : A)
        us.insert(x);
    
    for (int x : B)
        us.insert(x);
    
    // Convert set to vector
    vector<int> ans(us.begin(), us.end());
    
    return ans;
}

int main()
{
    // Test Case 1: Basic union
    cout << "Test Case 1: Basic union\n";
    vector<int> A1{1, 2, 3, 4, 5, 6}, B1{1, 2, 3};
    vector<int> ans1 = unionEle(A1, B1);
    cout << "A = [1, 2, 3, 4, 5, 6], B = [1, 2, 3]\n";
    cout << "Output: ";
    for (auto x : ans1)
        cout << x << " ";
    cout << "\nExpected: [1, 2, 3, 4, 5, 6] (order may vary)\n\n";
    
    // Test Case 2: Disjoint sets (no common elements)
    cout << "Test Case 2: Disjoint sets\n";
    vector<int> A2{1, 2, 3}, B2{4, 5, 6};
    vector<int> ans2 = unionEle(A2, B2);
    cout << "A = [1, 2, 3], B = [4, 5, 6]\n";
    cout << "Output: ";
    for (auto x : ans2)
        cout << x << " ";
    cout << "\nExpected: [1, 2, 3, 4, 5, 6] (order may vary)\n\n";
    
    // Test Case 3: Identical arrays
    cout << "Test Case 3: Identical arrays\n";
    vector<int> A3{1, 2, 3}, B3{1, 2, 3};
    vector<int> ans3 = unionEle(A3, B3);
    cout << "A = [1, 2, 3], B = [1, 2, 3]\n";
    cout << "Output: ";
    for (auto x : ans3)
        cout << x << " ";
    cout << "\nExpected: [1, 2, 3] (order may vary)\n\n";
    
    // Test Case 4: Partial overlap
    cout << "Test Case 4: Partial overlap\n";
    vector<int> A4{1, 2, 3, 4, 5}, B4{3, 4, 5, 6, 7};
    vector<int> ans4 = unionEle(A4, B4);
    cout << "A = [1, 2, 3, 4, 5], B = [3, 4, 5, 6, 7]\n";
    cout << "Output: ";
    for (auto x : ans4)
        cout << x << " ";
    cout << "\nExpected: [1, 2, 3, 4, 5, 6, 7] (order may vary)\n\n";
    
    // Test Case 5: One empty array
    cout << "Test Case 5: One empty array\n";
    vector<int> A5{1, 2, 3}, B5{};
    vector<int> ans5 = unionEle(A5, B5);
    cout << "A = [1, 2, 3], B = []\n";
    cout << "Output: ";
    for (auto x : ans5)
        cout << x << " ";
    cout << "\nExpected: [1, 2, 3] (order may vary)\n\n";
    
    // Test Case 6: Arrays with duplicates
    cout << "Test Case 6: Arrays with duplicates\n";
    vector<int> A6{1, 1, 2, 2, 3}, B6{2, 2, 3, 3, 4};
    vector<int> ans6 = unionEle(A6, B6);
    cout << "A = [1, 1, 2, 2, 3], B = [2, 2, 3, 3, 4]\n";
    cout << "Output: ";
    for (auto x : ans6)
        cout << x << " ";
    cout << "\nExpected: [1, 2, 3, 4] (order may vary)\n\n";
    
    return 0;
}