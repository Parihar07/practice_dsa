#include<iostream>
#include<vector>
using namespace std;
int main()
{
    cout << "sum of aarray linera\n";
    vector<int> A{1, 2, 5, 6, 7, 8, 99, 7};
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        ans += A[i];
    }
    cout << "Sum of array : " << ans << endl;
    return 0;
}  