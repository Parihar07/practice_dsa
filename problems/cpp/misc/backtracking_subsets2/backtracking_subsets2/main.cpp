//
//  main.cpp
//  backtracking_subsets2
//
//  Created by CodeBreaker on 10/02/25.
//

#include <iostream>
#include<vector>
using namespace std;
void btrack(vector<int> A, vector<vector<int>> &ans, vector<int> &tmp, int i)
{
    if(i==A.size())
    {
//        for(auto i:tmp)
//        {
//            cout<<i<<" ";
//        }
//        cout<<endl;
        ans.push_back(tmp);
        return;
    }
    
    tmp.push_back(A[i]);
    btrack(A, ans, tmp, i+1);
    tmp.pop_back();
    btrack(A, ans, tmp, i+1);
}
vector<vector<int> > subsets(vector<int> &A) {
    vector<vector<int>> ans;
    vector<int> tmp;
    btrack(A, ans, tmp, 0);
    sort(ans.begin(), ans.end());
    
//    vector<pair<int,vector<int>>> sortedAns(ans.size());
//    
//    for(int i=0;i<ans.size();i++)
//    {
//        sortedAns[i].first = (int)ans[i].size();
//        sortedAns[i].second = ans[i];
//    }
//    
//    sort(sortedAns.begin(),sortedAns.end());
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> A{1,2,3};
    auto ans = subsets(A);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
