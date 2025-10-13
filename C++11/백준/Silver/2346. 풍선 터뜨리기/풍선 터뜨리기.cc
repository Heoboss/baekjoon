#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    deque<pair<int, int>> dq;
    for (int i = 1; i <= N; ++i) {
        int move;
        cin >> move;
        dq.push_back({i, move}); // {풍선 번호, 이동할 칸 수}
    }

    while (!dq.empty()) {
        // 1. 맨 앞의 풍선을 터뜨림
        int current_balloon_num = dq.front().first;
        int move_count = dq.front().second;
        dq.pop_front();

        cout << current_balloon_num << " ";

        if (dq.empty()) {
            break;
        }

        // 2. 이동
        if (move_count > 0) {
            // 양수일 때: 앞에서 빼서 뒤로 (move_count - 1)번 이동
            for (int i = 0; i < move_count - 1; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            // 음수일 때: 뒤에서 빼서 앞으로 |move_count|번 이동
            for (int i = 0; i < abs(move_count); ++i) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << endl;

    return 0;
}