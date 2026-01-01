#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

#define INF 0x7FFFFFFF

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll, ll>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        vector<int> a, b, c;
        int n;
        cin >> n;
        a.resize(n);
        for(auto &u : a) cin >> u;
        cin >> n;
        b.resize(n);
        for(auto &u : b) cin >> u;
        cin >> n;
        c.resize(n);
        for(auto &u : c) cin >> u;

        set<int> _s;
        for(auto u : a) {
            for(auto v : b) {
                for(auto w : c) {
                    int sum = u + v + w;
                    string s = to_string(sum);
                    bool check = true;
                    for(auto _c : s) {
                        if(!(_c == '5' || _c == '8')){
                            check = false;
                            break;
                        } 
                    }
                    if(check) _s.insert(sum);
                }
            }
        }
        cout << _s.size() << "\n";
    }

    return 0;
}