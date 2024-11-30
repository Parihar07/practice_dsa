//
//  main.cpp
//  sorting_largetNumber
//
//  Created by CodeBreaker on 28/11/24.
//

/*Largest Number
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array A of non-negative integers, arrange them such that they form the largest number.
 Note: The result may be very large, so you need to return a string instead of an integer.


 Problem Constraints
 1 <= len(A) <= 100000
 0 <= A[i] <= 2*109


 Input Format
 The first argument is an array of integers.


 Output Format
 Return a string representing the largest number.


 Example Input
 Input 1:
  A = [3, 30, 34, 5, 9]
 Input 2:
  A = [2, 3, 9, 0]


 Example Output
 Output 1:
  "9534330"
 Output 2:
  "9320"


 Example Explanation
 Explanation 1:
 Reorder the numbers to [9, 5, 34, 3, 30] to form the largest number.
 Explanation 2:
 Reorder the numbers to [9, 3, 2, 0] to form the largest number 9320.


 Expected Output
 Provide sample input and click run to see the correct output for the provided input. Use this to improve your problem understanding and test edge cases
 */

#include <iostream>
#include<vector>
using namespace std;

bool compare(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    
    return ab.compare(ba) < 0;
}


int comparator(int a, int b)
{
    int t1=0,t2=0,s1=-1,s2=-1,tens=1;
    int n1=a, n2=b;
    if(n1==n2) return n1<n2;
    while(n1)
    {
        t1=n1;
        n1/=10;
        if(n1>0)
        {
            s1+=(tens*t1%10);
        }
        tens*=10;
    }
    tens=1;
    while(n2)
    {
        t2=n2;
        n2/=10;
        if(n2>0)
        {
            s2+=(tens*t2%10);
        }
        tens*=10;
    }
    if(t1!=t2 && (s1!=-1 || s2!=-1))
    {
        return t1<t2;
    } else {
        return comparator(s1, s2);
    }
}
string largestNumber(vector<int> &A) {
    string ans;
    size_t N= A.size();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            if(compare(A[j], A[j+1]))
            {
                swap(A[j],A[j+1]);
            }
        }
    }
    
    for(int i=0;i<N;i++)
    {
        ans+=(to_string(A[i]));
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Largest Number!\n";
    cout<<"--------------------\n";
    vector<int> A = {9,99,999,9999,9998};
    cout<<"Comparater : "<<compare(9, 98)<<endl;
    string ans = largestNumber(A);
    cout<<"Largest Number : "<<ans<<endl;
    
    return 0;
}
