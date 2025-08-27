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
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1};

int n, m, p;
string board[10005];
int s[10]; // 각 플레이어의 확장 칸 수
queue<pair<int, int>> q[10]; // 각 플레이어의 성 위치를 담을 큐
int castle_count[10] = { 0 }; // 각 플레이어의 성 개수

// 각 라운드마다 플레이어는 자기 턴에 성을 확장해야함
// 플레이어1부터 2, ...으로 진행
// 각 턴이 돌아왔을 때 자기의 성을 비어있는 칸으로 확장
// 플레이어 i는 자신의 성이 있는 곳에서 Si만큼 모든 칸에 성을 확장 
// 벽이나 다른 플레이어가 있는 성으로는 확장 불가
// 모든 플레이어가 더 이상 확장을 할 수 없을 때 게임 종료
// p1의 성의개수 p2의 성의개수 ... 출력

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                int player_id = board[i][j] - '0';
                q[player_id].push({ i, j });
            }
        }
    }

    // 게임 라운드 진행
    while (true) {
        bool expanded_in_round = false;

        // 1번 플레이어부터 p번 플레이어까지 턴 진행
        for (int i = 1; i <= p; i++) {
            // S[i]칸 만큼 확장
            for (int step = 0; step < s[i]; step++) {
                int q_size = q[i].size();
                if (q_size == 0) break; // 확장할 성이 없으면 중단

                // 현재 큐에 있는 모든 성에 대해 한 칸씩 확장
                while (q_size--) {
                    auto cur = q[i].front(); q[i].pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] != '.') {
                            continue;
                        }

                        board[nx][ny] = i + '0';
                        q[i].push({ nx, ny });
                        expanded_in_round = true;
                    }
                }
            }
        }
        // 이번 라운드에 아무도 확장을 못했다면 게임 종료
        if (!expanded_in_round) {
            break;
        }
    }

    // 최종 성 개수 카운트
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                castle_count[board[i][j] - '0']++;
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= p; i++) {
        cout << castle_count[i] << " ";
    }
    cout << '\n';

    return 0;
}