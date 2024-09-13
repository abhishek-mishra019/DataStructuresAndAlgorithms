#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows: "<<endl;
    cin>>r;
    cout<<"enter number of cols: ";
    cin>>c;
    cout<<endl;
    // for(int i=0; i<4;i++){
    //     for(int j=0; j<4; j++){
    //         cout<<"*"<< " ";     //Square or rectangle
    //     }
    //     cout<<endl;
    // }

    // for(int i=0; i<r;i++){  //hollow rectangle
    //     for(int j=0; j<c; j++){    
    //     if(i==0||i==r-1){
            
    //             cout<<"*"<< " ";
    //         }
        
    //     else{
    //         if(j==0||j==c-1){
    //             cout<<"*"<< " ";
    //         }
    //         else{
    //             cout<< " "<< " ";
    //         }
    //         }
    //     }
    //     cout<<endl;
    // }

    // for(int i=0; i<r;i++){  //half pyramid
    //     for(int j=0; j<i+1; j++){    
    //         cout<<"*"<< " ";     
        
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<r;i++){  //inverted half pyramid
    //     for(int j=0; j<r-i; j++){    
    //         cout<<"*"<< " ";     
        
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<r;i++){  //hollow half pyramid
    //     for(int j=0; j<i+1; j++){   
    //         if(i==0||i==r-1||j==0||j==i){ 
    //         cout<<"*"<< " ";     
    //         } 
    //         else{
    //             cout<<" "<<" ";  
    //         }
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<r;i++){  //inverted hollow half pyramid
    //     for(int j=0; j<r-i; j++){  
    //         if(i==0||i==r-1||j==0||j==r-i-1)  {
    //             cout<<"*"<< " ";     
    //         }
    //         else{
    //             cout<<" "<< " ";
    //         }
    //     }
    //     cout<<endl;
    // }
    // for(int i=0; i<r;i++){  //numeric half pyramid
    //     for(int j=0; j<i+1; j++){    
    //         cout<<j+1<< " ";     
        
    //     }
    //     cout<<endl;
    // }

        for(int i=0; i<r;i++){  //inverted numeric half pyramid
        for(int j=0; j<r-i; j++){    
            cout<<j+1<< " ";     
        
        }
        cout<<endl;
    }
    

    return 0;
}