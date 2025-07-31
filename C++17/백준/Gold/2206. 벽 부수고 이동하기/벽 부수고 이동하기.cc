#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
#define X first
#define Y second
string board[1000];
int dist[1000][1000][2]; // (x, y, 벽 부순 횟수)
queue<tuple<int,int, int>> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> board[i];
	}
	dist[0][0][0] = 1; q.push({0,0,0});
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
			if (board[nx][ny] == '0' && dist[nx][ny][broken] == 0) {
				q.push({ nx,ny,broken }); dist[nx][ny][broken] = dist[x][y][broken] + 1;
			}

			// 벽이고 아직 안부쉈다면
			if (board[nx][ny] == '1' && broken == 0 && dist[nx][ny][1] == 0) {
				dist[nx][ny][1] = dist[x][y][broken] + 1;
				q.push({ nx, ny, 1 });
			}
		}
	}
	int res1 = dist[n - 1][m - 1][0];
	int res2 = dist[n - 1][m - 1][1];
	if (res1 == 0 && res2 == 0)cout << -1;
	else if (res1 == 0)cout << res2;
	else if (res2 == 0)cout << res1;
	else cout << min(res1, res2);
	return 0;
}