#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int own=0;
    int a,b;
    int *famous=new int[n];
    int *kind=new int[n];
    
    for(int i=0;i<n;i++){
        cin>>famous[i]>>kind[i];
    }
    for(int i=0;i<n;i++){        
        int num=abs(famous[i]-own);
        if(num<=kind[i]){    
            own++;
        }
    }
    

    cout<<own;
    delete[] famous;
    delete[] kind;
}
