//
//  main.cpp
//  print_subarray_recursion
//
//  Created by CodeBreaker on 14/06/25.
//

#include <iostream>
#include <vector>
using namespace std;

//Printing all subsequence of given array or powerset

void printSubSeq(vector<int> &A, vector<int> &ans, int ind)
{
    if(ind >= A.size()){
        for(int p : ans)
        {
            cout<<p<<" ";
        }
        cout<<endl;
        return;
    }
    
    //So inorder to print the subsequence either you need pick the eleemnt or dont pick the element
    //Pick case, if yo pick push the element in ans list
    ans.push_back(A[ind]);
    printSubSeq(A, ans, ind+1);
    
    //No pick case, here you are not picking hence call as it is
    ans.pop_back();
    printSubSeq(A, ans, ind+1);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Print all the subsequence of given array!\n";
    vector<int> A{1,2,3,4}, ans;
    printSubSeq(A, ans, 0);
    return 0;
}
