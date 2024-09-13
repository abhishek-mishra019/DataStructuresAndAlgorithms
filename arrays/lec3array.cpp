#include <iostream>
#include <vector>
using namespace std;

//2d array
void print2dArrayRowWise(int arr[][100],int  m,int n){
    for(int i=0; i<m;i++){
        for(int j=0; j<n;j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
}
void print2dArrayColWise(int arr[][100],int  m,int n){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout<<arr[j][i]<< " ";
        }
        cout<<endl;
    }
}
void print2dArrayDiagonal(int arr[][100],int  m,int n){
    for(int i=0; i<m;i++){
        cout<<arr[i][i]<< " ";
    }
}
void print2dArrayReverseDiagonal(int arr[][100],int  m,int n){
        for(int i=m-1;i>=0; i--){
            for(int j=n-1;j>=0; j--){
                if(i+j+1==m){
                    cout<<arr[i][j]<<" ";
                }
            }
        } 
}
bool search2dArray(int arr[][100], int m, int n, int target){
    for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int m,n;
    int target;
    cin>>m;
    cin>>n;
    int arr[100][100];
    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++){
             cin>>arr[i][j];
        }
    }
    // print2dArrayRowWise(arr,m,n);
    // cout<<endl;
    // print2dArrayColWise(arr,m,n);
    // cout<<endl;
    // print2dArrayDiagonal(arr,m,n);
    // cout<<endl;
    // print2dArrayReverseDiagonal(arr,m,n);
    // cout<<endl;
    cin>>target;
    bool exist= search2dArray(arr,m,n,target);
    (exist)? cout<<"true": cout<< "false";
    cout<<endl;
    return 0;
}