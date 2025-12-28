#include <iostream>
using namespace std;
typedef long long ll;

int N, Q;
ll id;
ll ans = 9223372036854775807LL;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int n = 1; n <= N; n++) {
		ll P, K, C; cin >> P >> K >> C;
		ll cnt = (Q - 1) / K;

		ll val = P + cnt * (cnt + 1) / 2 * C;
		if (val < ans) id = n, ans = val;
	}

	cout << id << ' ' << ans;
}