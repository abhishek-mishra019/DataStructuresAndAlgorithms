#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int value){
        this->data=value;
        this->prev=NULL;
        this->next=NULL;
    }
};
void insertAtHead(int value, Node* &head, Node* &tail){
    if(head==NULL && tail==NULL){ //linked list is empty
        Node* newNode= new Node(value);  //create new node
        head=newNode; //update head 
        tail=newNode;   //update tail
    }
    else{ //linked list is not empty
        Node* newnode= new Node(value);    //create new node
        newnode->next=head;                // connect newNode to head 
        head->prev=newnode;                // connect head.prev to newnode
        head=newnode;                      // update head
    }
}


void insertAtTail(int value, Node* &head, Node* & tail){
    if(head==NULL && tail ==NULL){ // list is empty
        Node* newNode= new Node(value); //create new node
        head=newNode;                   //update head 
        tail=newNode;                   //update tail
    }
    else{    //list is not empty
        Node* newNode= new Node(value);   //create new node
        newNode->prev=tail;              // connect newnode.prev to tail
        tail->next=newNode;               // connect tail.next to newnode
        tail=newNode;                     // update tail
    }
}

int getLength(Node* &head){
    Node* temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

void insertAtPosition(int value, int position, Node* &head, Node* &tail){
    if(position==1){                        //head position
        insertAtHead(value, head, tail);
    }
    else if(position==getLength(head)+1){  //tail position
        insertAtTail(value, head, tail);
    }
    else{                                   //insert in between
        int count=1;   //from first position
        Node* temp=head;
        while(count<=position-2){
            count++;
            temp=temp->next;
        }
        // now temp is 1 position behind the position node
        Node* newNode= new Node(value);
        Node* forward=temp->next; // this is the node currently at the position
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=forward;
        forward->prev=newNode;

    }

}
void print(Node* &head){
    Node* temp=head;
    cout<<"NULL"<<" <-> ";
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void printReverse(Node* tail){
    Node* temp=tail;
    cout<<"reverse: ";
    cout<<"NULL"<<" <-> ";
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;
}

int searchElement(int target, Node* &head ){
    int pos=-1;
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(temp->data==target) return pos=count;
        temp=temp->next;
    }
    return pos;
}

void deleteFromPosition(int position, Node* &head, Node* &tail){
    if(head==NULL && tail==NULL) {  //empty
        cout<<"empty list cannot be deleted";
    }
    else if(head==tail){ //single node
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    else{
        if(position==1){  //delete head node
            Node* temp=head;
            head=head->next;
            temp->next=NULL;  //node isolation
            delete temp;
        }
        else if(position==getLength(head)){
            Node* temp=tail;
            tail=temp->prev;
            temp->prev=NULL; //node isolation
            tail->next=NULL; 
            delete temp;
        }
        else{ //any other node
            int count=1;
            Node* temp=head;
            while (count<=position-2)
            {
                count++;
                temp=temp->next;
            }
            Node* nodeToDelete=temp->next;
            Node* newAtPosition=nodeToDelete->next;
            temp->next=newAtPosition;
            newAtPosition->prev=temp;
            nodeToDelete->next=NULL;
            nodeToDelete->prev=NULL;
            delete nodeToDelete;
        }
    }
}

int main(){
    Node* head= NULL;
    Node* tail=NULL;
    insertAtHead(20, head, tail);
    insertAtHead(10, head, tail); 
    print(head);
    printReverse(tail);
    insertAtTail(30, head, tail);
    print(head);
    cout<<getLength(head)<<endl;
    printReverse(tail);
    insertAtPosition(25, 3, head, tail);
    print(head);

    cout<<searchElement(15, head)<<endl;

    deleteFromPosition(4, head, tail);
    print(head);
    return 0;
}