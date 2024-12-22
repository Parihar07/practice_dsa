//
//  main.cpp
//  arrays_BinaryFlip
//
//  Created by CodeBreaker on 19/12/24.
//
/*
 Flip
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a binary string A(i.e., with characters 0 and 1) consisting of characters A1, A2, ..., AN. In a single operation, you can choose two indices, L and R, such that 1 ≤ L ≤ R ≤ N and flip the characters AL, AL+1, ..., AR. By flipping, we mean changing character 0 to 1 and vice-versa.
 Your aim is to perform ATMOST one operation such that in the final string number of 1s is maximized.
 If you don't want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.
 NOTE: Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.


 Problem Constraints
 1 <= size of string <= 100000


 Input Format
 First and only argument is a string A.


 Output Format
 Return an array of integers denoting the answer.


 Example Input
 Input 1:
 A = "010"
 Input 2:
 A = "111"


 Example Output
 Output 1:
 [1, 1]
 Output 2:
 []


 Example Explanation
 Explanation 1:
 A = "010"

 Pair of [L, R] | Final string
 _______________|_____________
 [1 1]          | "110"
 [1 2]          | "100"
 [1 3]          | "101"
 [2 2]          | "000"
 [2 3]          | "001"

 We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
 Explanation 2:
 No operation can give us more than three 1s in final string. So, we return empty array [].
 */
#include <iostream>
#include <string>
using namespace std;


vector<int> flip(string A) {
    vector<int> ans(2,0);
    size_t N = A.size();
    int L=0,maxi=0,sum=0;
    for(int i=0;i<N;i++)
    {
        if(A[i]=='1')
        {
            sum-=1;
        } else {
            sum+=1;
        }

        if(sum>maxi)
        {
            maxi=sum;
            ans[0]=L;
            ans[1]=i;
        }
        
        if(sum<0)
        {
            sum=0;
            L=i+1;
        }
    }
    if(maxi==0) return vector<int>();
    
    ans[0]+=1;
    ans[1]+=1; //since result 1 based index
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Max Flip!\n";
    string A = "110001111";
    vector<int> ans = flip(A);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<< " ";
    }
    cout<<endl;
    return 0;
}
