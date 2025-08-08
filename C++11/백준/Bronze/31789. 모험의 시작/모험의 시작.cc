#include <iostream>
#include <vector>
using namespace std;
#define X first
#define Y second
int n,x,s;
vector<pair<int,int>> weapon(100);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> x >> s;
    for(int i = 0; i < n; i++){
        cin >> weapon[i].first >> weapon[i].second;
    }
    for(auto c : weapon){
        if (c.X <= x && c.Y > s){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}