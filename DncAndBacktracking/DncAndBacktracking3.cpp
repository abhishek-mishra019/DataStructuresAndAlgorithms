#include <iostream>
#include<string>

// #include <bits/stdc++.h>
using namespace std;

void printPermutations(string &str, int i){
    //base case
    if(i>=str.length()){
        cout<<str<<endl;
        return;
    }
    //1 case mai dekhunga baki recursion sambhal lega
    // 1 case: main i wale dibbe k upar har ek element ko chance dunga
    for(int j=i; j<str.length(); j++){
        swap(str[i], str[j]);
        printPermutations(str, i+1);
        swap(str[i], str[j]);
    }
}

int main(){
    string str="abc";
    printPermutations(str, 0);

    return 0;
}