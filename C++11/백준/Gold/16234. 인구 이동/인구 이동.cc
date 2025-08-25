#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define X first
#define Y second

int N, L, R;
int board[52][52];
bool vis[52][52];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int days = 0;
    while (true) {
        bool movement_occurred = false;
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (vis[i][j]) continue;

                queue<pair<int, int>> q;
                vector<pair<int, int>> union_coords;

                q.push({ i, j });
                vis[i][j] = true;
                union_coords.push_back({ i, j });

                int sum = board[i][j];
                int count = 1;

                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny]) continue;
                        int diff = abs(board[cur.X][cur.Y] - board[nx][ny]);
                        if (diff >= L && diff <= R) {
                            vis[nx][ny] = true;
                            q.push({ nx, ny });
                            union_coords.push_back({ nx, ny });
                            sum += board[nx][ny];
                            count++;
                        }
                    }
                }

                // 연합 국가가 2개 이상일 때만 인구 이동 발생
                if (count > 1) {
                    movement_occurred = true;
                    int new_population = sum / count;
                    // 해당 연합에 대해서만 인구 갱신
                    for (auto pos : union_coords) {
                        board[pos.X][pos.Y] = new_population;
                    }
                }
            }
        }

        if (!movement_occurred) {
            cout << days;
            break;
        }
        days++;
    }
    return 0;
}