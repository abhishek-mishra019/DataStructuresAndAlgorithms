#include<iostream>
using namespace std;

//Compile Time Polymorphism



//function overloading
class Add{
    public:
    int sum(int x, int y){
        cout<<"sum of two int: ";
        return x+y;
    }
    int sum(int x, int y, int z){
        cout<<"sum of three int: ";
        return x+y+z;
    }
    double sum(double x, double y){
        cout<<"sum of two doubles";
        return x+y;
    }
};
//operator overloading
class Complex{
    public:
    int real;
    int imag;

    Complex(){
        real=imag=-1;
    }
    Complex(int real, int imag){
        this->real=real;
        this->imag=imag;
    }
    //syntax for operator overloading
    // returnType operator <opSymbol> (arguments){
    //      operation
    //}
    Complex operator + (const Complex &B){
        Complex temp;
        temp.real= this->real +B.real;
        temp.imag= this->imag + B.imag;
        return temp;
    }
        Complex operator - (const Complex &B){
        Complex temp;
        temp.real= this->real -B.real;
        temp.imag= this->imag - B.imag;
        return temp;
    }
    bool operator == (const Complex &B){ 
        return (this->real==B.real) && (this->imag==B.imag);
    }

    void print(){
        printf("%d + i%d", this->real, this->imag);
        cout<<endl;
    }
};



int main(){
    //function overloading
    Add a;
    int x=5, y=6, z=7;
    cout<<a.sum(x,y)<<endl;  //sum of two int
    cout<<a.sum(x,y,z)<<endl;  //sum of three int
    // cout<<a.sum(x,y)<<endl;


    //operator overloading
    Complex A(2,5);
    Complex B(2,5);
    A.print();
    B.print();
    Complex C=A+B;  //hover over the + sign and 
                    // see it refers to the oparator overloading function
    C.print();
    Complex D=A-B;
    D.print();

    bool equalOrNot= A==B; //hover over the == sign and 
                    // see it refers to the oparator overloading function
    cout<<"is Equal: "<< equalOrNot<<endl;

    return 0;
}