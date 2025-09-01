#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
using namespace std;

int T;
int v, e;
vector<int> adj[20001];
int colors[20001];
const int RED = 1;
const int BLUE = 2;

// BFS를 이용한 이분 그래프 판별 함수
bool isBipartite(int start) {
    queue<int> q;

    colors[start] = RED; // 시작 노드를 RED로 칠함
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            // 연결된 노드가 칠해지지 않았다면
            if (colors[v] == 0) {
                // 현재 노드와 다른 색으로 칠함
                if (colors[u] == RED) {
                    colors[v] = BLUE;
                }
                else {
                    colors[v] = RED;
                }
                q.push(v);
            }
            // 연결된 노드가 이미 같은 색으로 칠해져 있다면 이분 그래프가 아님
            else if (colors[v] == colors[u]) {
                return false;
            }
        }
    }
    // 위에서 안걸렸으면 이분 그래프임
    return true;
}

void solve() {
	cin >> v >> e;

    for (int i = 1; i <= v; ++i) {
        adj[i].clear();
        colors[i] = 0;
    }
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool possible = true;
    // 모든 정점에 대해 확인 (그래프가 여러 컴포넌트일 수 있으므로)
    for (int i = 1; i <= v; ++i) {
        if (colors[i] == 0) { // 아직 방문하지 않은 컴포넌트
            if (!isBipartite(i)) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}