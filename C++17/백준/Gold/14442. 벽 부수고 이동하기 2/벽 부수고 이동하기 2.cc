#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

#define X first
#define Y second
int n, m, k;
string board[1005];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int dist[1000][1000][11]; // (x, y, 벽 부순 횟수)
int res[11];
queue<tuple<int, int, int>> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    memset(dist, -1, sizeof(dist));
    dist[0][0][0] = 1; q.push({ 0,0,0 });
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int broken = get<2>(cur);

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            // 이동 가능하고 아직 방문 안한 경우
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                q.push({ nx,ny,broken }); 
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
            }

            // 벽이고 아직 안부쉈다면
            if (board[nx][ny] == '1' && broken < k && dist[nx][ny][broken+1] == -1) {
                dist[nx][ny][broken+1] = dist[x][y][broken] + 1;
                q.push({ nx, ny, broken+1 });
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= k; i++) {
        res[i] = dist[n - 1][m - 1][i];
        if (res[i] != -1) {
            ans = min(res[i], ans);
        }
    }
    if (ans == 1e9) cout << -1;
    else cout << ans;
    return 0;
}

