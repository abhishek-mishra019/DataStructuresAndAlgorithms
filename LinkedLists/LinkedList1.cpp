#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int value){ //creation
        this->data=value;
        this->next=NULL;
    }
};

void insertAtHead(int value, Node* &head, Node* &tail){
    if(head==NULL && tail==NULL){ //linkedlist is empty
        Node* newnode=new Node(value);   //create a new node
        head=newnode;  //head ko node pr lagado
        tail=newnode; //tail ko node pr lagado
    }
    else{
        Node* newnode= new Node(value);  //new node banao
        newnode->next=head; //connect this new node to head node
        head=newnode; //head to update krdo
    }
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtTail(int value, Node* &head, Node* &tail){
    if(head==NULL && tail==NULL){
        Node* newNode= new Node(value);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode= new Node(value);
        tail->next=newNode;
        tail=newNode; 
    }
}
int getLength(Node* &head){
    int length=0;
    Node* temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}
void insertAtPostion(int value, int position, Node* &head, Node* &tail ){
    //assume valid position
    int length=getLength(head);
    if(position==1){
         //head insertion
         insertAtHead(value, head, tail);
    }
    else if(position==length+1){
        //tail insertion
        insertAtTail(value, head, tail);
    }
    else{  // in between head and tail
        int count=1;
        Node* temp=head;
        while(count<=position-2){
            count++;
            temp=temp->next;
        }
        Node* newNode= new Node(value);
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

int searchInLinkedList(Node* head, int target){
    Node*  temp=head;
    int pos=0;  
    while(temp!=NULL){
        pos++;
        if(temp->data==target) return pos;
        temp=temp->next;
    }
    return -1;

}

void deleteNode(int position, Node* &head, Node* &tail){
    if(head==NULL && tail==NULL){  //empty linked list
        return;
    }
    else if(head==tail){ //single node exists in linked list
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    else{
        if(position==1){ //delete from head
            Node* temp= head;
            head=temp->next;
            temp->next=NULL; //NODE ISOLATION
            delete temp;
        }
        else { //delete from any other node
            int count=1;
            Node* temp=head;
            while(count<=position-2){
                count++;
                temp=temp->next;
            }
            Node* nodeToDelete=temp->next;
            temp->next=nodeToDelete->next;
            nodeToDelete->next=NULL; //NODE ISOLATION
            delete nodeToDelete;
        }   
    }
}
int main(){ 
    Node* head=NULL;
    Node* tail=NULL;
    //LL is empty
    //head insertion
    insertAtHead(30,head, tail);
    print(head);//10->NULL
    insertAtHead(20, head, tail);
    print(head);//20->10->NULL
    insertAtHead(10,head, tail);
    print(head);////30->20->10->NULL

    //tail insertion
    insertAt Tail(25, head, tail);
    print(head);

    int length=getLength(head);
    cout<<"length of linked list: "<<length<<endl;

    //insert at position
    insertAtPostion(50,5, head, tail);
    print(head);
    int pos=searchInLinkedList(head, 45);
    if(pos!=-1)cout<<pos;
    else cout<<"does not exist"<<endl;


    //deletion from linked list
    deleteNode(1, head, tail);  //head deletion
    print(head);


    deleteNode(3,head, tail); //delete in between
    print(head); 

    deleteNode(getLength(head), head, tail); //tail delete
    print(head);
    return 0;
}