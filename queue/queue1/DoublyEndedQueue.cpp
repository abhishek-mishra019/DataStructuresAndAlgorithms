#include<iostream>
using namespace std;

class Deque{
    int size;
    int front;
    int rear;
    int *arr=NULL;
    public:
    Deque(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    };
    bool empty(){
        if(front==-1 && rear==-1) return true;
        else return false;
    }
    void push_back(int value){
        if(this->empty()){ //empty
            front++;
            rear++;
            arr[rear]=value;
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
    void push_front(int value){
        if(this->empty()){ //empty
            front++;
            rear++;
            arr[rear]=value;
        }
        else if((front==0 && rear==size-1)||(rear==front-1)){  //overflow
            cout<<"Overflow: queue is full"<<endl;
        }
        else if(rear<size-1 && front==0){  //circular nature
            front=size-1;
            arr[front]=value;
        } 
        else{  //normal case
            front--;
            arr[front]=value;
        }
    }
    void pop_front(){
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
    void pop_back(){
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
        else if(rear==0){ //circular nature
            arr[rear]=-1;
            rear=size-1;
        }
        else{ //normal case
            arr[rear]=-1;
            rear--;
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
    Deque dq(5);
    dq.push_front(10);
    dq.print();
    dq.push_front(20);
    dq.print();
    dq.push_back(30);
    dq.print();
    dq.push_back(40);
    dq.print();
    dq.push_front(50);
    dq.print();
    dq.push_front(60);
    dq.print();
    dq.pop_front();
    dq.print();
    dq.pop_front();
    dq.print();
    dq.pop_front();
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_front();
    dq.print();
    dq.pop_back();
    return 0;
}