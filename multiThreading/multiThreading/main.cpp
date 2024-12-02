//
//  main.cpp
//  multiThreading
//
//  Created by CodeBreaker on 29/11/24.
//

#include <iostream>
#include<thread>

using namespace std;


int foo()
{
    cout<<"hello form foo()\n";
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Multithreading!\n";
    thread t1(foo);
    thread t2([](){
        cout<<"Hello from lambda function\n";
    });
    t1.join();
    t2.join();
    
    return 0;
}
