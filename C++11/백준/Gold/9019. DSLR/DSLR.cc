#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define X first
#define Y second
int T;
bool visited[10000];

void solve() {
    int A, B;
    cin >> A >> B;

    memset(visited, 0, sizeof(visited));

    queue<pair<int, string>> q;
    q.push({ A, "" });
    visited[A] = true;

    while (!q.empty()) {
        int cur_num = q.front().X;
        string cur_path = q.front().Y;
        q.pop();

        // 만들었으면 출력
        if (cur_num == B) {
            cout << cur_path << "\n";
            return;
        }

        // D
        int nx_d = (cur_num * 2) % 10000;
        // 만들었던 수라면 pass
        if (!visited[nx_d]) {
            visited[nx_d] = 1;
            q.push({ nx_d, cur_path + 'D' });
        }

        // S
        int nx_s = (cur_num == 0) ? 9999 : cur_num - 1;
        if (!visited[nx_s]) {
            visited[nx_s] = 1;
            q.push({ nx_s, cur_path + 'S' });
        }

        // L : 각 자릿수를 왼편으로 회전
        int nx_l = (cur_num % 1000) * 10 + (cur_num / 1000);
        if (!visited[nx_l]) {
            visited[nx_l] = true;
            q.push({ nx_l, cur_path + 'L' });
        }

        // R : 각 자릿수를 오른편으로 회전
        int nx_r = (cur_num % 10) * 1000 + (cur_num / 10);
        if (!visited[nx_r]) {
            visited[nx_r] = true;
            q.push({ nx_r, cur_path + 'R' });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}