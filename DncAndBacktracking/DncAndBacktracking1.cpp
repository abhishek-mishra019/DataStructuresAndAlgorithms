#include<iostream>
using namespace std;
void merge(int arr[], int s, int e, int mid){
    int leftLength=mid-s+1;
    int rightLength=e-mid;

    int *leftArr = new int[leftLength];
    int *rightArr= new int[rightLength];

    // now copying into these arrays from main array
    int index=s;  //as main array starts from s here
        //  copying into left array from main array
    for(int i=0; i<leftLength; i++){
        leftArr[i]=arr[index];
        index++;
    }
    index=mid+1; 
        //  copying into right array from main array
    for(int i=0; i<rightLength; i++){
        rightArr[i]=arr[index];
        index++;
    }

    //now merging two sorted arrays
    int i=0; 
    int j=0;
    int mainArrayIndex=s;
    while(i<leftLength && j<rightLength){
        if(leftArr[i]<rightArr[j]){
            arr[mainArrayIndex]=leftArr[i];
            i++;
            mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex]=rightArr[j];
            j++;
            mainArrayIndex++;
        }
    }
    while(i<leftLength){
        arr[mainArrayIndex]=leftArr[i];
        i++;
        mainArrayIndex++;
    }
    while(j<rightLength){
        arr[mainArrayIndex]=rightArr[j];
        j++;
        mainArrayIndex++;
    }
    delete[] leftArr;
    delete[] rightArr;
}
void mergeSort(int arr[], int s, int e){
    //base case
    int mid=s+(e-s)/2;
    if(s>=e){ //jab start hi end se aage chala jaye(s>e) ya single element array ho (s==e)
        return;
    }

    //left part recusrion se sort karwao
    mergeSort(arr, s, mid);

    //right part recusrion se sort karwao
    mergeSort(arr, mid+1, e);
    //dono ko merge kardo 
    merge(arr,s,e,mid);
}


int main(){
    int arr[]={10,80,100,30,90,70,60,20,110,112,50,40};
    int size=12;
    int s=0;
    int e=size-1;
    //before merge sort
    cout<<"before merge sort: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,s,e);
    cout<<"after merge sort: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}