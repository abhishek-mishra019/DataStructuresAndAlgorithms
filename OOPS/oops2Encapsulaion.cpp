#include<iostream>
#include<string>
using namespace std;
//access modifiers: public, private, protected

//rule: constructors and destructors are always public 
class Student{
    public: 
    //attributes
    int id;
    int age;
    string name;
    int nos;

    private: 
    float *gpa;  //dynamic allocation
    string gf;

    public: 
    Student(){//default ctor
        cout<<this->name <<" default ctor called"<<endl;
    } 
    Student(int id, int age, string name, int nos, float gpa, string gf){
        this->id=id;
        this->age=age;
        this->name=name;
        this->nos=nos;
        this->gpa=new float(gpa);
        this->gf=gf;
        cout<<this->name<<" parametrised ctor called"<<endl;
    }

    Student(const Student &srcObject){
        this->id=srcObject.id;
        this->age=srcObject.age;
        this->name=srcObject.name;
        this->nos=srcObject.nos;
        this->gpa=srcObject.gpa;
        this->gf=srcObject.gf;
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

    private:
    void chatting(){
        cout<<this->name<<" is chatting with gf"<<endl; 
    }  
}; 


//perfect encapsulation

class perfEncapsulatedStudent {
    private:
    int id;
    int age;
    string name;
    int nos;
    float *gpa;
    string gf;

    public:
    perfEncapsulatedStudent(){//default ctor
        cout<<this->name <<" default ctor called"<<endl;
    } 
    perfEncapsulatedStudent(int id, int age, string name, int nos, float gpa, string gf){
        this->id=id;
        this->age=age;
        this->name=name;
        this->nos=nos;
        this->gpa=new float(gpa);
        this->gf=gf;
        cout<<this->name<<" parametrised ctor called"<<endl;
    }

    //cannot use copy constructor in perfect encapsulation
    // perfEncapsulatedStudent(const perfEncapsulatedStudent &srcObject){
    //     this->id=srcObject.id;
    //     this->age=srcObject.age;
    //     this->name=srcObject.name;
    //     this->nos=srcObject.nos;
    //     this->gpa=srcObject.gpa;
    //     this->gf=srcObject.gf;
    //     cout<<"student copy ctor called"<<endl;
    // }

    //getter methods: 
    // we can add another security layer to verify access is authorised or not.
    int getAge(){
        return this->age;
    }
    int getID(){
        return this->id;
    }
    string getName(){
        return this->name;
    }
    int getNOS(){
        return this->nos;
    }
    float getGPA() const { 
        return *this->gpa;
    }
    string getGF(){
        return this->gf;
    }

    //setter methods
    void setID(int id){
        this->id=id;
    }
    void setGPA(float gpa){
        this->gpa= new float(gpa);
    }
    void setAge(int age){
        this->age=age;
    }
    void setName(string name){
        this->name=name;
    }
    void setNOS(int nos){
        this->nos=nos;
    }
    void setGF(string gf){
        this->gf=gf;
    } 
    ~perfEncapsulatedStudent(){ //default dtor
        //delete the dynamic attributes
        delete this->gpa;
        cout<<this->name<<" default dtor called"<<endl;
    } 

    private:
    void chatting(){
        cout<<this->name<<" is chatting with gf"<<endl;
    }
};
int main(){
    // Student A(1,15,"Akshat", 6,8,"shristi");
    // A.chatting(); //will give error as chatting is a private method
    // cout<<A.age<<endl;
    // cout<<A.gf<<endl;  // will give error as gf is a private attribute

    // A.sleep();  //main function does not know the implementation behind A.sleep

    perfEncapsulatedStudent B(1,15,"Akshat", 6,8,"shristi");
    B.setGPA(7);
    cout<<B.getGPA()<<endl;
    
    return 0;
}