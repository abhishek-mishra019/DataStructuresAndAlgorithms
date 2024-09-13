#include<iostream>
using namespace std;

int squareRootInteger(int n){
    int s=0;
    int e=n;
    int ans;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid*mid<=n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
double squareRootDecimal(int n, int integerAns, int reqPrecision){
    double ans=integerAns;
    double originalAns=ans;
    double factor=0.1;
    int precision=1;
    while(precision<=reqPrecision){
        int s=0;
        int e=9;
        while(s<=e){
            int mid=s+(e-s)/2;
            double val= originalAns+(factor*mid);
            if(val*val <= n){
                ans = originalAns+factor*mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        originalAns=ans;
        factor /=10;
        precision++;
    }
    return originalAns;
}

int main(){
    int n;
    cin>>n;

    int integerAns= squareRootInteger(n);
    int precision;
    cin>>precision; 
    double decimalAns= squareRootDecimal(n, integerAns, precision);
    // cout<<decimalAns<<endl;
    printf("%.7f", decimalAns);
    return 0;
}