#include<iostream>
#include<vector>
using namespace std;

void findMissingElements(int arr[], int n){
    int i=0;
    while(i<n){
        int index=arr[i]-1;
        if(arr[i]!=arr[index]) swap(arr[i],arr[index]);
        else i++;
    }
    for(int i=0; i<n;i++){
        if(arr[i]!=i+1){
            cout<<i+1<< " ";
        }
    }
}
 
void wavePrintMatrix(vector<vector<int>> &arr, int m, int n){
    for(int i=0; i<n; i++){
        if(( i&1)==0){ //even column index
            for(int j=0; j<m; j++){
                cout<<arr[j][i]<< " ";
            }
        }
        else{
            for(int j=m-1; j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
    }
} 
void spiralPrintMatrix(vector<vector<int>>&arr, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<< arr[i][j];
        }
    }
}
int main(){
    vector<vector<int>> arr{
        {10,11,12,13},
        {14,15,16,17},
        {18,19,20,21},
        {22,23,24,25}
    }; 
    int m=arr.size();
    int n=arr[0].size();

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<"Wave Print Below: "<<endl;
    wavePrintMatrix(arr,m,n);
    // findMissingElements(arr,n);
}