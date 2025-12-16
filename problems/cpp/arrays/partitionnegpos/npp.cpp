#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Partition Negatives and Positives

Given an integer array, move all negative numbers to the front and all
non-negative numbers (>= 0) to the back. Do it in-place.

Notes:
- This two-pointer swap approach is O(n) time, O(1) space.
- It preserves the relative order of negatives, but the relative order of
    non-negatives may change (not fully stable overall).

Example:
Input : [7, -1, 3, -3, 5, -4, 9]
Output: [-1, -3, -4, 7, 3, 5, 9]
*/


//Negative elements order are maintained 
void pnegpos(vector<int> &A)
{
    int j = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] < 0)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
}

// Positive elements order are maintained
void pnegpos2(vector<int> &A)
{
    int j = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] > 0)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
}


//Maintaining both the orders
void pnegpos3(vector<int> &A){
    vector<int> tmp(A.size());
    int j = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] < 0)
        {
            tmp[j] = A[i];
            j++;
        }
    }
    //j = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] >= 0)
        {
            tmp[j] = A[i];
            j++;
        }
    }
    for (size_t i = 0; i < A.size(); i++)
    {
        A[i] = tmp[i];
    }
}

static void runTest(vector<int> A)
{
    cout << "Input : ";
    for (int v : A)
        cout << v << ' ';
    cout << '\n';
    pnegpos3(A);
    cout << "Output: ";
    for (int v : A)
        cout << v << ' ';
    cout << "\n\n";
}



int main()
{
    cout << "Partition negatives to front (in-place)\n\n";

    runTest({7, -1, 3, -3, 5, -4, 9}); // mixed
    runTest({-5, -2, -7});             // all negatives
    runTest({0, 2, 4, 6});             // no negatives (0 treated as non-negative)
    runTest({});                       // empty
    runTest({0, -1, 0, -2, 0, 3});     // with zeros

    return 0;
}