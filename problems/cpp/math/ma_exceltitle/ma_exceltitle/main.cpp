//
//  main.cpp
//  ma_exceltitle
//
//  Created by CodeBreaker on 27/08/1946 Saka.
//
/* Excel Column Number
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a column title as appears in an Excel sheet, return its corresponding column number.


 Problem Constraints
 1 <= length of the column title <= 5


 Input Format
 The only argument is a string that represents the column title in the excel sheet.


 Output Format
 Return a single integer that represents the corresponding column number.


 Example Input
 Input 1:
  AB
 Input 2:
  BB


 Example Output
 Output 1:
  28
 Output 2:
  54


 Example Explanation
 Explanation 1:
  A -> 1
  B -> 2
  C -> 3
  ...
  Z -> 26
  AA -> 27
  AB -> 28
 Explanation 2:
  A -> 1
  B -> 2
  C -> 3
  ...
  Z -> 26
  AA -> 27
  AB -> 28
  ...
  AZ -> 52
  BA -> 53
  BB -> 54
 */
#include <iostream>
#include<string>
using namespace std;

int power(int a, int e)
{
    int ans=1;
    if(e==0) return 1;
    for(int i=0;i<e;i++)
    {
        ans*=a;
    }
    return ans;
}

int titleToNumber(string A) {
    int ans=0;
    size_t N=A.length();
    int j=0;
    for(int i=N-1;i>=0;i--,j++)
    {
        cout<< "value : "<<((int)A[i]%65+1)<<endl;
        ans+=((int)A[i]%65+1) * power(26, j);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Excel title conversion!\n";
    cout<<"-----------------------\n";
    cout<<"Actual tital number : "<<titleToNumber("AB")<<endl;;
    return 0;
}
