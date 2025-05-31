//
//  main.cpp
//  lambdaa
//
//  Created by CodeBreaker on 31/05/25.
//

#include <iostream>
using namespace std;

//Function pointer appraoch
int isEven(int n)
{
    return n%2==0;
}

//Functor approach or function object
struct isEvenFunctor{
    bool operator()(int n)
    {
        return n%2==0;
    }
};

void take_func_ptr(void (*func)(int)) {
    func(100);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    std::cout << "Hello, Lambda Understanding!\n";
    
    vector<int> numbers{1,2,3,4,5,6,7,8};
    //auto it = find_if(numbers.begin(), numbers.end(), isEven); //Function pointer
    //auto it = find_if(numbers.begin(), numbers.end(), isEvenFunctor()); //FUnctor
    //Lambda
    auto it = find_if(numbers.begin(), numbers.end(), [](int n)->bool{
        return n%2==0;
    });
    cout<<"first even number : "<<*it<<endl;
    
    //printing something
    for_each(numbers.begin(), numbers.end(), [](int n){
        cout<<n<<" "<<endl;
    });
    
    
    take_func_ptr([](int x) { std::cout << "Stateless lambda called with: " << x << std::endl; });
    return 0;
}
