#include<iostream>
using namespace std;
int getLength(char arr[], int size){
    int count=0;
    int i=0;
    // while(arr[i]!='\0'){
    //     i++;
    //     count++;
    // }
    for(int i=0; i<size; i++){
        if(arr[i]=='\0') break;
        count++; 
    }
    return count;
}
void replaceCharacter(char originalChar, char newChar, char arr[], int size){
    for(int i=0; i<size; i++){
        if(arr[i]==originalChar){
            arr[i]=newChar;
        } 
    }
}
void convertToUpperCase(char arr[], int size){
        for(int i=0; i<size; i++){
            char ch=arr[i];
            if(ch>='a' && ch<='z'){
                ch=ch-'a'+'A';
                arr[i]=ch;
            }
        
    }
}
void convertToLowerCase(char arr[], int size){
        for(int i=0; i<size; i++){
            char ch=arr[i];
            if(ch>='A' && ch<='Z'){
                ch=ch-'A'+'a';
                arr[i]=ch;
            }
        
    }
}
void reverseCharArray(char arr[], int size){
    int length=getLength(arr, size);
    int s=0,  e=length-1;
    while(s<=e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
bool checkPallindrome(char arr[], int size){
    int length=getLength(arr, size);
    int s=0,  e=length-1;
    while(s<=e){
        if(arr[s] == arr[e]){
            s++;
            e--;
        } 
        else return false;
    }
    return true;
}

int main(){
    char name[100];
    cin.getline(name,100, '\n');
    // cout<< name[0]<< "->" << (int)name[0]<<endl;
    // cout<< name[1]<< "->" << (int)name[1]<<endl;
    // cout<< name[2]<< "->" << (int)name[2]<<endl;
    // cout<< name[3]<< "->" << (int)name[3]<<endl;
    // cout<< name[4]<< "->" << (int)name[4]<<endl;
    // cout<< name[5]<< "->" << (int)name[5]<<endl;
    // cout<< name[6]<< "->" << (int)name[6]<<endl;
    // cout<< name[7]<< "->" << (int)name[7]<<endl; 
    // cout<< name[8]<< "->" << (int)name[8]<<endl;
    // cout<< name[9]<< "->" << (int)name[9]<<endl;
    // cout<< name[10]<< "->" << (int)name[10]<<endl;
    // cout<< name[11]<< "->" << (int)name[11]<<endl;
    // cout<<name;
    // cout<<"length is: "<<getLength(name, 100)<<endl;
    cout<<"original: "<<name<<endl;
    replaceCharacter('@', ' ', name,100);
    cout<<"New: "<<name<<endl;
    convertToLowerCase(name,100);
    cout<<"Lower: "<<name<<endl;
    convertToUpperCase(name,100);
    cout<<"Upper: "<<name<<endl;
    reverseCharArray(name, 100);
    cout<<"Reversed: "<<name<<endl;
    cout<<"Pallindrome or not: "<<checkPallindrome(name,100)<<endl;
    return 0;
} 