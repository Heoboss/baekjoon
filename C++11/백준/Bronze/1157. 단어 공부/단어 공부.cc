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
int cnt[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            cnt[s[i] - 'a']++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            cnt[s[i] - 'A']++;
        }
    }
    queue<int> q;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (ans < cnt[i]) {
            ans = max(ans, cnt[i]);
            while (!q.empty()) q.pop();
            q.push(i);
        }
        else if (ans == cnt[i]) {
            q.push(i);
        }
    }
    if (q.size() >= 2) cout << '?';
    else {
        cout << char(q.front() + 'A');
    }
    return 0;
}