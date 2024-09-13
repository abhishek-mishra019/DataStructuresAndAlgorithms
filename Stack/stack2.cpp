#include <iostream>
#include <stack>
using namespace std;


void printMiddleElement(stack<int> &s, int count){
    if(count==0){
        cout<<s.top()<<endl;
        return; 
    }
    count--;
    int current=s.top();
    s.pop();
    printMiddleElement(s, count);
    s.push(current);

} 
bool checkSorted(stack<int> &s, int prevTop=INT_MAX ){
    if(s.empty()) return true;  //base case

    int currentTop=s.top();

    if(currentTop<prevTop){
        // 1 case sorted haii
        s.pop();
        //baki case recursion check krega
         bool ans= checkSorted(s, currentTop);
         s.push(currentTop);//backtrack
         return ans;
    }
    else{
        // sorted nahi hai matlab false return kar do
        //no need to check baaki cases
        return false;
    }
}

void sortedInsertion(stack<int> &s, int value ){
    //given a sorted stack, insert a value at the rightly sorted place
    if(s.empty()){
        s.push(value);
        return ;  //base case
    } 

    int currentTop=s.top();

    if(currentTop<value){
        s.push(value); //base case
        return;
    }
    else{
        //need to insert lower
        s.pop();
        sortedInsertion(s,value);//recursion
        s.push(currentTop); //backtrack
    }
}

void insertAtBottom(stack<int>&s, int value){
    if(s.empty()){
        s.push(value);
        return;
    }
    int currentTop=s.top();
    s.pop();
    insertAtBottom(s,value);
    s.push(currentTop);
}

void reverseTheStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int currentTop=s.top();
    s.pop();
    reverseTheStack(s);
    insertAtBottom(s,currentTop);
}


void sortedInsertion(stack<int> &s, int value ){
    //given a sorted stack, insert a value at the rightly sorted place
    if(s.empty()){
        s.push(value);
        return ;  //base case
    } 

    int currentTop=s.top();

    if(currentTop<value){
        s.push(value); //base case
        return;
    }
    else{
        //need to insert lower
        s.pop();
        sortedInsertion(s,value);//recursion
        s.push(currentTop); //backtrack
    }
} 


int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    int count=s.size()/2;
    printMiddleElement(s,count);
 

    cout<<checkSorted(s)<<endl;
    

    // insertAtBottom(s,5);
    // reverseTheStack(s);
    sortedInsertion(s,35);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
     
    return 0;
}