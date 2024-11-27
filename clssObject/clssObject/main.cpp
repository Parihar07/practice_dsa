//
//  main.cpp
//  clssObject
//
//  Created by CodeBreaker on 27/11/24.
//

#include <iostream>
#include<string>
using namespace std;

class Student{
    string name;
    int age;
public:
    void stName(string n) { this->name = n;}
    void stAge(int a) { this->age=a;};
    void printDetails(){
        cout<<"Student Name: "<<name<<endl;
        cout<<"Student Age : "<<age<<endl;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...

    std::cout << "Hello, Class and objects!\n";
    Student *St = new Student();
    St->stName("codebreaker");
    St->stAge(37);
    St->printDetails();
    
    return 0;
}
