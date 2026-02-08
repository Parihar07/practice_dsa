#include <iostream>
#include <vector>
#include <string>
#include<stack>
using namespace std;

vector<int> firstNegInt(vector<int> &A, int k)
{
    vector<int> ans;
    for (int i = 0; i < A.size(); i++)
    {
        int s = i, e = (s + (k - 1)), filled = 0;

        for (int j = s; j <= e; j++)
        {
            if (A[j] < 0)
            {
                ans.push_back(A[j]);
                filled = 1;
                break;
            }
        }
        if(!filled){
            ans.push_back(0);
        }
        if (e == A.size() - 1)
            break;
    }
    return ans;
}

vector<int> firstNegIntOpt(vector<int> &A, int k) {
    stack<int> st;
    int filled = 0;
    for (int i = 0; i < k; i++)
    {
        if(A[i]<0){
            st.push(i);
            filled = 1;
        }
    }
    if(!filled)
        st.push(-1);

    for (int i = 1; i <= A.size() - k;i++){
        int e = i + (k - 1);
        int t = st.top();

        if(A[e]<0){
            if(t!=-1)
                st.push(t);
            else
                st.push(e);
        } else if(i-1==t){
            st.push(-1);
        } else {
            st.push(t);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top()==-1?0:A[st.top()]);
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    cout << "Hello, solving firs neagative integer in window of size k..\n";
    vector<int> A{2, -1, 3, 7, 3, 4, -1, 2, -3, 5, 6};
    auto ans = firstNegIntOpt(A, 3);
    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}