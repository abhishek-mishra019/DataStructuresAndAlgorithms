#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int>&q){ //using stack
    stack<int> st;
    while(!q.empty()){
        int el=q.front();
        st.push(el);
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}
void reverseQueueRecursive(queue<int>&q){ //using recusrion and backtracking
    if(q.empty()){
        return;
    }
    int el=q.front();
    q.pop();
    reverseQueueRecursive(q);
    q.push(el);
}
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    print(q);

    reverseQueueRecursive(q);

    print(q);
    return 0;
}