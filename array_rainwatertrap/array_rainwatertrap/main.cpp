//
//  main.cpp
//  array_rainwatertrap
//
//  Created by CodeBreaker on 15/12/24.
//
/*
 Rain Water Trapped
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Imagine a histogram where the bars' heights are given by the array A. Each bar is of uniform width, which is 1 unit. When it rains, water will accumulate in the valleys between the bars.

 Your task is to calculate the total amount of water that can be trapped in these valleys.

 Example:

 The Array A = [5, 4, 1, 4, 3, 2, 7] is visualized as below. The total amount of rain water trapped in A is 11.


 Rain Water Trapped



 Problem Constraints
 1 <= |A| <= 105
 0 <= A[i] <= 105


 Input Format
 First and only argument is the Integer Array, A.


 Output Format
 Return an Integer, denoting the total amount of water that can be trapped in these valleys


 Example Input
 Input 1:
  A = [0, 1, 0, 2]
 Input 2:
 A = [1, 2]


 Example Output
 Output 1:
 1
 Output 2:
 0


 Example Explanation
 Explanation 1:
 1 unit is trapped on top of the 3rd element.
 Rain Water Histogram
 Explanation 2:
 No water is trapped.
 */
#include <iostream>
#include<vector>
using namespace std;

int trap(const vector<int> &A) {
    int sum=0;
    size_t N=A.size();
    vector<int> PMA(N,0);
    PMA[0]=A[0];
    vector<int> SMA(N,0);
    SMA[N-1]=A[N-1];
    for(int i=1;i<N;i++)
    {
        PMA[i]=max(PMA[i-1],A[i]);
    }
    for(int j=N-2;j>=0;j--)
    {
        SMA[j]=max(SMA[j+1],A[j]);
    }
    
    for(int i=1;i<N-1;i++)
    {
        int LM = PMA[i];
        int RM = SMA[i];
        int t = min(RM,LM) - A[i];
        sum+=t>0?t:0;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Rain water harvesting!\n";
    vector<int> A{5, 4, 1, 4, 3, 2, 7};
    cout<<"Total rain water trapped : " << trap(A)<<endl;
    return 0;
}
