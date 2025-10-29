//
//  main.cpp
//  cls
//
//  Created by CodeBreaker on 28/08/1946 Saka.
//

#include <iostream>
#include<string>
using namespace std;

class Student{
    int age;
    string name;
    string DOB;
public:
    void setAge(int a){
        age=a;
    }
    void setName(string str)
    {
        name= str;;
    }
    void print_details();
};

void Student::print_details()
{
    cout<<"Age: "<<age<<endl;
    cout<<"Name: "<<name<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, encapsulation world!\n";
    Student std;
    std.setAge(45);
    std.setName("Codebreaker");
    std.print_details();
    return 0;
}
