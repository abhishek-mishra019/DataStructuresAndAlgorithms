#include<iostream>
using namespace std;

class CircularQueue{
    int size;
    int front;
    int rear;
    int *arr=NULL;
    public:
    CircularQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    };
    bool empty(){
        if(front==-1 && rear==-1) return true;
        else return false;
    }
    void push(int value){
        if(this->empty()){ //empty
            front++;
            rear++;
            arr[rear]=value;
            cout<<"check"<<endl;
        }
        else if((front==0 && rear==size-1)||(rear==front-1)){  //overflow
            cout<<"Overflow: queue is full"<<endl;
        }
        else if(rear==size-1 && front!=0){  //circular nature
            rear=0;
            arr[rear]=value;
        } 
        else{  //normal case
            rear++;
            arr[rear]=value;
        }
    }
    void pop(){
        if(this->empty()){  //empty
            cout<<"Underflow: cannot Pop empty queue"<<endl;
            return;
        }
        else if(front==rear){ //single element
            arr[rear]=-1;
            front=-1;
            rear=-1;
            return;
        }
        else if(front==size-1 && rear!=0){ //circular nature
            arr[front]=-1;
            front=0;
        }
        else{ //normal case
            arr[front]=-1;
            front++;
        }
    }
    int getFront(){
        if(this->empty()) {
            cout<<"Empty Queue ";
            return -1;
        }
        else return this->arr[front];
    }
    int getBack(){
        if(this->empty()) {
            cout<<"Empty Queue ";
            return -1;
        }
        else return this->arr[rear];
    }
    int getSize(){
        if(this->empty()) return 0; //when empty
        else if(front<=rear){ //normal case
            return rear-front+1;
        }
        else{ //circular case
            return ((size-front)+(rear+1));
        }
    }
    void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    CircularQueue c(5);
    c.push(10);
    cout<<c.getSize()<<endl; 
    c.push(20);
    c.push(30);
    c.push(40);
    c.push(50);
    c.print();
    c.push(60);
    c.pop();
    c.pop();
    c.print();
    c.push(60);
    c.print();
    c.push(70);
    c.print(); 
    cout<<c.getSize()<<endl;
    cout<<c.getFront();
    return 0;
}
