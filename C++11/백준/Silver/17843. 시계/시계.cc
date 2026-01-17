#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[3];

void solve() {
	int h, m, s; cin >> h >> m >> s;
	arr[0] = 3600 * h + 60 * m + s;
	arr[1] = 720 * m + 12 * s;
	arr[2] = 720 * s;
	sort(arr, arr + 3);
	int mx = min(min(arr[1] - arr[0], arr[2] - arr[1]), 43200 + arr[0] - arr[2]);
	cout << (double) mx / 120 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << fixed;
	cout.precision(10);

	int T; cin >> T;
	while (T--) {
		solve();
	}
}