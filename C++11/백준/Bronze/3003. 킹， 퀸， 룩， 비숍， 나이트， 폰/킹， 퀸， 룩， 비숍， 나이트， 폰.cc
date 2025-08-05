#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int n = 6;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> vv(n);
    vv[0] = 1;
    vv[1] = 1;
    vv[2] = 2;
    vv[3] = 2;
    vv[4] = 2;
    vv[5] = 8;
    for (int i = 0; i < n; i++) {
        cout << vv[i] - v[i] << ' ';
    }
    return 0;
}