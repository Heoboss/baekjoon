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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cout << n + m << '\n';

    }
    
    return 0;
}