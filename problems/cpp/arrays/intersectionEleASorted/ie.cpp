#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> interElements(vector<int> &A, vector<int> &B)
{

    vector<int> ans;
    size_t i = 0;
    for (; i < (A.size() < B.size() ? A.size() : B.size()); i++)
    {
        if (A[i] == B[i])
        {
            ans.push_back(A[i]);
        }
        else if (A[i] < B[i])
        {
            ans.push_back(A[i]);
            ans.push_back(B[i]);
        }
        else
        {
            ans.push_back(B[i]);
            ans.push_back(A[i]);
        }
    }
    for (size_t j = i; j < (A.size() > B.size() ? A.size() : B.size()); j++)
    {
        ans.push_back((A.size() > B.size() ? A[j] : B[j]));
    }
    return ans;
}

int main()
{
    cout << "Intersecting elements in sorted array..\n";
    vector<int> A{1, 2, 3, 4, 5}, B{1, 2, 5, 6};
    vector<int> ans = interElements(A, B);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}