//
//  main.cpp
//  string_getprefix
//
//  Created by CodeBreaker on 03/02/25.
///*
//

/*
 get shortest prefix
 */

#include <iostream>
#include <string>
using namespace std;
string getPrefix(string s1, string s2)
{
    auto l1 = s1.length(), l2 = s2.length();
    int i=0;
    while(i<l1 && i<l2)
    {
        if(s1[i]!=s2[i]) break;
        i++;
    }
    return i==0?s1.substr(0,1):s1.substr(0,i);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Get prefix!\n";
    
    cout<<"Prefix : "<<getPrefix("eleph", "elephant")<<endl;
    return 0;
}
