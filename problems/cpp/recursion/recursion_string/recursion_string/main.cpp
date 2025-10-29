//
//  main.cpp
//  recursion_string
//
//  Created by CodeBreaker on 25/05/25.
//

#include <iostream>
#include <string>
using namespace std;

void helper(string str, int ind)
{
    if(str[ind]=='\0') return;
    helper(str, ind+1);
    cout<<str[ind];
}

void revString(string str)
{
    helper(str,0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, reversing string using recursion!\n";
    revString("hello world!"); cout<<endl;
    return 0;
}
