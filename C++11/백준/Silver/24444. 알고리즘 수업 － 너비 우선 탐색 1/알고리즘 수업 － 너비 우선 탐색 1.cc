#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 전역 변수로 선언하여 스택 메모리 문제를 방지하고 자동 초기화(0) 활용
vector<int> adj[100005]; // 인접 리스트
int visited[100005];     // 방문 순서를 저장할 배열 (0이면 미방문)
int cnt = 1;             // 방문 순서 카운트

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    // 1. 간선 정보 입력 (무방향 그래프이므로 양쪽에 추가)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 2. 오름차순 방문을 위해 인접 리스트 정렬
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // 3. BFS 탐색 시작
    queue<int> q;

    q.push(r);          // 시작 정점 큐에 삽입
    visited[r] = cnt++; // 시작 정점 방문 순서 기록 (1번)

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 현재 정점(cur)과 연결된 모든 정점(nxt) 확인
        for (int nxt : adj[cur]) {
            if (visited[nxt] == 0) { // 아직 방문하지 않았다면
                visited[nxt] = cnt++; // 방문 순서 기록
                q.push(nxt);          // 큐에 삽입
            }
        }
    }

    // 4. 결과 출력
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << "\n";
    }

    return 0;
}