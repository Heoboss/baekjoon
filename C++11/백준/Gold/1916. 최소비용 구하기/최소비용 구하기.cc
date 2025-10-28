#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n+1);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	int st, end;
	cin >> st >> end;

	vector<int> dist(n + 1, INF);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[st] = 0;
	pq.push({ 0,st });

	while (!pq.empty()) {
		int cur_cost = pq.top().first;
		int cur_city = pq.top().second;
		pq.pop();

		if (dist[cur_city] < cur_cost) continue;

		for (auto& edge : adj[cur_city]) {
			int edge_cost = edge.first;
			int nx_city = edge.second;

			if (cur_cost + edge_cost < dist[nx_city]) {
				dist[nx_city] = cur_cost + edge_cost;
				pq.push({ dist[nx_city], nx_city });
			}
		}
	}
	
	cout << dist[end];

	return 0;
}