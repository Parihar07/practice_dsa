//
//  main.cpp
//  PN_CntDivs
//
//  Created by CodeBreaker on 04/01/25.
//

/*
 Count of divisors
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A, find and return the count of divisors of each element of the array.
 NOTE: The order of the resultant array should be the same as the input array.


 Problem Constraints
 1 <= length of the array <= 100000
 1 <= A[i] <= 106


 Input Format
 The only argument given is the integer array A.


 Output Format
 Return the count of divisors of each element of the array in the form of an array.


 Example Input
 Input 1:
  A = [2, 3, 4, 5]
 Input 2:
  A = [8, 9, 10]


 Example Output
 Output 1:
  [2, 2, 3, 2]
 Output 1:
  [4, 3, 4]


 Example Explanation
 Explanation 1:
  The number of divisors of 2 : [1, 2], 3 : [1, 3], 4 : [1, 2, 4], 5 : [1, 5]
  So the count will be [2, 2, 3, 2].
 Explanation 2:
  The number of divisors of 8 : [1, 2, 4, 8], 9 : [1, 3, 9], 10 : [1, 2, 5, 10]
  So the count will be [4, 3, 4].
 */
#include <iostream>
#include<vector>
using namespace std;

int getDivCnt(int A)
{
    int ans=0;
    for(long i=1;i*i<=A;i++)
    {
        if(A%i==0){
            if(i*i==A)
            {
                ans+=1;
            } else {
                ans+=2;
            }
        }
    }
    return ans;
}

vector<int> solve(vector<int> &A) {
    size_t N = A.size();
    vector<int> ans(N);
    for(int i=0;i<N;i++)
    {
        ans[i]=getDivCnt(A[i]);
    }
    return ans;
}

vector<int> solveOpt(vector<int> &A) {
    size_t N = A.size();
    int mN = 0;
    vector<int> ans(N);
    for(int i=0;i<N;i++)
    {
        mN=max(mN,A[i]);
    }
    vector<int> mFact(mN,1);
    
    for(int i=2;i<mN;i++)
    {
        for(int j=i;j<mN;j+=i)
        {
            mFact[j]+=1;
        }
    }
    
    for(int i=0;i<N;i++)
    {
        ans[i]=mFact[A[i]];
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, count divisiors!\n";
    vector<int> A{2,4,6,8,12,10,3}/*{1238,1751,1391,1038,1605,609,1381,1551,1316,1838,959,1710,604,117,1011,171,76,668,1975,893,477,75,1413,1441,623,144,443,1048,1607,214,1502,1766,571,751,1227,1876,1280,1808,1392,891,1570,1996,1763,1908,1308,971,1504,1912,931,1123,358,1628,1873,158,1168,23,205,1553,1544,169,1682,508,469,1295,67,923,1461,124,1042,195,1549,1280,1361,1170,760,1509,955,466,92,1714,645,1559,983,415,1837,1515,226,130,1107,70,913,393,1960,862,564,1649,182,1064,1863,1102,213,1407,1606,749,1737,1633,1377,1277,299,807,1241,1307,1175,1557,1332,1529,1950,365,1560,1681,294,276,904,1045,1281,67,722,149,1275,797,1381,705,866,954,87,472,1636,938,302,1669,655,482,1347,1883,499,844,890,960,1320,1029,889,286,1045,164,1268,98,135,232,1103,1948,477,824,422,1313,2,298,867,1492,1371,1798,392,373,706,1960,1947,457,743,793,677,1582,15,1249,519,1230,1709,268,1315,967,724,1737,1548,1633,1061,1696,1621,209,239,1417,264,1954,632,479,67,352,1807,1890,1432,712,794,441,1267,818,994,10,1675,1949,941,1304,554,1795,1510,673,551,1326,308,1063,1125,498,986,1884,625,830,976,1679,1217,379,1795,1796,1260,361,1421,994,1317,807,540,1866,1348,1010,1449,298,1852,1250,281,798,714,1293,1881,1438,358,517,130,436,416,151,824,1913,1596,87,1295}*/;
    vector<int> ans = solve(A);
    for(int i=0;i<A.size();i++)
    {
        cout<<ans[i]<< " ";
    }
    cout<<endl;
    return 0;
}
