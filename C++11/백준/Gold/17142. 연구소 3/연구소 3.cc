#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
using namespace std;
#define X first
#define Y second

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
const int MX = 0x7f7f7f7f;

int n, m, ans = MX;
int board[52][52];
int board_t[52][52];
int dist[52][52];

vector<pair<int, int>> virus;
vector<int> mask;
queue<pair<int, int>> q;

bool OOM(int i, int j) {
	return (i < 0 || i >= n || j < 0 || j >= n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i,j });
				board[i][j] = 0;
				mask.push_back(0);
			}
		}
	}
	// 뽑을 개수만큼만 0으로 남게됨
	for (int i = m; i < mask.size(); i++) {
		mask[i] = 1;
	}
	do {
		int tt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board_t[i][j] = board[i][j];
			}
		} //board 로 map 복사

		for (int i = 0; i < n; i++) {
			fill(dist[i], dist[i] + n, -1);
		} // 거리 배열 -1로 초기화

		for (int i = 0; i < mask.size(); i++) {
			dist[virus[i].X][virus[i].Y] = 0;
			if (mask[i] == 0) {
				q.push({ virus[i].X,virus[i].Y });
			}
			else {
				board_t[virus[i].X][virus[i].Y] = 2;
			}
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (OOM(nx, ny)) continue;
				if (board_t[nx][ny] == 2 && dist[nx][ny] == 0) { // 비활성 바이러스 처리
					q.push({ nx,ny });
					dist[nx][ny] = dist[cur.X][cur.Y]+1;
				}
				if (board_t[nx][ny] != 0 || dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				tt = max(tt, dist[nx][ny]);
				q.push({ nx,ny });
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0 && dist[i][j] == -1) {
					flag = false;
				}
			}
		}
		if (flag == 1) ans = min(ans, tt);
	} while (next_permutation(mask.begin(), mask.end()));

	if (ans == MX) {
		cout << -1;
	}
	else cout << ans;
	return 0;
	return 0;
}