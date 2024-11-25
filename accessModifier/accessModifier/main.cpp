//
//  main.cpp
//  accessModifier
//
//  Created by CodeBreaker on 21/11/24.
//

#include <iostream>
using namespace std;

class A{
private:
    int pri_a;
protected:
    int pro_p;
public:
    void set_a(int x);
    void set_p(int p);
};

class B : public A
{
private:
    int pri_b;
protected:
    int pro_bp;
public:
    void set_b(int x);
    void set_bp(int p);
};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, Access Modifier..!\n";
    return 0;
}
