 #include<iostream>
 #include <string>
 using namespace std;

class Vehicle{
    protected:

    string name;
    string model;
    int numberOfTyres;

    public:
    Vehicle(string name, string model, int numberOfTyres){  ///constructor
        cout<<"Vehicle ctor reached"<<endl;
        this->name=name;
        this->model=model;
        this->numberOfTyres=numberOfTyres;
    }
    string getName(){
        return name;
    }
    void startEngine(){
        cout<<"Engine is starting "<<this->name<<" "<<this->model<<endl;
    }
        void stopEngine(){
        cout<<"Engine is stopping "<<this->name<<" "<<this->model<<endl;
    }
    ~Vehicle(){
        cout<<"Vehicle dtor reached"<<endl;
    }
};
class Car: public Vehicle{
    protected:
    int numberOfDoors;
    string transmissionType;

    public:
    //constructor
    Car(string name, string model, int numberOfTyres, int numberOfDoors, 
    string transmissionType): Vehicle(name, model, numberOfTyres){  ///initialising the vehicle class
        cout<<"Car ctor reached"<<endl;
        this->numberOfDoors=numberOfDoors;
        this->transmissionType=transmissionType;
    }

    void startAC(){
        cout<<"Ac has started of "<<getName()<<endl;
    }
    ~Car(){
        cout<<"Car dtor reached"<<endl;
    }
};

class Motorcycle: public Vehicle{
    protected:
    string handleBarStyle;
    string suspensionType;
    
    public:
    //constructor
    Motorcycle(string name, string model, int numberOfTyres, string handleBarStyle,
    string suspensionType): Vehicle(name, model, numberOfTyres){ //initialising the vehicle class
        cout<<"Motorcycle ctor reached"<<endl;
        this->handleBarStyle=handleBarStyle;
        this->suspensionType=suspensionType;
    }
    void wheelie(){
        cout<<"Wheelie on "<<getName()<<endl;
    }

    ~Motorcycle(){
        cout<<"Motorcycle dtor reached"<<endl;
    }
     
};

 int main(){
    Car A("Maruti 800", "LXI", 4, 4, "Manual");
    A.startEngine();
    A.startAC();
    A.stopEngine();

    Motorcycle M("BMW", "VXI", 2,"U", "Hard");
    M.startEngine();
    M.wheelie();
    M.stopEngine();
    return 0;
 }