#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
#define X first
#define Y second
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, m;
string board[602];
bool vis[602][602];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'I') {
				q.push({ i,j });
				vis[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] == 1 || board[nx][ny] == 'X') continue;
			if (board[nx][ny] == 'P') {
				cnt++; vis[nx][ny] = 1;
				q.push({ nx,ny });
				continue;
			}
			q.push({ nx,ny }); vis[nx][ny] = 1;
		}
	}
	if (cnt == 0)
		cout << "TT";
	else
		cout << cnt;
	return 0;
}