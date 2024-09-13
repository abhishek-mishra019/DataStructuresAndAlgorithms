#include<iostream>
// #include<bits/stdc++.h>
#include <string>
using namespace std;

//lifecycle of an object
// 1. constructor is called.
// 2. attributes and behaviours are accessed/
// 3. destructor is called


class Student{
    public: 
    //attributes
    int id;
    int age;
    string name;
    int nos;
    float *gpa;  //dynamic allocation

    // Student(){//default ctor
    //     cout<<this-.name <<" default ctor called"<<endl;
    // } 

    Student(int id, int age, string name, int nos, float gpa){
        this->id=id;
        this->age=age;
        this->name=name;
        this->nos=nos;
        this->gpa=new float(gpa);
        cout<<this->name<<" parametrised ctor called"<<endl;
    }

    Student(const Student &srcObject){
        this->id=srcObject.id;
        this->age=srcObject.age;
        this->name=srcObject.name;
        this->nos=srcObject.nos;
        cout<<"student copy ctor called"<<endl;
    }


    //behavoiours
    void study(){
        cout<<this->name<< " is studying"<<endl;
    }
    void sleep(){
        cout<<this->name<<" is sleeping"<<endl;
    }
    void bunk(){
        cout<<this->name<<" is bunking"<<endl;
    }

    ~Student(){ //default dtor
        //delete the dynamic attributes
        delete this->gpa;
        cout<<this->name<<" default dtor called"<<endl;
    }  
};

int main(){
    //navive maethod to object instatiation
    // Student A;
    // A.id=1;
    // A.age=15;
    // A.name="Ranu";
    // A.nos=6;
    Student A(1,15,"rahul", 6,7);   //stack Allocation --> static

    A.study();

    // Student B;
    // B.id=2;
    // B.name="Rahul";
    // B.age=17;
    // B.nos=5;
    Student B(2,17,"ranu", 5,8);  //stack allocation --> static
    B.bunk();

    //copy constructor
    // Student C=A; or
    Student C(A);  //stack allocation --> static
    C.sleep();


    //dynamic allocation
    Student *D= new Student(4, 16, "Ronaldo", 4,9);
    D->study();   //in dynamic we use arrow instead if dot
    //destructor not automatically called;
    delete D;
    return 0;
}