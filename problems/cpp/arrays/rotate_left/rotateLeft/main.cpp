//
//  main.cpp
//  rotateLeft
//
//  Created by CodeBreaker on 06/08/1946 Saka.
//
/**
 Multiple left rotations of the array
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A and multiple values in B, which represents the number of times array A needs to be left rotated.
 Find the rotated array for each value and return the result in the from of a matrix where ith row represents the rotated array for the ith value in B.


 Problem Constraints
 1 <= length of both arrays <= 2000 -10^9 <= A[i] <= 10^9 0 <= B[i] <= 2000


 Input Format
 The first argument given is the integer array A.
 The second argument given is the integer array B.asd


 Output Format
 Return the resultant matrix.


 Example Input
 Input 1:
  
     A = [1, 2, 3, 4, 5]
     B = [2, 3]

 Input 2:
   
     A = [5, 17, 100, 11]
     B = [1]



 Example Output
 Output 1:
  
     [ [3, 4, 5, 1, 2]
      [4, 5, 1, 2, 3] ]


 Output 2:

     
     [ [17, 100, 11, 5] ]



 Example Explanation
 for input 1 -> B[0] = 2 which requires 2 times left rotations
 1: [2, 3, 4, 5, 1]
 2: [3, 4, 5, 1, 2]
 B[1] = 3 which requires 3 times left rotation
 1: [2, 3, 4, 5, 1]
 2: [3, 4, 5, 1, 2]
 2: [4, 5, 1, 2, 4]
 */
#include <iostream>
#include<vector>
using namespace std;

int reverseArray(vector<int> &arr, size_t s, size_t e)
{
    while(s<e)
    {
        size_t tmp=arr[s];
        arr[s]=arr[e];
        arr[e]=tmp;
        s++;e--;
    }
    return 0;
}

vector<vector<int> > solve(vector<int> &A, vector<int> &B) {
    size_t rB=B.size();
    vector<vector<int>> ans;
    ans.resize(rB);
    size_t N= A.size();
    vector<int> tA(A.size());
    for(size_t i=0;i<A.size();i++)
    {
        tA[i]=A[i];
    }
    
    for (size_t r=0; r<rB; r++) {
        int b = B[r]%tA.size();
        reverseArray(tA, 0,N-1);
        reverseArray(tA, N-b,N-1);
        reverseArray(tA, 0, N-b-1);
        ans[r]=tA;
        for(size_t i=0;i<A.size();i++)
        {
            tA[i]=A[i];
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v{515,581,569,481,-439,733,-970,293,-264,144,-990,-263,-906,-544,103,-328,-186,908,-121,-272,0,989,515,-131,-371,-717,36,401,-932,-397,-66,626,-393,172,-137,-832,779,-895,345,-361,905,-280,0,-269,-743,-697,648,133,510,902,-150,-312,727,407,-82,-866,-940,764,-747,-569,510,-532,-24,225,658,708,-752,-709,-900,-546,442,953,469,-368,336,407,373,62,-62,-345,411,320,-842,-692,-567,-128,-401,917,-306,-116,-992,678,185,-52,-440,-621,-468,-334,85,-733,-882,-528,-424,141,-216,393,-102,459,391,533,-549,464,-157,990,759,-571,-289,-345,-571,18,538,-143,-260,-594,-913,186,-779,-604,355,4,-949,-9,964,115,816,-889,-247,-148,-781,-981,794,465,762,-182,-122,90,-3,-55,-416,-181,64,972,447,-583,420,-788,450,-886,371,-335,107,527,-89,610,-280,-715,-391,-143,-947,189,868,54,-362,865,735,727,185,-230,-383,822,176,-853,-235,-623,-397,-937,-816,-339,36,-987,-247,-383,-265,758,-234,794,-656,9,-138,-956};
    vector<int> B{103,84,67,24,451,57,41,97,67,68,158,470,396,182,186,125,202,369,361,484,142,346,48,188,326,206,130,19,32,378,26,279,84,104,124,123,428,69,192,227,132,133,143,3,38,222,204,101,352,417,254,463,355,2,198,334,432,411,334,340,364,397,203,41,278,25,403,213,302,204,268,84,332,348,247,248,350,68,106,88,32,302,443,221,307,257,189,235,231,228,37,314,376,449,347,271,44,489,233,484};
    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    vector<vector<int>> rt = solve(v, B);
    cout<<endl;
    for(int r=0;r<B.size();r++)
    {
        for(int c=0;c<v.size();c++)
        {
            cout<<rt[r][c]<<" ";
        }
        cout<<endl;
    }
   
    std::cout << "\nRotateArray\n";
    return 0;
}
