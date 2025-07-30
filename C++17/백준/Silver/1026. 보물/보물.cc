#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int n;
vector<int> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a.resize(n); b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[n - i - 1];
	}
	cout << ans;
	return 0;
}