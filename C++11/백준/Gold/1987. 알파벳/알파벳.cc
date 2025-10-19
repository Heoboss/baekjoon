#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
string board[22];
bool visited[26]; // 알파벳 방문 여부 체크

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int max_moves = 0;

// 현재 x좌표, 현재 y좌표, 현재까지의 경로 길이
void dfs(int x, int y, int count) {
    // 현재 경로 길이로 최댓값 갱신
    max_moves = max(max_moves, count);

    // 4방향 탐색
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
            continue;
        }

        int nx_idx = board[nx][ny] - 'A';
        // 알파벳 방문 여부 체크
        if (!visited[nx_idx]) {
            // DFS 진행
            visited[nx_idx] = true; // 방문 처리
            dfs(nx, ny, count + 1);

            // 백트래킹 -> 방문 처리 해제
            visited[nx_idx] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    // 시작점 처리
    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << max_moves;

    return 0;
}