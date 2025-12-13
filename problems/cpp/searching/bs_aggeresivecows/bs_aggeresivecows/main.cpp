//
//  main.cpp
//  bs_aggeresivecows
//
//  Created by CodeBreaker on 14/01/25.
//
/*
 Aggressive cows
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Farmer John has built a new long barn with N stalls. Given an array of integers A of size N where each element of the array represents the location of the stall and an integer B which represents the number of cows.
 His cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, John wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?


 Problem Constraints
 2 <= N <= 100000
 0 <= A[i] <= 109
 2 <= B <= N


 Input Format
 The first argument given is the integer array A.
 The second argument given is the integer B.


 Output Format
 Return the largest minimum distance possible among the cows.


 Example Input
 Input 1:
 A = [1, 2, 3, 4, 5]
 B = 3
 Input 2:
 A = [1, 2]
 B = 2


 Example Output
 Output 1:
  2
 Output 2:
  1


 Example Explanation
 Explanation 1:
  John can assign the stalls at location 1, 3 and 5 to the 3 cows respectively. So the minimum distance will be 2.
 Explanation 2:
  The minimum distance will be 1.
 */

#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<int> &A, int m, int B)
{
    int c=1,lp=A[0]; //lp last position where we placed the cow, and as in all the scenarions cow i placed at position 1 hence will start c=1
    for(int i=0;i<A.size();i++)
    {
        if((A[i]-lp)>=m)
        {
            lp = A[i];
            c+=1;
            if(c==B) return true;
        }
    }
    return false;
}

int solve(vector<int> &A, int B) {
    size_t N = A.size();
    sort(A.begin(), A.end());
    int l=A[1]-A[0],h=0,m=0,ans=0;
    for(int i=0;i<N-1;i++)
    {
        l=min(l,A[i+1]-A[i]);
    }
    h = A[N-1]-A[0];
    while(l<=h)
    {
        m=(l+h)/2;
        if(check(A, m, B)==true)
        {
            ans=m;
            l=m+1;
        } else {
            h=m-1;
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Aggressive Cows !\n";
    vector<int> A{6939,2057,3094,9698,6214,9667,8682,6309,928,1603,3194,6188,1170,923,7887,3932,9083,1924,2795,1686,3189,303,2254,1148,3312,7357,6162,8194,2923,4763,5314,5499,1271,4919,1067,9698,8553,8097,1883,3478,3542,1702,1872,9795,4593,8876,9385,4873,1747,3290,6890,9086,9782,4590,6903,9879,9490,4179,2588,8976,7187,4223,5784,6836,553,3685,9665,943,2222,3969,8065,953,1269,3293,8518,2915,6713,3349,1516,6851,6451,3950,4186,6825,9691,1418,2594,286,836,4261,3261,3971,8077,5323,1081,6916,429,3074,7832,7264,2915,5905,2719,8433,669,2423,3997,1971,9329,7601,8609,8946,828,9315,4980,9069,842,2360,2675,6945,6568,7320,1389,7780,1267,9794,983,699,5054,1474,3659,6423,9781,8294,9193,7450,9549,2426,4218,3161,7385,4354,6944,9244,2901,8350,9416,756,5405,9802,457,755,1838,5560,3746,1929,9178,9181,7151,6960,6477,1342,1417,4424,2615,2008,8543,995,1974,4946,2798,7389,1793,7131,243,5081,1721,5231,5777,3159,8234,8907,326,9823,4002,5947,4584,1060,5042,7445,9860,9781,6533,2109,1103,2320,1568,7620,1883,5632,5780,3461,6230,7700,4753,4094,7644,5788,497,3490,1282,1934,7819,2077,1345,2823,1375,4980,2051,1604,9482,6038,7226,2550,1218,5572,479,5516,9335,1104,5248,6113,2576,9313,1545,9210,7574,4387,4176,7933,2239,2668,5373,7687,9732,5922,3351,4871,4493,5973,7109,2969,9577,1498,6939,4454,7583,3801,9612,5576,5851,2065,6935,2507,264,228,6487,1535,1001,6966,3742,3066,7882,7464,5503,9020,2575,712,5570,5891,9871,8824,4944,1216,441,5537,483,9469,3112,9539,7917,4533,5496,4435,7368,9814,8041,1349,2166,3730,8035,1940,4595,7965,6930,9387,5433,8094,6429,2350,7709,1485,6264,2295,8888,5246,9291,7625,9878,7856,7611,9097,3697,1693,6786,9698,1441,79,3908,8752,8239,1713,9252,4414,7319,7377,586,903,6019,8688,3795,6827,3566,6304,3428,8786,6831,5478,2020,78,6889,161,7588,7762,6186,2941,4572,2596,3384,7024,4687,5476,560,8199,630,817,5304,9265,7389,2093,8507,6748,3047,7190,7136,9913,3375,1609,141,5033,2271,5654,4775,3702,3145,7692,85,2551,4737,9347,4104,3152,8527,50,1362,5132,3869,7750,7729,2549,1345,9795,316,3450,4378,3004,1204,5163,4141,4765,5076,3412,3008,7628,2505,1564,7356,8318,2610,7490,1396};
    cout<<"minimum distance john cows cane be palced : "<< solve(A, 385)<<endl;
    
    return 0;
}
