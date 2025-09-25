#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
using namespace std;

#define X first
#define Y second
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int r, c;
int fx, fy;
string map[52];

int dist1[52][52];
int dist2[52][52];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	queue<pair<int, int>> q1, q2;
	memset(dist1, -1, sizeof(dist1));
	memset(dist2, -1, sizeof(dist2));

	for (int i = 0; i < r; i++) {
		cin >> map[i];
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'S') { // 고슴도치 위치
				q1.push({ i,j });
				dist1[i][j] = 0;
			}
			else if (map[i][j] == '*') { // 물 시작 위치
				q2.push({ i,j });
				dist2[i][j] = 0;
			}
			else if (map[i][j] == 'D') {
				fx = i;
				fy = j;
			}
		}
	}

	while (!q2.empty()) { // 물에 대한 bfs 먼저 처리
		auto cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (dist2[nx][ny] != -1 || map[nx][ny] == 'X' || map[nx][ny] == 'D') continue;
			q2.push({ nx,ny });
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
		}
	}

	while (!q1.empty()) { // 이후 고슴도치의 bfs 처리
		auto cur = q1.front(); q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (dist1[nx][ny] != -1 || map[nx][ny] == 'X') continue;
			if (dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[cur.X][cur.Y] + 1) continue; // 물이 찰 예정인 곳으로는 이동 불가
			q1.push({ nx,ny });
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
		}
	}

	if (dist1[fx][fy] != -1) {
		cout << dist1[fx][fy];
	}
	else {
		cout << "KAKTUS";
	}

	return 0;
}