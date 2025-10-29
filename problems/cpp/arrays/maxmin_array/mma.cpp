/*
Q3. Max and Min of an Array
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
Take input an array A of size N and write a program to print maximum and minimum elements of the input. The only line of the input would contain a single integer N that represents the length of the array followed by the N elements of the input array A.

Problem constraints
1 <= N <= 1000

1 <= A <= 1000


Input Format
The first line contains a single integer N representing the length of the array A followed by N elements of the array A.


Output Format
A single line output containing two space-separated integers.
The first integer is the maximum value of the array.
The second integer is the minimum value of the array. 

There is **no space** after the minimum value in the output format. 
There is only a **single space** between the maximum and minimum value.


Example Input
Input 1:
5 1 2 3 4 5
Input 2:
4 10 50 40 80

Example Output
Output 1:
5 1
Output 2:
80 10
Note: There is no space after the minimum value in the output format.
There is only a single space between the maximum and minimum value.
*/

#include<iostream>
#include<vector>
using namespace std;
int maxi(int a, int b)
{
    return a>b ?a:b;
}
int mini(int a, int b)
{
    return a<b?a:b;
}
int main()
{
    int N=0;
    cin>>N;
    vector<int> A(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    int max=A[0], min=A[0];
    for(int i=0;i<N;i++)
    {
        max=maxi(max,A[i]);
        min=mini(min,A[i]);
    }
    cout<<max<<" "<<min<<endl;
    return 0;
}