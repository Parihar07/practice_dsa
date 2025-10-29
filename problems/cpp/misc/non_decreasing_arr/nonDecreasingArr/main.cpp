//
//  main.cpp
//  nonDecreasingArr
//
//  Created by CodeBreaker on 10/08/1946 Saka.
//
/*
 Non decreasing subarray queries
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array A of size N. You will be given M queries to process. Each query will be of the form B[i][0] B[i][1].

 If the subarray from B[i][0] to B[i][1] is non decreasing, the output should be 1 else output should be 0.

 Return an array of integers answering each query.


 Problem Constraints
 1 <= N <= 105

 1 <= A[i] <= 109

 1 <= M <= 105

 0 <= B[i][0], B[i][1] <= N-1


 Input Format
 First argument contains the array A.

 Second argument contains B, denoting the queries.


 Output Format
 Return an array of integers consisting of 0 and 1


 Example Input
 Input 1:
 A = [1, 7, 3, 4, 9]
 B = [
       [0, 1],
       [1, 4]
     ]
 Input 2:
 A = [1, 1, 7, 2, 3]
 B = [
       [0, 2],
       [2, 4]
     ]


 Example Output
 Output 1 :
 [1, 0]
 Output 2 :
 [1, 0]


 Example Explanation
 Explanation 1 :
 Query 1: The subarray in the range [0, 1] is {1, 7} which is non-decreasing. Therefore, ans = 1
 Query 2: The subarray in the range [1, 4] is {7, 3, 4, 9} which is not non-decreasing. Therefore, ans = 0
 Explanation 1 :
 Query 1: The subarray in the range [0, 2] is {1, 1, 7} which is non-decreasing. Therefore, ans = 1
 Query 2: The subarray in the range [2, 4] is {7, 2, 3} which is not non-decreasing. Therefore, ans = 0sdfa
 */
#include <iostream>
#include<vector>
using namespace std;

int chkNonDecreasing(vector<int> &A, int s, int e)
{
    int ans=1;
    for(int i=s;i<=e-1;i++)
    {
        if(A[i]<=A[i+1])
        {
            continue;
        } else {
            return 0;
        }
    }
    return ans;
}
vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
    vector<int> ans(B.size());
    for(int i=0;i<B.size();i++)
    {
        ans[i]=chkNonDecreasing(A, B[i][0], B[i][1]);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, NonDEcreasingArray problem!\n";
    vector<int> v{44,53,29,143,66,196,124,166,132,48,57,60,3,168,32,166,73,54,58,101,101,157,100,87,119,20,121,141,200,108,31,195,30,86,173,84,62,22,70,44,58,50,8,89,113,71,77,180,197,191,113,182,41,105,100,150,180,2,177,95,117,44,130,77,182,110,104,49,164,120,114,79,46,151,63,199,178,66,129,60,57,94,24,187,124,52,73,37,7,102,126,60,198,145,121,19,130,79,20,73,21,80,190,101,80,50,167,125,118,103,157,192,127,138,130,122,70,179,21,142,147,29,11,120,89,59,11,114,90,106,178,24,142,154,138,137,29,186,131,119,47,160,96,163,49,136,45,133,73,146,140,116,92,85,118};
    vector<vector<int>> b{    {67,87},{126,127},{45,117},{0,125},{29,91},{25,83},{99,139},{66,102},{60,93},{110,111},{146,147},{15,59},{127,144},{137,145},{85,117},{80,84},{37,86},{152,154},{136,137},{99,119},{85,120},{144,148},{53,54},{72,137},{63,80},{31,36},{88,89},{133,142},{58,125},{143,153},{76,83},{22,140},{136,154},{79,99},{35,147},{130,151},{125,126},{14,64},{16,93},{129,133},{120,148},{152,154},{125,144},{30,44},{52,110},{9,141},{88,90},{124,140},{89,93},{138,144},{98,112},{66,151},{127,151},{104,109},{98,119},{142,152},{91,142},{16,139},{12,154},{142,144},{10,105},{109,141},{50,77},{129,145},{138,146},{7,35},{52,130},{2,27},{105,123},{61,86},{80,130},{104,151},{43,74},{149,154},{54,118},{114,120},{138,153},{9,106},{97,110},{47,93},{86,139},{13,32},{116,145},{99,147},{87,111},{52,134},{94,110},{47,79},{109,116},{93,95},{85,120},{124,153},{119,137},{53,129},{63,131},{114,122},{115,145},{1,16},{41,108},{104,112},{80,105},{132,145},{43,133},{92,141},{80,86},{21,27},{146,148},{6,15},{84,111},{23,136},{152,153},{59,100},{61,64},{147,149},{75,142},{119,130},{148,151},{54,118},{97,104},{66,130},{38,152},{116,152},{127,142},{78,115},{19,64},{27,47},{76,109},{60,61},{103,130},{32,85},{17,137},{97,142},{92,148},{112,140},{63,98},{88,112},{93,126},{57,103},{25,67},{143,151},{9,87},{55,60},{95,130},{135,148},{8,62},{100,142},{100,137},{18,24},{75,141},{146,151},{53,71},{57,72},{98,121},{55,84},{66,154},{79,133},{74,124},{131,137},{17,65},{40,68},{2,22},{113,126},{58,146},{34,131},{132,151},{147,153}};
    vector<int> ans = solve(v, b);
    
    for(int i=0;i<b.size();i++)
    {
        cout<<ans[i]<<" ";
        
    }
    cout<<endl;
    return 0;
}
