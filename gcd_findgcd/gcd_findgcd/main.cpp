//
//  main.cpp
//  gcd_findgcd
//
//  Created by CodeBreaker on 03/01/25.
//

#include <iostream>
using namespace std;

int gcd(int A, int B) {
    int a = A, b = B;
    while(b!=0)
    {
        int t=a;
        a=b;b=t%b;
    }
    return a;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<"GCD : "<<gcd(18,4)<<endl;
    return 0;
}
