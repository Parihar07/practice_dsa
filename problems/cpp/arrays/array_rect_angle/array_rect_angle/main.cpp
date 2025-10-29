//
//  main.cpp
//  array_rect_angle
//
//  Created by CodeBreaker on 24/08/1946 Saka.
//
/*
 Rectangle Area
Solved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
Eight integers A, B, C, D, E, F, G, and H represent two rectangles in a 2D plane.

For the First rectangle,
Bottom left corner is (A, B)
Top right corner is (C, D)
For the Second rectangle,
Bottom left corner is (E, F)
Top right corner is (G, H).
Find and return the overlapping area of the two rectangles.


Problem Constraints
-104 <= A <= C <= 104
-104 <= B <= D <= 104
-104 <= E <= G <= 104
-104 <= F <= H <= 104


Input Format
The eight arguments given are the integers A, B, C, D, E, F, G and H.


Output Format
Return the overlapping area of the two rectangles.


Example Input
Input 1:
 A = 0   B = 0
 C = 4   D = 4
 E = 2   F = 2
 G = 6   H = 6
Input 2:
 A = 0   B = 0
 C = 4   D = 4
 E = 2   F = 2
 G = 3   H = 3


Example Output
Output 1:
 4
Output 2:
 1


Example Explanation
Explanation 1:
Rectangle with bottom left (2, 2) and top right (4, 4) is overlapping.
Explanation 2:
Rectangle with bottom left (2, 2) and top right (3, 3) is overlapping.
 */
#include <iostream>
using namespace std;
int solve(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area=0;
    int x1=0,x2=0,y1=0,y2=0;
    if((E>C) || (F>D)) return 0;
    x1=max(A,E);
    y1=max(B,F);
    x2=min(C,G);
    y2=min(D,H);
    area=(x2-x1)*(y2-y1);
    return area;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Area of rectangle!\n";
    int A=0,B=0,C=4,D=4,E=2,F=2,G=6,H=6;
    cout<<"Area of tectangle : "<<solve(A, B, C, D, E, F, G, H)<<endl;
    return 0;
}
