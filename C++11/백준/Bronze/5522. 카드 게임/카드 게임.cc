#include <iostream>
using namespace std;
int main(){
    int n = 5;
    int ans = 0;
    while(n--){
        int x;
        cin >> x;
        ans += x;
    }
    cout << ans;
}