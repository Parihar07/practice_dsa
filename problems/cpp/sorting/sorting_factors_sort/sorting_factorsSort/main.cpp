//
//  main.cpp
//  sorting_factorsSort
//
//  Created by CodeBreaker on 25/11/24.
//
/*
 Factors sort
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an array A of N elements. Sort the given array in increasing order of number of distinct factors of each element, i.e., element having the least number of factors should be the first to be displayed and the number having highest number of factors should be the last one. If 2 elements have same number of factors, then number with less value should come first.

 Note: You cannot use any extra space


 Problem Constraints
 1 <= N <= 104
 1 <= A[i] <= 104


 Input Format
 First argument A is an array of integers.


 Output Format
 Return an array of integers.


 Example Input
 Input 1:
 A = [6, 8, 9]
 Input 2:
 A = [2, 4, 7]


 Example Output
 Output 1:
 [9, 6, 8]
 Output 2:
 [2, 7, 4]


 Example Explanation
 For Input 1:
 The number 9 has 3 factors, 6 has 4 factors and 8 has 4 factors.
 For Input 2:
 The number 2 has 2 factors, 7 has 2 factors and 4 has 3 factors.
 */
#include <iostream>
#include<vector>
using namespace std;
int facto(int x)
{
    int ans=0;
    for(int i=1;i*i<=x;i++)
    {
        if((x%i)==0)
        {
            if(x/i==i)
            {
                ans+=1;
            } else {
                ans+=2;
            }
        }
    }
    return ans;
}
int camp_factor(int a, int b)
{
    int f1 = facto(a);
    int f2 = facto(b);
    if(f1 != f2)
        return f1 > f2;
    return a > b;
    
}
int camp_factor(pair<int, int> a, pair<int, int> b)
{
    int f1 = a.second;
    int f2 = b.second;
    if(f1 != f2)
        return f1 > f2;
    return a > b;
    
}
/*
 
 this soultion basiclly we are collecting factors for each element in array like A[i+1] in bubble sort we compare adjacent elements in that way overall complexity goes to NxN.
 
 Need to find where we can store factor along with actual element that will deccrese the calling fctors functions.
 */
vector<int> solve(vector<int> &A)
{
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            int t=0;
            if(camp_factor(A[j], A[j+1]))
            {
                t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
    }
    return A;
}

vector<int> solveOpt(vector<int> &A) {
    size_t N = A.size();
    vector<pair<int, int>> factPairA(A.size());
    for(int i=0;i<N;i++)
    {
        factPairA[i]={A[i], facto(A[i])};
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            pair<int, int> t;
            if(camp_factor(factPairA[j], factPairA[j+1]))
            {
                t=factPairA[j];
                factPairA[j]=factPairA[j+1];
                factPairA[j+1]=t;
                //swap(factPairA[j], factPairA[j+1]); u can use this too;
            }
        }
    }
    for(int i = 0; i < N; i++) {
          A[i] = factPairA[i].first;
      }
    return A;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Factors Sort!\n";
    cout<<"---------------------\n";
    cout<<"Facto : "<<camp_factor(20, 18)<<endl;
    vector<int> A{888,417,136,979,360,711,569,649,693,763,586,259,715,892,366,309,170,72,992,483,245,5,421,66,466,368,109,774,716,89,630,154,68,749,857,699,68,539,467,69,531,888,46,364,700,827,181,44,470,145,859,819,245,618,957,737,232,394,435,447,729,209,291,117,824,939,646,242,936,145,369,799,593,583,142,660,156,84,776,866,482,229,722,848,838,809,241,559,342,830,173,910,158,251,829,422,268,148,616,998,949,770,284,760,135,608,722,506,685,359,992,95,927,882,470,60,71,99,354,851,124,100,348,187,467,775,378,237,193,903,685,785,378,261,362,463,389,420,59,95,510,628,99,89,315,611,118,494,632,663,366,389,555,965,183,294,328,262,12,99,182,908,167,98,15,370,693,661,956,649,784,281,911,740,379,962,504,61,154,654,841,245,383,278,194,888,102,552,493,758,442,127,866,204,989,57,637,353,860,896,531,433,209,314,753,86,240,625,365,66,506,732,435,205,653,764,241,813,121,872,627,313,396,385,992,534,344,503,587,298,976,298,715,540,222,593,675,290,40,879,426,560,718,137,573,360,414,537,944,413,801,238,33,831,779,66,781,890,454,258,753,502,871,602,810,952,776,847,197,600,349,946,616,554,823,612,655};
    vector<int> ans = solveOpt(A);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<< " ";
    }
    cout<<endl;
    return 0;
}
