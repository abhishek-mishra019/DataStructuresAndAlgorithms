#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseQueueRecursive(queue<int>&q){ //using recusrion and backtracking
    if(q.empty()){
        return;
    }
    int el=q.front();
    q.pop();
    reverseQueueRecursive(q);
    q.push(el);
}

void reverseInKGroups(queue<int> &q, int k, int n){
    if(n<k){
        //size is less than k ==> cannot reverse
        while(n>0){
            q.push(q.front());
            q.pop();
            n--;
        }
        return;

    }
    int count=0;
    stack<int> st;
    while(count<k){
        st.push(q.front());
        q.pop();
        count++;
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    reverseInKGroups(q,k,n-k);
}

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){

    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);
    int k=3;

    print(q);
    int n=q.size();
    reverseInKGroups(q,k,n);
    print(q);

    return 0;
}