#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define X first
#define Y second

int R, C;
int board[102][102];
bool visited[102][102];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };


int count_cheese() {
    int count = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (board[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
        }
    }

    int time = 0;
    int last_cheese_count = 0;

    while (true) {
        int current_cheese = count_cheese();
        if (current_cheese == 0) break;

        last_cheese_count = current_cheese;
        time++;

        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;

        q.push({ 0, 0 });
        visited[0][0] = true;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (visited[nx][ny] || board[nx][ny] == 1) continue; // 방문했거나 치즈면 continue

                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }

        // board 순회하면서 녹을 치즈 찾아서 리스트에 저장
        vector<pair<int, int>> melting_cheese;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (board[i][j] == 1) { // 치즈라면
                    bool is_exposed_to_air = false;
                    // 상하좌우에 외부 공기가 있는지 확인
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        // 외부 공기(visited[nx][ny] == true)와 접촉했다면
                        if (visited[nx][ny]) {
                            is_exposed_to_air = true;
                            break;
                        }
                    }
                    if (is_exposed_to_air) {
                        melting_cheese.push_back({ i, j });
                    }
                }
            }
        }

        // 리스트에 있는 치즈를 한꺼번에 녹임
        for (auto pos : melting_cheese) {
            board[pos.X][pos.Y] = 0;
        }
    }

    cout << time << "\n";
    cout << last_cheese_count << "\n";

    return 0;
}