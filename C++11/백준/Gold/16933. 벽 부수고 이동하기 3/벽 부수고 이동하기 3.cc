#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

#define X first
#define Y second

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

string board[1005];
int dist[1000][1000][11][2]; // {x, y, 벽 부순 갯수, 낮 : 0 / 밤 : 1 }
int res[11][2];
int n, m, k;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	queue<tuple<int, int, int, int>> q;
	memset(dist, -1, sizeof(dist));
	dist[0][0][0][0] = 1;
	dist[0][0][0][1] = 1;
	q.push({ 0,0,0,0 });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = get<0>(cur);
		int y = get<1>(cur);
		int broken = get<2>(cur);
		int day = get<3>(cur);
		//cout << "cur : " << x << ' ' << y << ' ' << broken << ' ' << day << '\n';
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nd = (day + 1) % 2;
			//cout << nx << ' ' << ny << ' ' << broken << ' ' << nd << '\n';
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// 이동 가능하고 아직 방문 안한 경우
			if (board[nx][ny] == '0' && dist[nx][ny][broken][nd] == -1) {
				dist[nx][ny][broken][nd] = dist[x][y][broken][day] + 1;
				q.push({ nx,ny,broken,nd });
			}

			// 벽이고 낮이고 아직 안부쉈다면
			if (board[nx][ny] == '1' && broken < k && dist[nx][ny][broken + 1][nd] == -1 && day == 0) {
				dist[nx][ny][broken + 1][nd] = dist[x][y][broken][day] + 1;
				q.push({ nx, ny, broken + 1, nd });
			}

			// 벽이고 밤이고 아직 안부쉈다면
			else if (board[nx][ny] == '1' && broken < k && dist[x][y][broken][nd] == -1 && day == 1) {
				dist[x][y][broken][nd] = dist[x][y][broken][day] + 1;
				q.push({ x, y, broken , nd });
			}
		}
	}
	int ans = 1e9;

	for (int i = 0; i <= k; i++) {
		res[i][0] = dist[n - 1][m - 1][i][0];
		res[i][1] = dist[n - 1][m - 1][i][1];
		if (res[i][0] != -1)
			ans = min(res[i][0], ans);
		if (res[i][1] != -1)
			ans = min(res[i][1], ans);
	}
	if (ans == 1e9) cout << -1;
	else cout << ans;

	return 0;
}