#include<iostream>

using namespace std;

class Shape{
    public: 
    virtual void draw(){
        cout<<"Generic Shape Drawing"<<endl;
    }

    //virtual keyword is used whenever we are doing upcasting or downcasting
    //to tell the compiler that we will decide call this function on runtime
    //whether to call it from parent class or child class
};
class Circle: public Shape{
    public: 
    void draw() override{
        cout<<"Circle Drawing"<<endl;
    }
    //override keyword is used to tell the reader that this function might be
    //overriding a parent function
};
class Rectangle: public Shape{
    public: 
    void draw() override{
        cout<<"Rectangle Drawing"<<endl;
    }
    //override keyword is used to tell the reader that this function might be
    //overriding a parent function
};

void drawShape(Shape *s){
    s->draw();
}

int main(){
    Shape S;
    S.draw();

    Circle C;
    C.draw(); //method overriding

    Rectangle R;
    R.draw(); //method overriding 

    Shape *s= &C;  //upcasting: parent class holding object of child class

    drawShape(s); //without virtual keyword: prints the function of class holding the object.(shape here)
    //with virtual keyword: prints Actual object 


    //no casting
    Shape *s1= new Shape();
    s1->draw();
    
    //Upcasting: parent class holding object of child class
    Shape *s2= new Circle();
    s2->draw();  //without virtual keyword: prints the function of class holding the object i.e class on Left of =sign (shape here)
    //with virtual keyword: prints Actual object 


    //Downcasting: child class holding object of parent class
    Shape *s3=new Shape();
    Circle *c2= (Circle *) s3;  //downcasting;
     //without virtual keyword: calls the function of class holding the object i.e class on Left of =sign (shape here)
    //with virtual keyword: calls Actual object function 
    c2->draw();
    return 0;
}
