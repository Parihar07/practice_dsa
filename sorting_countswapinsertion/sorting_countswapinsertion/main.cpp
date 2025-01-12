//
//  main.cpp
//  sorting_countswapinsertion
//
//  Created by CodeBreaker on 10/01/25.
//
/*
 Count swaps in InsertionSort - II
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer array A of size N, sort the elements in increasing order using Insertion Sort.
 You are asked to return the total number of shifts/swaps done.


 Problem Constraints
 1 <= N <= 103
 1 <= A[i] <= 109


 Input Format
 First and only argument is an integer array A.


 Output Format
 Return an integer denoting the number of swaps.


 Example Input
 Input 1:
  A = [5, 3, 1, 9, 4]
 Input 2:
  A = [2, 10, 4, 11]


 Example Output
 Output 1:
  5
 Output 2:
  1


 Example Explanation
 Explanation 1:
  Array will be sorted in 5 Swaps.
 Explanation 2:
  Only 1 swap is required.
 */
#include <iostream>
#include<vector>
using namespace std;

int solve(vector<int> &A) {
    size_t N = A.size();
    int sc=0;
    for(int i=1;i<N;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(A[j]<A[j-1])
            {
                sc++;
                int t=A[j];
                A[j]=A[j-1];
                A[j-1]=t;
            } else {
                break;
            }
        }
    }
    return sc;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, swap count using insertion sort!\n";
    vector<int> A{53897654,30317906,34596121,42180743,27822421,52168357,40551547,39270959,53584535,59806847,10552645,49965317,14541319,49948947,47944882,35708847,52016390,37759796,38470096,38829344,62247195,61550168,63973974,42450552,42312716,42793589,41061281,32018837,29717158,66555149,38784329,23943740,19821678,20727112,36445140,24980506,29473744,50860278,34905229,11250650,41184515,54303694,54483578,18740883,27893178,47111758,65001994,3993768,30017444,37212189,30273425,4227449,50995155,54242645,35826316,44272175,35095391,39093166,45396641,48208026,63786147,53109977,14359695,53450479,51826592,54850986,65000263,42213829,53329943,36769407,51072905,30896100,49063753,34182926,53476527,55651882,39738012,23637494,1200322,58827279,37117454,23426832,33693308,37945754,9927056,46582517,3401217,53866391,35893936,18688429,42592100,49879188,39762594,58215120,28405695,49491689,58602864,54132721,29262039,47013193,64904614,30425583,50455105,58592035,46066403,35801079,45595749,54497252,2432543,34193353,54018511,32700007,26980746,30458454,37364668,57193429,50884343,33601189,50055535,38775345,59213433};
    cout<<"swap count : "<<solve(A)<<endl;
    return 0;
}
