//
//  main.cpp
//  recursion_towerofhanoi
//
//  Created by CodeBreaker on 06/01/25.
//

/*
 Tower of Hanoi
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
In the classic problem of the Towers of Hanoi, you have 3 towers numbered from 1 to 3 (left to right) and A disks numbered from 1 to A (top to bottom) of different sizes which can slide onto any tower.
The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one).
You have the following constraints:
Only one disk can be moved at a time.
A disk is slid off the top of one tower onto another tower.
A disk cannot be placed on top of a smaller disk.
You have to find the solution to the Tower of Hanoi problem.
You have to return a 2D array of dimensions M x 3, where M is the minimum number of moves needed to solve the problem.
In each row, there should be 3 integers (disk, start, end), where:
disk - number of the disk being moved
start - number of the tower from which the disk is being moved
end - number of the tower to which the disk is being moved


Problem Constraints
1 <= A <= 18


Input Format
The first argument is the integer A.


Output Format
Return a 2D array with dimensions M x 3 as mentioned above in the description.


Example Input
Input 1:
A = 2
Input 2:
A = 3


Example Output
Output 1:
[1 1 2 ] [2 1 3 ] [1 2 3 ]
Output 2:
[1 1 3 ] [2 1 2 ] [1 3 2 ] [3 1 3 ] [1 2 1 ] [2 2 3 ] [1 1 3 ]


Example Explanation
Explanation 1:
We shift the first disk to the middle tower.
We shift the second disk to the last tower.
We, finally, shift the first disk from the middle tower to the last tower.
Explanation 2:
We can see that this was the only unique path with minimal moves to move all disks from the first to the third tower.
 */
#include <iostream>
#include<vector>
using namespace std;

void TOH(vector<vector<int>> &V, int n, int S, int T, int D)
{
    if(n==0) return;
    TOH(V,n-1,S,D,T);
    vector<int> t{n,S,D};
    V.push_back(t);
    TOH(V,n-1,T,S,D);
}
vector<vector<int>> towerOfHanoi(int A) {
    vector<vector<int>> ans;
    TOH(ans,A,1,2,3);
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Tower of hanoi!\n";
    vector<vector<int>> ans = towerOfHanoi(3);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
