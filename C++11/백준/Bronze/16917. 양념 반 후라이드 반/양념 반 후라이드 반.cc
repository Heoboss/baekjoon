#include <iostream>
using namespace std;
 
int main(){
 
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    
    
    bool ischeapBanBan = A+B>2*C ? true : false;    //양념 + 후라이드 각각 사는게 더 싼지 체크
    
    long long mini = 10000000000, sum;
    if(ischeapBanBan){
        
        if(X>Y) {
           
            for(int i = Y; i<=X; i++){
                sum = 2*C*i + (X-i)*A;          //(X-i) : 반반 구매하고 더 구매해야 하는 양념 치킨 수
                if(sum<mini) {mini = sum;}
            }
        }
        else {
            for(int i = X; i<=Y; i++){
                sum = 2*C*i + (Y-i)*B;         //(Y-i) : 반반 구매하고 더 구매해야 하는 후라이드 치킨 수
                if(sum<mini) {mini = sum;}
            }
        }
        
    }
    else{
        mini  = A*X + B*Y;
    }
    
    cout << mini;
    return 0;
}