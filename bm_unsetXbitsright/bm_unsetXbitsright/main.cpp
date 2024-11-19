//
//  main.cpp
//  bm_unsetXbitsright
//
//  Created by CodeBreaker on 26/08/1946 Saka.
//

#include <iostream>
using namespace std;
long solve(long A, int B) {
    return A&(~1<<(B-1));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, unset x bits form right!\n";
    cout<<"------------------\n";
    cout<<"Unsetting x bits form right : "<< solve(25, 3)<<endl;
    return 0;
}
