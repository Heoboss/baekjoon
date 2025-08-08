#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int n, m;
#define X first
#define Y second
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int board[305][305];
bool vis[305][305];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int mx_height = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			mx_height = max(mx_height, board[i][j]);
		}
	}

	int time = 0;
	while (true) {
		int bing = 0;
		mx_height = 0; // ← 새 해 시작 시 초기화
		int tmp[305][305] = { 0 };
		memset(vis, 0, sizeof(vis));

		// 덩어리 세기 & 감소량 계산
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] || board[i][j] == 0) continue;
				bing++;
				queue<pair<int, int>> q;
				q.push({ i,j }); vis[i][j] = 1;

				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					int dec_cnt = 0;
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == 0) dec_cnt++;
						else if (!vis[nx][ny]) {
							vis[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
					tmp[cur.X][cur.Y] = max(0, board[cur.X][cur.Y] - dec_cnt);
					mx_height = max(mx_height, tmp[cur.X][cur.Y]);
				}
			}
		}

		if (bing >= 2) { cout << time; return 0; }
		if (mx_height == 0) { cout << 0; return 0; }

		memcpy(board, tmp, sizeof(tmp));
		time++;
	}

	return 0;
}