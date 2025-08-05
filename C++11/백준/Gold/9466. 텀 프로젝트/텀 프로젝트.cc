#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int T,cnt;
vector<int> v;
vector<bool> visited, finished;

void dfs(int st) {
	visited[st] = 1;
	int nx = v[st];

	if (!visited[nx]) dfs(nx); // 아직 방문 안 했으면 계속 dfs
	else if (!finished[nx]) {  // 방문은 했지만 아직 사이클 판정 안 끝났으면 = 사이클
		// nx부터 다시 st까지가 사이클
		// finished가 false인데 방문했었다면 그게 시작점이자 끝임
		// 다시 v배열 확인하면서 사이클에 포함된 애들 수 세기
		for (int cur = nx; cur != st; cur = v[cur]) {
			cnt++;
		}
		cnt++; // 사이클 start 바로 전 애도 세주기
	}
	finished[st] = 1; // st 처리 완료
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int n;
		cin >> n; // 학생의 수
		v.assign(n + 1, 0);
		
		for (int i = 1; i <= n; i++) cin >> v[i];
		
		visited.assign(n + 1, 0);
		finished.assign(n + 1, 0);
		cnt = 0;

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) dfs(i);
		}
		cout << n - cnt << '\n';
	}
	return 0;
}