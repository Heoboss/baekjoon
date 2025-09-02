#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> coord;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coord.push_back({ y,x });
	}
	sort(coord.begin(), coord.end());
	for (auto c : coord) {
		cout << c.second << ' ' << c.first << '\n';
	}

	return 0;
}