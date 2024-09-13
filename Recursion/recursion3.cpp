#include<iostream>
#include<vector>
#include<string>
using namespace std;

void storeAllSubsequences(string input, int index, string output, vector<string> &ans){
    if(index==input.length()){
        ans.push_back(output);
        return; 
    }
    char ch=input[index];
    //exclude
    storeAllSubsequences(input, index+1, output, ans);
    
    //include
    storeAllSubsequences(input, index+1, output+ch, ans);
}

int main(){
    string input="xy";
    int index=0;
    string output="";
    vector<string> ans;
    storeAllSubsequences(input, index, output, ans);
    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}