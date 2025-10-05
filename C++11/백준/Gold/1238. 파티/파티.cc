#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>> adj) {

    vector<int> dist(n + 1, INF);
    // 최소 힙
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] < cur_dist) continue;

        for (auto& edge : adj[cur_node]) {
            int next_node = edge.first;
            int next_dist = cur_dist + edge.second;

            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({ next_dist, next_node });
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> adj;
    vector<vector<pair<int, int>>> rev_adj;

    adj.resize(N + 1);
    rev_adj.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({ v, t });
        rev_adj[v].push_back({ u, t });
    }

    vector<int> dist_to_party = dijkstra(X, N, rev_adj);
    vector<int> dist_to_home = dijkstra(X, N, adj);

    int mx_time = 0;
    for (int i = 1; i <= N; ++i) {
        int total_time = dist_to_party[i] + dist_to_home[i];
        if (total_time > mx_time) {
            mx_time = total_time;
        }
    }

    cout << mx_time;

    return 0;
}
