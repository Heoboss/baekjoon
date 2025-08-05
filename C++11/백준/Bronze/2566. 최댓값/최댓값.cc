#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int n = 9, m = 9;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> v1(100, vector<int>(100));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v1[i][j];
        }
    }
    int idx1=1, idx2=1, mx = v1[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mx < v1[i][j]) {
                idx1 = i+1;
                idx2 = j+1;
                mx = v1[i][j];
            }
        }
    }
    cout << mx << '\n' << idx1 << ' ' << idx2;
    return 0;
}