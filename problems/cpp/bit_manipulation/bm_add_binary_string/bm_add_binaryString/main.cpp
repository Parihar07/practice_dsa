//
//  main.cpp
//  bm_add_binaryString
//
//  Created by CodeBreaker on 24/08/1946 Saka.
//
/*
 Add Binary Strings
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given two binary strings A and B. Return their sum (also a binary string).


 Problem Constraints
 1 <= length of A <= 105
 1 <= length of B <= 105
 A and B are binary strings


 Input Format
 The two argument A and B are binary strings.


 Output Format
 Return a binary string denoting the sum of A and B


 Example Input
 Input 1:
 A = "100"
 B = "11"
 Input 2:
 A = "110"
 B = "10"


 Example Output
 Output 1:
 "111"
 Output 2:
 "1000"


 Example Explanation
 For Input 1:
 The sum of 100 and 11 is 111.
 For Input 2:
  
 The sum of 110 and 10 is 1000.
 */
#include <iostream>
#include<string>
using namespace std;

string addBinary(string A, string B) {
    size_t aN=A.length(),bN=B.length();
    size_t len=max(aN,bN);
    int i=aN-1, j=bN-1;
    string ans(len,'0');
    int carry=0;
    int k=len-1;
    while(len>0)
    {
        if(i>=0 && j>=0){
            if(A[i]=='1' && B[j]=='1')
            {
                if(carry==1)
                {
                    ans[k]='1';
                } else
                {
                    ans[k]='0';
                }
                carry=1;
                
            } else if((A[i]=='1' && B[j]=='0') ||(A[i]=='0' && B[j]=='1') )
            {
                if(carry==1)
                {
                    carry=1;
                    ans[k]='0';
                } else {
                    ans[k]='1';
                    carry=0;
                }
            } else {
                if(carry==1)
                {
                    ans[k]='1';
                } else {
                    ans[k]='0';
                }
                carry =0;
            }
            i--;j--;
        } else if(i>=0)  {
            if(A[i]=='1')
            {
                if(carry==1)
                {
                    carry=1;
                    ans[k]='0';
                } else {
                    ans[k]='1';
                    carry=0;
                }
            } else {
                if(carry==1)
                {
                    ans[k]='1';
                }
                carry=0;
            }
            
            i--;
        } else if(j>=0){
            if(B[j]=='1')
            {
                if(carry==1)
                {
                    carry=1;
                    ans[k]='0';
                } else {
                    ans[k]='1';
                    carry=0;
                }
            } else {
                if(carry==1)
                {
                    ans[k]='1';
                }
                carry=0;
            }
            j--;
        }
       
        len--;k--;
    }
        if(len==0)
        {
            if(carry==1)
            {   string t;
                t.push_back('1');
                t=t+ans;
                return t;
            }
        }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, add binary strings!\n";
    cout<<"--------------\n";
      string A="101";
    string B="11";
    cout<<"Ans = "<<addBinary(A, B)<<endl;
    return 0;
}
