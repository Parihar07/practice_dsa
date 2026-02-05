#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxProductSubArray(vector<int> &A)
{
    int maxProd = A[0]; // max product ending here
    int minProd = A[0]; // min product ending here
    int result = A[0];  // overall maximum

    for (int i = 1; i < A.size(); i++)
    {
        int temp = maxProd; // save previous maxProd

        // Update max and min by considering current element
        maxProd = max(A[i], max(maxProd * A[i], minProd * A[i]));
        minProd = min(A[i], min(temp * A[i], minProd * A[i]));

        // Update result
        result = max(result, maxProd);
    }
    return result;
}

int main()
{
    cout << "solving max product subarray..\n";

    vector<int> A{1,3,2,4,-1,5,4,2,-2,-7,2,1};
    cout << "max product subarray : " << maxProductSubArray(A) << endl;
    return 0;
}