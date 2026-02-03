#include <iostream>
#include <vector>
using namespace std;

// Find maximum profit from buying and selling a stock once
// TC: O(n) - single pass through array
// SC: O(1) - only using constant extra space
int buysellstock(vector<int> &A)
{
    if (A.empty())
        return 0;

    int maxProfit = 0;
    int minPrice = A[0];

    for (int i = 1; i < A.size(); i++)
    {
        minPrice = min(minPrice, A[i]);
        maxProfit = max(maxProfit, A[i] - minPrice);
    }
    return maxProfit;
}

// Unlimited buy and sell - can make multiple transactions
// TC: O(n) - single pass through array
// SC: O(1) - only using constant extra space
int unBuySellStock(vector<int> &A)
{
    if (A.empty())
        return 0;
        
    int maxProfit = 0;
    // Add profit whenever next day price is higher than current day
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i + 1] > A[i])
        {
            maxProfit += A[i + 1] - A[i];
        }
    }
    return maxProfit;
}
int main()
{
    cout << "Buy Sell Stock Problem\n";
    cout << "TC: O(n), SC: O(1)\n\n";

    // Test case 1: Normal case with profit opportunity
    vector<int> tc1{7, 1, 5, 3, 6, 4};
    cout << "TC1: {7, 1, 5, 3, 6, 4}" << endl;
    cout << "Expected: 7 (buy at 1, sell at 5 = 4, buy at 3, sell at 6 = 3)" << endl;
    cout << "Got: " << unBuySellStock(tc1) << endl
         << endl;

    // Test case 2: Decreasing prices (no profit)
    vector<int> tc2{7, 6, 4, 3, 1};
    cout << "TC2: {7, 6, 4, 3, 1}" << endl;
    cout << "Expected: 0 (no profit)" << endl;
    cout << "Got: " << unBuySellStock(tc2) << endl
         << endl;

    // Test case 3: Single element
    vector<int> tc3{5};
    cout << "TC3: {5}" << endl;
    cout << "Expected: 0 (need at least 2 prices)" << endl;
    cout << "Got: " << unBuySellStock(tc3) << endl
         << endl;

    // Test case 4: Increasing prices (buy and sell every day)
    vector<int> tc4{1, 2, 3, 4, 5};
    cout << "TC4: {1, 2, 3, 4, 5}" << endl;
    cout << "Expected: 4 (accumulate all increases: 1+1+1+1)" << endl;
    cout << "Got: " << unBuySellStock(tc4) << endl
         << endl;

    // Test case 5: Two elements
    vector<int> tc5{3, 8};
    cout << "TC5: {3, 8}" << endl;
    cout << "Expected: 5 (buy at 3, sell at 8)" << endl;
    cout << "Got: " << unBuySellStock(tc5) << endl;

    return 0;
}