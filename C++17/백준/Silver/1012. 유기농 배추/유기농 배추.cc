#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int T, N, M,K;
int board[502][502];
bool vis[502][502];
int x, y;
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	
	for (int p = 0; p < T; p++) {
		cin >> N >> M >> K;
		for (int o = 0; o < K; o++) {
			cin >> x >> y;
			board[x][y] = 1;
		} // 배추 밭 입력 완료
		int cnt = 0; // 지렁이 갯수 담을 변수
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (vis[i][j] || !board[i][j]) continue;
				cnt++;
				Q.push({ i,j }); vis[i][j] = 1;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (vis[nx][ny] || !board[nx][ny]) continue;
						vis[nx][ny] = 1; Q.push({ nx,ny });
					}
				}
			}
		}
		cout << cnt << '\n';
		for (int x = 0; x < 502; x++) {
			for (int y = 0; y < 502; y++) {
				vis[x][y] = 0;
				board[x][y] = 0;
			}
		}
			
				

			
	}

}