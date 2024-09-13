#include <iostream>
#include <vector>
using namespace std;

//2d array
void print2dArrayRowWise(vector<vector<int>> &arr,int  m,int n){
    for(int i=0; i<m;i++){
        for(int j=0; j<n;j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
}
void print2dArrayColWise(vector<vector<int>> &arr,int  m,int n){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout<<arr[j][i]<< " ";
        }
        cout<<endl;
    }
}
void print2dArrayDiagonal(vector<vector<int>> &arr,int  m,int n){
    for(int i=0; i<m;i++){
        cout<<arr[i][i]<< " ";
    }
}
void print2dArrayReverseDiagonal(vector<vector<int>> &arr,int  m,int n){
        for(int i=m-1;i>=0; i--){
            for(int j=n-1;j>=0; j--){
                if(i+j+1==m){
                    cout<<arr[i][j]<<" ";
                }
            }
        } 
}
bool search2dArray(vector<vector<int>> &arr , int m, int n, int target){
    for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==target){
                return true;
            }
        }
    }
    return false;
}
int findMinValue(vector<vector<int>> &arr , int m, int n){
    int ans=INT_MAX;
    for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]<ans){
                ans=min(ans,arr[i][j]);
            }
        }
    }
    return ans;
}
int findMaxValue(vector<vector<int>> &arr , int m, int n){
    int ans=INT_MIN;
    for(int i=0; i<m;i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]>ans){
                ans=max(ans,arr[i][j]);
            }
        }
    }
    return ans;
}
void rowWiseSum(vector<vector<int>> &arr , int m, int n){
    for(int i=0; i<m;i++){
        int sum=0;
        for(int j=0; j<n; j++){
            sum+=arr[i][j];
        }
        cout<<"sum of row "<<i<<" is "<<sum<<endl;
    }
    cout<<endl;
}
void colWiseSum(vector<vector<int>> &arr , int m, int n){
    for(int i=0; i<n;i++){
        int sum=0;
        for(int j=0; j<m; j++){
            sum+=arr[j][i];
        }
        cout<<"sum of col "<<i<<" is "<<sum<<endl;
    }
    cout<<endl;
}
void diagonalSum(vector<vector<int>> &arr , int m, int n){
    int sum=0;
    for(int i=0; i<n;i++){
        sum+=arr[i][i];
    }
    cout<<"sum of diagonal is "<<sum<<endl;
    cout<<endl;
}
void reverseDiagonalSum(vector<vector<int>> &arr , int m, int n){
    int sum=0;
    for(int i=m-1; i>=0;i--){
        for(int j=n-1; j>=0; j--){
            if(i+j+1==m)
            sum+=arr[i][j];
        }
    }
    cout<<"sum of reverse diagonal is "<<sum<<endl;
    cout<<endl;
}
void transposeMatrix(vector<vector<int>> &arr, int m, int n){
        for(int i=0; i<m;i++){
            for(int j=i+1; j<n; j++){ 
                    swap(arr[i][j],arr[j][i]);
            } 
        }
        print2dArrayRowWise(arr,m,n);
}
int main(){
    vector<vector<int>> arr(3, vector<int>(3,0));
    int m=arr.size();
    int n=arr[0].size();
    // taking values
    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++){
             cin>>arr[i][j];
        }
    }
    // print2dArrayRowWise(arr,m,n);
    // cout<<endl;
    // prin t2dArrayColWise(arr,m,n);
    // cout<<endl;
    // print2dArrayDiagonal(arr,m,n);
    // cout<<endl;
    // print2dArrayReverseDiagonal(arr,m,n);
    // cout<<endl;

    // int target;
    // cin>>target;
    // bool exist= search2dArray(arr,m,n,target);
    // (exist)? cout<<"true": cout<< "false";

    // cout<<"Minimum Value is:"<<findMinValue(arr, m,n)<<endl;
    // cout<<"Maximum Value is:"<<findMaxValue(arr, m,n)<<endl;
    // rowWiseSum(arr,m,n);
    // colWiseSum(arr,m,n);
    // diagonalSum(arr,m,n);
    // reverseDiagonalSum(arr,m,n);

    transposeMatrix(arr,m,n);
    return 0;
}