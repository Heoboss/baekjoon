#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(auto c : v){
        cout << c << ' ';
    }
    return 0;
}