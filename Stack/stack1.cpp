// #include<iostream>
// using namespace std;


// //implementation of stack
// class Stack{
//     public:
//         int* arr;
//         int size;
//         int top;
  
//         Stack(int capacity){
//             size=capacity;
//             arr=new int(capacity);
//             top=-1;
//         }

//         void push(int value){
//             if(top == size-1){
//                 // stack is already full: insertion will cause stack overflow
//                 cout<<"Stack Overflow"<<endl;
//                 return;
//             }
//             else{
//                 //normal case: stack has space left
//                 top++;
//                 arr[top]=value;
//             }   
            
//         }
//         bool isEmpty(){
//             if(top==-1) return true;
//             else return false;
//         }   
//         void pop(){
//             if(this->isEmpty()){
//                 //stack already empty: removal will cause stack underflow
//                 cout<< "Stack Underflow"<<endl;
//                 return;
//             }
//             else{
//                 //normal case: stack not empty
//                 arr[top]=-1;
//                 top--;
//             }
//         }
//         int getSize(){
//             return top+1; //returns number of elements
//         }
//         int getTop(){
//             if(this->isEmpty()){
//                 cout<<"Stack is Empty"<<endl;
//                 return -1;
//             } 
//             else{
//                 //normal case: stack not empty
//                 return arr[top];
//             }
//         }
// };

// //implementation of stack
// class DoubleStack{
//     public:
//         int* arr;
//         int size;
//         int top1;
//         int top2;
  
//         DoubleStack(int capacity){
//             size=capacity;
//             arr=new int(capacity);
//             top1=-1;
//             top2=size;
//         }

//         void push1(int value){
//             if(top1+1 == top2){
//                 // stack is already full: insertion will cause stack overflow
//                 cout<<"Stack 1 Overflow"<<endl;
//                 return;
//             }
//             else{
//                 //normal case: stack has space left
//                 cout<<"not full"<<endl;
//                 top1++;
//                 arr[top1]=value;
//             }   
            
//         }
//         void push2(int value){
//             if(top1 == top2-1){
//                 // stack is already full: insertion will cause stack overflow
//                 cout<<"Stack Overflow"<<endl;
//                 return;
//             }
//             else{
//                 //normal case: stack has space left
//                 top2--;
//                 arr[top2]=value;
//             }   
            
//         }
//         bool isEmpty1(){
//             if(top1==-1) return true;
//             else return false;
//         } 
//         bool isEmpty2(){
//             if(top2==size) return true;
//             else return false;
//         }   
//         void pop1(){
//             if(this->isEmpty1()){
//                 //stack already empty: removal will cause stack underflow
//                 cout<< "Stack1 Underflow"<<endl;
//                 return;
//             }
//             else{
//                 //normal case: stack not empty
//                 arr[top1]=-1;
//                 top1--;
//             }
//         }
//         void pop2(){
//             if(this->isEmpty2()){
//                 //stack already empty: removal will cause stack underflow
//                 cout<< "Stack2 Underflow"<<endl;
//                 return;
//             }
//             else{
//                 //normal case: stack not empty
//                 arr[top2]=-1;
//                 top2++;
//             }
//         }
//         int getSize1(){
//             return top1+1; //returns number of elements
//         }
//         int getSize2(){
//             return size-top2; //returns number of elements
//         }
//         int getTop1(){
//             if(this->isEmpty1()){
//                 cout<<"Stack1 is Empty"<<endl;
//                 return -1;
//             } 
//             else{
//                 //normal case: stack not empty
//                 return arr[top1];
//             }
//         }
//         int getTop2(){
//             if(this->isEmpty2()){
//                 cout<<"Stack is Empty"<<endl;
//                 return -1;
//             } 
//             else{
//                 //normal case: stack not empty
//                 return arr[top2];
//             }
//         }
// };

// void insertAtBottom( Stack &s, int value ){
//     if(s.isEmpty()){
//         s.push(value);
//         return;
//     }
//     int currentTop=s.getTop();
//     s.pop();
//     insertAtBottom(s, value); //recursion
//     s.push(currentTop); //backTracing
// }

// int main(){
//     // Stack s(6);
//     // cout<<s.isEmpty();
//     // s.push(5);
//     // s.push(10);
//     // s.push(15);
//     // s.push(20);
//     // s.push(25);
//     // cout<<s.getTop()<< endl;
//     // s.pop();
//     // cout<<s.getTop()<<endl;
//     // s.push(25);
//     // cout<<s.getSize()<<endl;
//     // s.push(30);

//     //inserTing At Bottom of a stack
//     Stack s1(10);
//     s1.push(10);
//     s1.push(15);
//     s1.push(20);
//     s1.push(25);
//     s1.push(30);
    
//     int value=5;
//     insertAtBottom(s1,value);

//     // traverse
//     while(!s1.isEmpty()){
//         cout<<s1.getTop()<< " ";
//         s1.pop();
//     }
    
    
//     //two stacks in a single array

//     // DoubleStack s2(6);
//     // s2.push1(10);
//     // s2.push1(20);
//     // s2.push1(30);
//     // s2.push1(40);
//     // s2.push1(50);
//     // s2.push1(60);
//     // cout<<s2.getTop1()<<endl;
//     // s2.push1(70);
//     return 0;
// }

// 