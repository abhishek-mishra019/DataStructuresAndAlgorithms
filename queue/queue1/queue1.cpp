#include<iostream>
// #include<deque>
#include <queue>
using namespace std;

class Queue{
    int queueSize;
    int front;
    int rear;
    int *arr=NULL;
    public:
    Queue(int size){
        this->queueSize=size;
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
        }
        else if(rear==queueSize-1){ //overflow
            cout<<"Overflow: queue is full"<<endl;
        }
        else{ //normal case
            rear++;
            arr[rear]=value;
        }
    }
    void pop(){
        if(this->empty()){ //underflow
            cout<<"Underflow: cannot Pop empty queue"<<endl;
            return;
        }
        else if(front==rear){ //single element
            arr[rear]=-1;
            front=-1;
            rear=-1;
            return;
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
            cout<<"Empty Stack ";
            return -1;
        }
        else return this->arr[rear];
    }
    int size(){
        if(this->empty()) return 0;
        else return rear-front+1;
    }
};


class Deque{
    int* arr;
    int front;
    int rear;
    int size;

    public:
    Deque(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    bool empty(){
        if(front==-1 && rear==-1) return true;
        else return false;
    }
    void push_front(int value){
        if(this->empty()){ //empty
            front++;
            rear++;
            arr[rear]=value;
        }
        else if(rear==size-1){ //full
            cout<<"Overflow: Deque is full"<<endl;
        }
        else{ //normal case 
            // O(n) complexity: we better use cicular array
            int j=rear;
            while(j>=front){
                arr[j+1]=arr[j];
                j--;
            }
            rear++;
            arr[front]=value;
        }

    }
    void push_back(int value){
        if(this->empty()){ //empty
            front++;
            rear++;
            arr[rear]=value;
        }
        else if(rear==size-1){ //full
            cout<<"Overflow: Deque is full"<<endl;
        }
        else{ //normal case
            rear++;
            arr[rear]=value;
        }
    }

    void pop_front(){
        if(this->empty()){ //empty
            cout<<"Underflow: cannot Pop empty queue"<<endl;
            return;
        }
        else if(front==rear){ //single element
            arr[rear]=-1;
            front=-1;
            rear=-1;
            return;
        }
        else{ //normal case
            arr[front]=-1;
            front++;
        }
    }
    void pop_back(){
        if(this->empty()){ //empty
            cout<<"Underflow: cannot Pop empty queue"<<endl;
            return;
        }
        else if(front==rear){ //single element
            arr[rear]=-1;
            front=-1;
            rear=-1;
            return;
        }
        else{ //normal case
            arr[rear]=-1;
            rear--;
        }
    }
    void print(){
        for(int i=0; i<this->size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};  


int main(){
    // deque<int> dq;
    // dq.push_front(10);
    // cout<<dq.front()<<endl;
    // dq.push_front(20);
    // cout<<dq.front()<<endl;
    // dq.push_back(30);
    // cout<<dq.back()<<endl;


    // Queue q(10);
    // q.pop();
    // q.push(5);
    // q.push(10);
    // q.push(15);
    // q.push(25);
    // q.push(35);
    // q.push(45);
    // q.push(55);
    // q.push(65);
    // q.push(75);
    // q.push(85);
    // cout<<q.getBack()<<endl;
    // q.push(95 );

    // cout<<q.size()<<endl;

    Deque deq(5);
    deq.push_front(10);
    deq.print();
    deq.push_front(15);
    deq.print();
    deq.push_back(35);
    deq.print();
    deq.push_front(100);
    deq.print();
    deq.push_front(90);
    deq.print();
    deq.push_front(110);
    deq.print();
    deq.pop_back();
    deq.print();
    deq.pop_front();
    deq.print();
    deq.pop_front();
    deq.print();
    deq.pop_back();
    deq.print();
    deq.pop_front();
    deq.print();

       deq.pop_back();
    deq.print();
    deq.pop_front();
    deq.print();
    return 0;
}
