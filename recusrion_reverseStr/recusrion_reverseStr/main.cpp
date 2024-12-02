//
//  main.cpp
//  recusrion_reverseStr
//
//  Created by CodeBreaker on 30/11/24.
//

#include <iostream>
#include<string>
using namespace std;
void charStr(const char *s)
{
    if(*s=='\0') return;
    charStr(s+1);
    cout<<*s;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Revesring string!\n";
    string s;
    cin>>s;
    charStr(s.c_str());
    cout<<endl;
    return 0;
}
