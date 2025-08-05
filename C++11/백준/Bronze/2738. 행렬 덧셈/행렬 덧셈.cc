#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> v1(100, vector<int>(100));
    vector<vector<int>> v2(100, vector<int>(100));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v2[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v1[i][j]+ v2[i][j]<< ' ';
        }
        cout << '\n';
    }
    return 0;
}