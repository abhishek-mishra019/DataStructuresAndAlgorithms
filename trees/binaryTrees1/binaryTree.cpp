#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Node* createTree(){
    int value;
    // cout<<"enter the value for node"<<endl<<endl;
    cin>>value;
    if( value == -1 ){
        return NULL;
    } 
    else{
        Node* root= new Node(value);
        
        // cout<<"adding left child for "<< value<<endl;
        root->left=createTree();

        // cout<<"adding right child for "<<value<<endl;
        root->right=createTree();
        return root;
    }
}

void preOrderTraversal(Node* root){
    if(root == NULL){ //empty tree
        return;
    }
    //  N L R
    // N
    cout<<root->data<<" ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right); 
}

void inOrderTraversal(Node* root){
    if(root == NULL){ //empty tree
        return;
    }
    //  L N R
    // L
    inOrderTraversal(root->left);
    // N
    cout<<root->data<<" ";
    // R
    inOrderTraversal(root->right); 
}

void postOrderTraversal(Node* root){
    if(root == NULL){ //empty tree
        return;
    }
    //  L  R N
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right); 
    // N
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front=q.front();
        bool leftToRight=false;
        q.pop();
        if(front==NULL){
            // mtlb ek level complete hogaya
            cout<<endl;
            //mtlb ek level ke saare children bhi queue mein aagye, i.e agla level queue me agya
            //agle level ke liye NULL ko push krenge
            if(!q.empty()){ //to check that it was not the last level
                q.push(NULL);
            }
            leftToRight = !leftToRight;
        }
        else{
            cout<<front->data<<" ";
            if(leftToRight){
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            else{
                if(front->right!=NULL){
                    q.push(front->right);
                }
                if(front->left!=NULL){
                    q.push(front->left);
                }
            }
        }
    }
}

int main(){
    Node* root=NULL;
    root=createTree();

    cout<<"preOrder Traversal"<<endl;
    preOrderTraversal(root);

    cout<<endl<<"InOrder Traversal"<<endl;
    inOrderTraversal(root);

    cout<<endl<<"PostOrder Traversal"<<endl;
    postOrderTraversal(root);


    cout<<endl<<"LevelOrder Traversal"<<endl;
    levelOrderTraversal(root);
    return 0;
}