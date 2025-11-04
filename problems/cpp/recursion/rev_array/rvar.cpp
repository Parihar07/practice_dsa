#include<iostream>
#include<vector>
#include<string>
using namespace std;

void revArray(vector<int> &A, int s, int e){
    if(A.empty() || A.size() == 1 || s>e)
        return;
    int t = A[s];
    A[s] = A[e];
    A[e] = t;
    return revArray(A, s + 1, e - 1);
}

int main(){
    cout << "Testing Reverse Array (Recursive)\n";
    cout << "==================================\n\n";
    
    // Test 1: Normal case
    vector<int> test1{2, 3, 4, 5, 6};
    revArray(test1, 0, test1.size()-1);
    cout << "Test 1 - [2,3,4,5,6]: ";
    for(auto i : test1) cout << i << " ";
    cout << (test1 == vector<int>{6,5,4,3,2} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 2: Palindrome
    vector<int> test2{1, 2, 3, 2, 1};
    revArray(test2, 0, test2.size()-1);
    cout << "Test 2 - [1,2,3,2,1]: ";
    for(auto i : test2) cout << i << " ";
    cout << (test2 == vector<int>{1,2,3,2,1} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 3: Problem example
    vector<int> test3{1, 1, 10};
    revArray(test3, 0, test3.size()-1);
    cout << "Test 3 - [1,1,10]: ";
    for(auto i : test3) cout << i << " ";
    cout << (test3 == vector<int>{10,1,1} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 4: Single element
    vector<int> test4{42};
    revArray(test4, 0, test4.size()-1);
    cout << "Test 4 - [42]: ";
    for(auto i : test4) cout << i << " ";
    cout << (test4 == vector<int>{42} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 5: Two elements
    vector<int> test5{10, 20};
    revArray(test5, 0, test5.size()-1);
    cout << "Test 5 - [10,20]: ";
    for(auto i : test5) cout << i << " ";
    cout << (test5 == vector<int>{20,10} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 6: All same
    vector<int> test6{5, 5, 5, 5};
    revArray(test6, 0, test6.size()-1);
    cout << "Test 6 - [5,5,5,5]: ";
    for(auto i : test6) cout << i << " ";
    cout << (test6 == vector<int>{5,5,5,5} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 7: Empty array
    vector<int> test7{};
    revArray(test7, 0, 0);
    cout << "Test 7 - []: ";
    cout << (test7.empty() ? "✓ PASS" : "✗ FAIL") << "\n";
    
    cout << "\n==================================\n";
    return 0;
}