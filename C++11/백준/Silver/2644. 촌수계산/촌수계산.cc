#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
using namespace std;

vector<int> adj[101]; // 인접 리스트로 그래프 표현
int dis[101];    // 시작점으로부터의 거리(촌수) 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int person1, person2;
    cin >> person1 >> person2;

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // distance 배열 초기화 (-1은 아직 방문 안 함을 의미)
    for (int i = 1; i <= n; ++i) {
        dis[i] = -1;
    }

    queue<int> q;
    q.push(person1);
    dis[person1] = 0; // 시작점의 촌수는 0

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == person2) {
            break;
        }

        for (int neighbor : adj[current]) {
            // 아직 방문하지 않은 친척이라면
            if (dis[neighbor] == -1) {
                dis[neighbor] = dis[current] + 1;
                q.push(neighbor);
            }
        }
    }

    // 목표 사람의 distance 값을 출력 (방문 못했으면 -1)
    cout << dis[person2];

    return 0;
}