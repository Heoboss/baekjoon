#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int n,m;
int cur_score[1000];
int ex_score[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> cur_score[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> ex_score[i];
    }
    int mx = 0;
    for (int i = 0; i < m; i++) {
        mx = max(mx,ex_score[i] - cur_score[i]);
    }
    cout << mx;
    return 0;
}