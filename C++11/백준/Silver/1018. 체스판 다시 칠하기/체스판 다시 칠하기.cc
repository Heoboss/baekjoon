#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 주어진 (r, c)에서 시작하는 8x8 영역을 검사하는 함수
int check_board(int r, int c, const vector<string>& board) {
    int repaint_count1 = 0; // 'W'로 시작하는 경우
    int repaint_count2 = 0; // 'B'로 시작하는 경우

    for (int i = r; i < r + 8; ++i) {
        for (int j = c; j < c + 8; ++j) {
            // (i+j)의 홀짝성으로 올바른 색 결정
            if ((i + j) % 2 == 0) { // 짝수 칸
                if (board[i][j] != 'W') repaint_count1++; // 'W'가 아니면 칠해야 함
                if (board[i][j] != 'B') repaint_count2++; // 'B'가 아니면 칠해야 함
            } else { // 홀수 칸
                if (board[i][j] != 'B') repaint_count1++; // 'B'가 아니면 칠해야 함
                if (board[i][j] != 'W') repaint_count2++; // 'W'가 아니면 칠해야 함
            }
        }
    }
    // 두 경우 중 더 적게 칠하는 횟수를 반환
    return min(repaint_count1, repaint_count2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    int min_repaints = 64; // 최댓값으로 초기화 (8*8=64)

    // 8x8 보드를 만들 수 있는 모든 시작점을 순회
    for (int i = 0; i <= N - 8; ++i) {
        for (int j = 0; j <= M - 8; ++j) {
            min_repaints = min(min_repaints, check_board(i, j, board));
        }
    }

    cout << min_repaints << endl;

    return 0;
}