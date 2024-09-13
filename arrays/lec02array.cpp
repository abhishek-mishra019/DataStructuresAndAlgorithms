#include <iostream>
using namespace std;

void sortZeroesOnes(int arr[], int &n){
    int zeroPtr=0;
    int onePtr=n-1;
    while(zeroPtr<onePtr){
        while(arr[zeroPtr]<0){
            zeroPtr++;
        }
        while(arr[onePtr]>=0){
            onePtr--;
        }
        if(zeroPtr<onePtr)swap(arr[zeroPtr],arr[onePtr]);
        zeroPtr++;
        onePtr--;
    }
}
void printAllTriplets(int arr[], int &n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout<<arr[i] <<endl;
            }
        }
    }
}
int main(){
    int arr[]={-1,2,-3,4,12,-5};
    int n=sizeof(arr)/sizeof(arr[0]);
    sortZeroesOnes(arr,n);
    // printAllTriplets(arr, n);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}