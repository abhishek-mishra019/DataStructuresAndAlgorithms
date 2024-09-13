//Recursion with array,

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void printArray(int arr[], int size, int index){
    if(index==size) {
        //array se bahar aagye
        cout<<endl;
        return;
    }
    cout<<arr[index]<< " ";
    printArray(arr, size, index+1);
}

bool searchInArray(int arr[], int size, int index, int target){
    if ( index == size){
        //not found
        return false;
    }  
    if(arr[index]==target){
        return true;
    }

    return searchInArray(arr, size, index+1, target);
}
int maxInArray(int arr[], int size, int index, int ans){
    if(index==size) return ans;
    
    ans=max(arr[index], ans);
    return maxInArray(arr, size, index+1, ans);
}
int minInArray(int arr[], int size, int index, int ans){
    if(index==size) return ans;
    
    ans=min(arr[index], ans);
    return minInArray(arr, size, index+1, ans);
}
void printAllOdds(int arr[], int size, int index){
    if(index==size) {
        //array se bahar aagye
        cout<<endl;
        return;
    }
    if((arr[index])&1){
        cout<<arr[index]<< " ";
    } 
    printAllOdds(arr, size, index+1);
}
void printAllEvens(int arr[], int size, int index){
    if(index==size) {
        //array se bahar aagye
        cout<<endl;
        return;
    }
    if(!((arr[index])&1)){
        cout<<arr[index]<< " ";
    } 
    printAllEvens(arr, size, index+1);
}

void storeAllOdds(int arr[], int size, int index, vector<int> &ans){
    if(index==size) {
        //array se bahar aagye 
        return;
    }
    if((arr[index])&1){
        ans.push_back(arr[index]);
    } 
    storeAllOdds(arr, size, index+1, ans);
}
int binarySearch(int arr[], int start, int end, int target){
    if(start>end) return -1;
    int mid=start+(end-start)/2;
    if(arr[mid]==target) return mid;

    if(arr[mid]>target){
        return binarySearch(arr, start, mid-1, target);
    }
    if(arr[mid]<target){
        return binarySearch(arr, mid+1, end, target);
    }
    return 0;
}
void printDigits(int input){
    if(input==0){
        return; 
    } 
    printDigits(input/10);
    cout<<input%10<< " ";
}

bool sortedOrNot(int arr[], int size, int index ){
    if(size-1==index){
        return true;
    } 
    if(arr[index]>arr[index+1]) {
        return false;
    }

    return sortedOrNot(arr, size,index+1);
}

int main(){
    int arr[]={10,20, 30,40, 50};
    int size= sizeof(arr)/sizeof(arr[0]);
    int index=0;
    cout<<"printing Array: ";
    printArray(arr, size, index);

    cout<<"searching 50: "<< searchInArray(arr, size, index,50)<<endl;
    
    cout<<"max: "<<maxInArray(arr, size, index, INT_MIN)<<endl;
    
    cout<<"min: "<<minInArray(arr, size, index, INT_MAX)<<endl;
    
    cout<<"printing Odds:";
    printAllOdds(arr,size,index);
    cout<<"printing Evens";
    printAllEvens(arr,size,index);


    vector<int> odds;
    storeAllOdds(arr, size, index, odds);
    for(auto i: odds){
        cout<<i<<endl;
    }
    cout<<"bs 50 index: "<<binarySearch(arr, 0, size-1, 50)<<endl;
    cout<<"printing digits 389:";
    printDigits(389);
    cout<<endl;
    cout<<"check if sorted array: "<<sortedOrNot(arr, size, index)<<endl;
    return 0;
}