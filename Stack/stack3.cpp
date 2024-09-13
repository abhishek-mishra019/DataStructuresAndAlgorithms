#include<iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findNextSmaller(vector<int>&arr){
    int n=arr.size();
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=n-1; i>=0; i-- ){
        int element=arr[i];
        while(s.top()>=element){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(element);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> findPreviousSmaller(vector<int>&arr){
    int n=arr.size();
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=0; i<n; i++){
        int element=arr[i];
        while(s.top()>=element){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(element);
    }
    return ans;
}
void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr={8,4,6,2,3};
    // arr.push_back(8);
    // arr.push_back(4);
    // arr.push_back(6);
    // arr.push_back(2);
    // arr.push_back(3);

    cout<<"original: ";
    print(arr);
    
    cout<<"nextSmaller: ";
    vector<int>nextSmaller=findNextSmaller(arr);
    print(nextSmaller);

    cout<<"previousSmaller: ";
    vector<int> previousSMaller=findPreviousSmaller(arr);
    print(previousSMaller);

    return 0;
}
