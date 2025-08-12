#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
#define X first
#define Y second 

int dx[] = { 1, 2, 3, 4, 5, 6 };
int board[105];
int dist[105];
int n, m;

void print_dist() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << dist[i*10+j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		board[x - 1] = y - 1; // 사다리를타고 y-1로 이동
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		board[x - 1]= y-1; // 뱀을 타고 y-1로 이동
	}
	queue<int> q;
	q.push(0); dist[0] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur + dx[dir];
			if (nx < 0 || nx >= 100) continue;
			if (board[nx] != 0) { // 사다리거나 뱀이면
				if (dist[board[nx]] == -1) { // 방문하지 않은 칸이면
					dist[board[nx]] = dist[cur] + 1;
					q.push(board[nx]);
				}
				else if (dist[board[nx]] > dist[cur] + 1) { // dist를 갱신할 수 있다면
					dist[board[nx]] = dist[cur] + 1;
					q.push(board[nx]);
					continue;
				}
			}
			else { // 일반 보드라면
				if (dist[nx] == -1) { // 방문하지 않은 칸이면
					dist[nx] = dist[cur] + 1;
					q.push(nx);
				}
				else { //방문한 칸이면
					if (dist[nx] > dist[cur] + 1) { // dist를 갱신할 수 있다면
						dist[nx] = dist[cur] + 1;
						q.push(nx);
						continue;
					}
				}
			}
		}
	}
	// print_dist();
	cout << dist[99];
	return 0;
}