#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    queue<pair<int, int>> q; // {중요도, 원래 인덱스}
    priority_queue<int> pq;      // 중요도만 저장하여 최댓값 추적

    for (int i = 0; i < N; ++i) {
        int priority;
        cin >> priority;
        q.push({priority, i});
        pq.push(priority);
    }

    int print_count = 0;
    while (!q.empty()) {
        // 1. 큐에서 문서 하나를 꺼냄
        int current_priority = q.front().first;
        int current_index = q.front().second;
        q.pop();

        // 2. 현재 문서의 중요도가 가장 높은지 확인
        if (current_priority == pq.top()) {
            // 2-1. 인쇄하는 경우
            print_count++;
            pq.pop(); // 가장 높은 중요도 제거
            
            // 우리가 찾던 문서인지 확인
            if (current_index == M) {
                cout << print_count << "\n";
                return;
            }
        } else {
            // 2-2. 인쇄하지 않고 맨 뒤로 보내는 경우
            q.push({current_priority, current_index});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}