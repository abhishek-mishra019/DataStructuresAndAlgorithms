#include<iostream>
#include<vector>
using namespace std;

vector<int> findTwosComplement(vector<int> &binary){
    int n=binary.size();
    vector<int> twosComp(n+1,0);
    // 1s complement of binary saved in new array
    for(int i=n-1, k=twosComp.size()-1; i>=0; i--,k--){
        twosComp[k]=binary[i]==0? 1:0; 
    }
    //adding 1 in the new array
    int carry=1;
    for(int i=twosComp.size()-1; i>=0; i--){
        int sum=twosComp[i]+carry;
        twosComp[i]=sum%2;
        carry=sum/2;
    }
    if(carry) twosComp[0]=carry;
    return twosComp;
} 

int main(){
    vector<int> binary = {0,0, 0,0};
    vector<int>twosComp = findTwosComplement(binary); 
    cout<<"twos complement: "<<endl;
    for(int i=0; i<twosComp.size();i++){
        cout<< twosComp[i]<< " ";
    }
    cout<<endl;
    return 0;
}