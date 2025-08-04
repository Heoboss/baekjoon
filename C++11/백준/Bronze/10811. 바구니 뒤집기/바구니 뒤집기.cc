#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

vector<int> arr(101);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	queue<int> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j <= b; j++) {
			q.push(arr[j]);
		}
		for (int j = b; j >= a; j--) {
			arr[j] = q.front();
			q.pop();
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}