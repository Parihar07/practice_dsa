//
//  main.cpp
//  oops_inheritance
//
//  Created by CodeBreaker on 15/03/25.
//

#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle{
    private:
    int height, width;
    public:
    void setHieght(int h){
        height = h;
    }
    void setWidth(int w){
        width=w;
    }
    void display(){
        cout<<width<<" "<<height<<endl;
    }
};

class RectangleArea : public Rectangle{
    private:
    int h,w;
    public:
    void read_input()
    {
        cin>>h>>w;
        setHieght(h); setWidth(w);
    }
    void display() {
        cout<<h*w<<endl;
    }
};

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}
