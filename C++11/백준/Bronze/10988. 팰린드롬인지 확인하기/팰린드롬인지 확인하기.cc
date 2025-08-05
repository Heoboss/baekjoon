#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    string rs;
    for (int i = s.length()-1; i >= 0; i--) {
        rs += s[i];
    }
    if (s == rs) cout << 1;
    else cout << 0;
    return 0;
}