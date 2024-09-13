#include<iostream>
using namespace std;

int countDer(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return (n-1)*(countDer(n-2)+countDer(n-1));
}
int getPaintWays(int n, int k){
    if(n==1) return k;
    if(n==2) return k+k*(k-1);

    return (k-1)*(getPaintWays(n-2,k)+getPaintWays(n-1,k));
}

int main(){
    // int n=6 ;
    // cout<<"counting derangement: "<<countDer(n)<<endl;

    int n=3;
    int k=3;
    cout<<"PaintWays: "<<getPaintWays(n,k)<<endl;
    return 0;
}