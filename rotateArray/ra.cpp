/*
Problem Description
Given an integer array A of size N and an integer B, you have to print the same array after rotating it B times towards the right.


Problem Constraints
1 <= N <= 106
1 <= A[i] <=108
1 <= B <= 109


Input Format
There are 2 lines in the input

Line 1: The first number is the size N of the array A. Then N numbers follow which indicate the elements in the array A.

Line 2: A single integer B.


Output Format
Print array A after rotating it B times towards the right.


Example Input
Input 1 :
4 1 2 3 4
2


Example Output
Output 1 :
3 4 1 2


Example Explanation
Example 1 :

N = 4, A = [1, 2, 3, 4] and B = 2.

Rotate towards the right 2 times - [1, 2, 3, 4] => [4, 1, 2, 3] => [3, 4, 1, 2]

Final array = [3, 4, 1, 2]
*/

#include<iostream>
using namespace std;

void revArray(int ar[], int s, int e)
{
    if(s>e || ar==NULL) return;
    int i=s, j=e;
    while(i<j)
    {
        int tmp = ar[i];
        ar[i]=ar[j];
        ar[j]=tmp;

        i++;j--;
    }
    return;
}
int main()
{
    int sz=0;
    cin>>sz;
    int* ar;
    ar = new int[sz];
    // int ar[]={2,3,5,6,7,8,9};
    // int sz = sizeof(ar)/sizeof(ar[0]);
    for(int i=0;i<sz;i++)
    {
        cin>>ar[i];
    }
    int B=0;
    cin>>B;
    if(B>sz)
    {
        B = B%sz;
    }
    revArray(ar,0,sz-1);
    revArray(ar,0,B-1);
    revArray(ar,B, sz-1);

    for(int i=0;i<sz;i++)
    {
        cout<<ar[i]<<" ";
    }

    cout<<endl;
    return 0;
}