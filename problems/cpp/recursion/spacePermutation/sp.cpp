#include <cassert>
/*
Space Insertion Permutations
===========================
Given a string of length N, print all possible strings that can be formed by inserting zero or more spaces between its characters.

For example, for input "abc", the output should be:
abc
a bc
ab c
a b c

Each character must remain in order, and spaces can be inserted between any two characters (or not at all).

Time Complexity: O(2^(N-1)), since there are N-1 places to insert or not insert a space.
Space Complexity: O(N) per call (due to string copies and recursion stack).
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void spacePermutation(string ip, int ind)
{
    if (ind == static_cast<int>(ip.size()) - 1)
    {
        cout << ip << "\n";
        return;
    }

    ip.insert(ind + 1, " ");
    spacePermutation(ip, ind + 2);
    ip.erase(ind + 1, 1);
    spacePermutation(ip, ind + 1);
}

int main()
{
    cout << "Hello space permutation.\n";
    string ip = "abc";
    cout << "input : " << ip << endl;
    spacePermutation(ip, 0);
    cout << "input : " << ip << endl;

    return 0;
}