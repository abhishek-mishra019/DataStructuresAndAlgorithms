#include <iostream>
using namespace std;
void fullPyramid(){
    int r;
    cin>>r;
    for(int i=0;i<r;i++){
        for(int j=0; j<r-i-1; j++){
            cout<<" ";
        }
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        cout<<endl; 
    }
}
void invertedPyramid(){
    int r;
    cin>>r;
    for(int i=0;i<r;i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int j=0; j<r-i; j++){
            cout<<"* ";
        }
        cout<<endl; 
    }

}
void diamond(){
    int r;
    cin>>r;
    for(int i=0;i<r;i++){  //full pyramid
        for(int j=0; j<r-i-1; j++){
            cout<<" ";
        }
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        cout<<endl; 
    }
    for(int i=0;i<r;i++){  //inverted pyramid
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int j=0; j<r-i; j++){
            cout<<"* ";
        }
        cout<<endl; 
    }
}
void hollowPyramid(){
    int r;
    cin>>r;
    for(int i=0;i<r;i++){
        for(int j=0; j<r-i-1; j++){
            cout<<" ";
        }
        for(int j=0; j<i+1; j++){
            if(i==0 || i==r-1 || j==0 || j==i){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl; 
    }
}
void invertedHollowPyramid(){
    int r;
    cin>>r;
    for(int i=0;i<r;i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int j=0; j<r-i; j++){
            if(i==0 || i==r-1 || j==0 || j==r-i-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl; 
    }

}
void hollowDiamond(){
    int r;
    cin>>r;
    for(int i=0;i<r;i++){  //full pyramid
        for(int j=0; j<r-i-1; j++){
            cout<<" ";
        }
        for(int j=0; j<i+1; j++){
            if(i==0 || j==0 || j==i){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl; 
    }
    for(int i=0;i<r;i++){  //inverted pyramid
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int j=0; j<r-i; j++){
            if(i==r -1 || j==0 || j==r-i-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl; 
    }
}
void mixPyramid(){
   int r;
   cin>>r;
  for(int i=0; i<r;i++){  
        for(int j=0; j<r-i; j++){    
            cout<<"*";     
        
        }

        for(int j=0; j<2*i+1; j++){
                cout<<" ";
        }

        for(int j=0; j<r-i; j++){    
            cout<<"*";     
        
        }
        cout<<endl;
    }

//second half

    for(int i=0; i<r;i++){  
        for(int j=0; j<i+1; j++){    
            cout<< "*";     
        
        }

        for(int j=0; j<2*(r-i)-1; j++){
            cout<<" ";
        }
        
        for(int j=0; j<i+1; j++){    
            cout<< "*";     
        }
        cout<<endl;
    }

}



//Fancy12pattern
void fancy12Pattern(){
    int r;
    cin>>r;
    for(int i=0; i<r;i++){
        for(int j=0; j<2*i+1;j++){
            if(j%2==0){
                cout<<i+1<<" ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
void fullfancy12Pattern(){
    int r;
    cin>>r;
    for(int i=0; i<r;i++){
        for(int j=0; j<2*i+1;j++){
            if(j%2==0){
                cout<<i+1<<" ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
    r--;
    for(int i=0; i<r;i++){
        for(int j=0; j<2*(r-i)-1;j++){
            if(j%2==0){
                cout<<r-i<<" ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}

void ABCBApattern(){
    int r;
    cin>>r;
    for(int i=0; i<r; i++){
        char ch='A'- 1;
        for(int j=0; j<i+1; j++){
            ch++;
            cout<<ch;
            // if((j%i==0) ch='A'-1;
        }
        for(int j=0; j<i; j++){
            ch--;
            cout<<ch;
        }
        cout<<endl;
    }
}

int main(){
    // fullPyramid();
    // invertedPyramid();
    // diamond();
    // hollowPyramid();
    // invertedHollowPyramid();
    // hollowDiamond();
    // mixPyramid();
    // fullfancy12Pattern();
    ABCBApattern();
    return 0;

}