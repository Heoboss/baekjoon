#include <iostream>
#include <vector>
#include <algorithm>

#define BG ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main(void) {
    BG
    
    int n;
    cin >> n;
    
    vector<int> v(n*2);
    for(int i=0; i<n*2; i++) {
        cin >> v[i];
    }

    int res = 0;
    for(int i=1; i<=n; i++) {
        int si = -1;
        int gap = 0;
        for(int j=0; j<n*2; j++) {
            if(v[j] == i) {
                if(si == -1) si = j;
                else gap = j - si - 1;
            }
        }
        res = max(res, gap);
    }
    cout << res;
    return 0;
}