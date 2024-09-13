#include<iostream>
using namespace std;

void findFirstOccurence(int arr[], int n, int target, int & firstIndex){
    int s=0, e=n-1;
    while (s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            // ans found, may or may not be first occurence
            firstIndex=mid;  //store
            e=mid-1;      //compute
        }
        else if(arr[mid]<target) s=mid+1;
        else e=mid-1;
    }    
}
void findLastOccurence(int arr[], int n, int target, int & lastIndex){
    int s=0, e=n-1;
    while (s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            // ans found, may or may not be first occurence
            lastIndex=mid;  //store
            s=mid+1;      //compute
        }
        else if(arr[mid]<target) s=mid+1;
        else e=mid-1;
    }      
}
int main(){
    int arr[]={5,10,20,20,20,20,20, 30,40,50,60};
    // int arr[]={20,20,20,20,20,30,30,30,40,40,40};
    int n=11;
    int target=20;
    int firstIndex=-1;
    int lastIndex=-1;
    findFirstOccurence(arr,n,target, firstIndex);
    findLastOccurence(arr,n,target, lastIndex);
    cout<< "first occurance index of "<<target<< " is : "<< firstIndex<<endl;
    cout<< "last occurance index of "<<target<< " is : "<< lastIndex<<endl;
    int totalOccurance = lastIndex-firstIndex+1;
    cout<< "total number of occurances of "<<target<< " is : "<< totalOccurance<<endl;
    return 0; 
}