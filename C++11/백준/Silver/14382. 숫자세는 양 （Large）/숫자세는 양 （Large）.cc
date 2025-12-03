#include <iostream>
#include <map>
using namespace std;

#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main() {
	FASTIO;
	ll t, n, ans, v;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> v;
		ans = v;
		map<int, int> m;
		if (v == 0) cout << "Case #" << i + 1 << ": " << "INSOMNIA" << "\n";
		else {
			for (ll j = 1, tmp; ; j++) {
				ans = v * j;
				tmp = ans;

				while (tmp) {
					m[tmp % 10]++;
					tmp /= 10;
				}
				if (m.size() == 10) break;
			}
			cout << "Case #" << i + 1 << ": " << ans << "\n";
		}	
	}
	return 0;
}