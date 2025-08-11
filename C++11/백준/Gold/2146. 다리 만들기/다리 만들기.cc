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
int board[105][105];
bool vis[105][105];
int mn_dist = 1e9;
int dist[105][105];
#define X first
#define Y second
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0 ,-1 };

void print_board() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int dae = 1;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || board[i][j] == 0) continue;
			vis[i][j] = 1; dae++;
			board[i][j] = dae;
			q.push({ i,j });
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;
					vis[nx][ny] = 1; q.push({ nx,ny }); 
					board[nx][ny] = dae;
				}
			}
		}
	} // 대륙 개수 당 2,3,4 ... 으로 메꿈

	memset(dist, -1, sizeof(dist));

	// 모든 육지에서 동시에 BFS 시작
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] != 0) {
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}
	
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if (board[nx][ny] == 0) {
				board[nx][ny] = board[cur.X][cur.Y];
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx,ny });
			}
			else if (board[nx][ny] != board[cur.X][cur.Y]) {
				mn_dist = min(mn_dist, dist[cur.X][cur.Y] + dist[nx][ny]);
			}
		}
	}
	
	cout << mn_dist; 
	return 0;
}