#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    string str;
 
    while(true){
        cin>>str;
        if(str=="0"){
            break;
        }
 
        int cnt=0;
        int len = str.length();
 
        for(int i=0; i<len/2; i++){
            if(str[i]!=str[len-1-i]){
                continue;           // 이 조건이 맞지 않을때는 무시하고 두번쨰 for문으로 넘어간다.
            }
            else{
                cnt++;
            }
        }
        if(cnt==len/2){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
    return 0;
}
