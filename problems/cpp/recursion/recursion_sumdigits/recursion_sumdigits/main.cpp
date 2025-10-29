//
//  main.cpp
//  recursion_sumdigits
//
//  Created by CodeBreaker on 02/12/24.
//

#include <iostream>
using namespace std;

int solve(int A) {
    int ans=0;
    if(A==0) return 0;
    ans=A%10;
    ans+=solve(A/10);
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<"Sum digits using recusiorn "<<solve(34567)<<endl;
    return 0;
}
